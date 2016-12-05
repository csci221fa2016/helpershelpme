#include "user.h"
#include "event.h"
#include "eventposition.h"
#include "sqlite3.h"
#include "string.h"
#include <string>
#include <iostream>
using namespace std;

EventPosition::EventPosition(int _eventid, int _userid, int _posid) {
	posid = _posid;
	eventid = _eventid;
	userId = _userid;
	char *errmsg;
	retval = sqlite3_open("/tmp/csci221_dmcmahon.db", &db);
    if(retval != 0)
    {
        cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
        return;
    }
	retval = sqlite3_exec(db, "create table if not exists eventpositions (eposid integer primary key, eventid integer, userid integer, posid integer, desc text);", NULL, NULL, &errmsg);
    if(retval != SQLITE_OK)
    {
        cout << "Error in previous command: " << errmsg << endl;
        sqlite3_free(errmsg);
    }


    // make sure this event exists in db
    bool exists = false;
	sqlite3_stmt *s;
	const char *sql = "select eposid from eventpositions where eventid = ? and userid = ? and posid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return;
	}
	retval = sqlite3_bind_int(s, 0, eventid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return;
	}
	retval = sqlite3_bind_int(s, 1, userId);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return;
	}
	retval = sqlite3_bind_int(s, 2, posid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return;
	}
	if (sqlite3_step(s) == SQLITE_ROW) {
		eposid = sqlite3_column_int(s, 0);
	}
	sqlite3_reset(s);
	sql = "select * from eventpositions where eposid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_int(s, 1, eposid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
	if(sqlite3_step(s) == SQLITE_ROW) {
        exists = true;
	}
    sqlite3_reset(s);
    if(!exists) {
        sqlite3_stmt *s;
        const char *sql = "insert into eventpositions (eposid, eventid, userid, posid) values (?, ?, ?, ?)";
        retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
        if(retval != SQLITE_OK) {
            cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
            return;
        }
        retval = sqlite3_bind_int(s, 1, eposid);
        if(retval != SQLITE_OK) {
            cout << "Error in binding SQL statement " << sql;
            return;
        }
        retval = sqlite3_bind_int(s, 2, eventid);
        if(retval != SQLITE_OK) {
            cout << "Error in binding SQL statement " << sql;
            return;
        }
        retval = sqlite3_bind_int(s, 3, userId);
        if(retval != SQLITE_OK) {
            cout << "Error in binding SQL statement " << sql;
            return;
        }
		retval = sqlite3_bind_int(s, 4, posid);
		if(retval != SQLITE_OK){
			cout << "Error in binding SQL statement " << sql;
			return;
		}
        if(sqlite3_step(s) != SQLITE_DONE) {
            cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
            return;
        }
        sqlite3_reset(s);
    }
}

User* EventPosition::getVolunteer(){
	return new User(userId);
}

Event* EventPosition::getEvent(){
	return new Event(eventid);
}

string EventPosition::getDescription(){
	sqlite3_stmt *s;
	string desc;
	const char *sql = "select description from vacancies where eposid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return "";
    }
    retval = sqlite3_bind_int(s, 1, eposid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return "";
    }
	if(sqlite3_step(s) == SQLITE_ROW) {
        if(sqlite3_column_text(s, 0) != NULL) {
            desc = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
        } else {
            desc = "NULL";
        }
	} else {
        cout << "Bad event id? " << eposid;
    }
    sqlite3_reset(s);
	return desc;
}

time_t EventPosition::getStartTime(){
	sqlite3_stmt *s;
	time_t start = -1;
	const char *sql = "select start from events where id = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		start = (time_t)sqlite3_column_int(s, 0);
	}
	return start;
}

time_t EventPosition::getEndTime(){
	sqlite3_stmt *s;
	time_t end = -1;
	const char *sql = "select start from events where id = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		end = (time_t)sqlite3_column_int(s, 0);
	}
	return end;
}

void EventPosition::setVolunteer(int _userId){
	userId = _userId;
}

void EventPosition::setDescription(string _description){
	sqlite3_stmt *s;
	const char *sql = "update vacancies set description = ? where eposid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
    }
    retval = sqlite3_bind_int(s, 2, eposid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_text(s, 1, _description.c_str(), _description.size(), SQLITE_STATIC);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
	if(sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
	}
    sqlite3_reset(s);
}
//TODO: IMPLEMENT INDIVIDUAL START AND END TIMES FOR EVENTPOSITIONS
void EventPosition::setStartTime(string _start) {
/*
	sqlite3_stmt *s;
	const char *sql = "update events set start = ? where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
	cout << "Error in SQL statement " << sql;
	return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if(retval != SQLITE_OK) {
	cout << "Error in binding SQL statement " << sql;
	return;
    }
    retval = sqlite3_bind_text(s, 1, _start.c_str(), _start.size(), SQLITE_STATIC);
    if(retval != SQLITE_OK) {
	cout << "Error in binding SQL statement " << sql;
	return;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
	cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
	return;
    }
    sqlite3_reset(s);
*/
}

//TODO: iMPLEMENT INDIVIDUAL START AND END TIMES FOR EVENTPOSITIONS
void EventPosition::setEndTime(string _end){
/*
    sqlite3_stmt *s;
    const char *sql = "update events set end = ? where eventid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
	cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
	return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if (retval != SQLITE_OK) {
	cout << "Error in binding SQL statement " << sql;
	return;
    }
    retval = sqlite3_bind_text(s, 1, _end.c_str(), _end.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
	cout << "Error in binding SQL statement " << sql;
	return;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
	cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
	return;
    }
    sqlite3_reset(s);
*/
}
int EventPosition::getPosId() {
	return posid;
}
