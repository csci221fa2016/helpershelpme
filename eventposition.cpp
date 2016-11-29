#include "user.h"
#include "event.h"
#include "eventposition.h"
#include "sqlite3.h"
#include "string.h"
#include <string>
#include <iostream>
using namespace std;

EventPosition::EventPosition(int _eposid, int _eventid, int _userid) {
	eposid = _eposid;
	eventid = _eventid;
	userId = _userid;
	char *errmsg;
	retval = sqlite3_open("/tmp/csci221_dmcmahon.db", &db);
    if(retval != 0)
    {
        cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
        return;
    }
	retval = sqlite3_exec(db, "create table if not exists eventpositions (eposid integer primary key, eventid integer, userid integer, description text, start text, end text);", NULL, NULL, &errmsg);
    if(retval != SQLITE_OK)
    {
        cout << "Error in previous command: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    // make sure this event exists in db
    bool exists = false;
	sqlite3_stmt *s;
	const char *sql = "select * from eventpositions where eposid = ?";
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
        const char *sql = "insert into eventpositions (eposid, eventid, userid) values (?, ?, ?)";
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
	const char *sql = "select description from eventpositions where eposid = ?";
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

string EventPosition::getStartTime(){
	sqlite3_stmt *s;
	string start;
	const char *sql = "select start from eventpositions where id = " + (char)eposid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		start = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return start;
}

string EventPosition::getEndTime(){
	sqlite3_stmt *s;
	string end;
	const char *sql = "select start from eventpositions where id = " + (char)eposid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		end = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return end;
}

void EventPosition::setVolunteer(int _userId){
	userId = _userId;
}

void EventPosition::setDescription(string _description){
	sqlite3_stmt *s;
	const char *sql = "update eventpositions set description = ? where eposid = ?";
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

void EventPosition::setStartTime(string _start){

}

void EventPosition::setEndTime(string _end){

}

