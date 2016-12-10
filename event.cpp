#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include "string.h"
#include "event.h"
#include "user.h"
#include "sqlite3.h"
#include "eventposition.h"
using namespace std;

Event::Event(int _eventid) : eventid(_eventid) {
	char *errmsg;
	retval = sqlite3_open("/tmp/csci221_dmcmahon.db", &db);
	if(retval != 0)
	{
		cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
		return;
	}
	retval = sqlite3_exec(db, "create table if not exists events (eventid integer primary key, name text, description text, start integer, end integer, location text);", NULL, NULL, &errmsg);
	if(retval != SQLITE_OK)
	{
		cout << "Error in previous command: " << errmsg << endl;
		sqlite3_free(errmsg);
	}

	retval = sqlite3_exec(db, "create table if not exists vacancies (eventid integer, posid integer, name text, desc text, openings int);", NULL, NULL, &errmsg);
	if(retval != SQLITE_OK)
	{
		cout << "Error in previous command: " << errmsg << endl;
		sqlite3_free(errmsg);
	}

	//make sure that event exists in db
	bool exists = false;
	sqlite3_stmt *s;
	const char *sql = "select * from events where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return;
	}
    retval = sqlite3_bind_int(s, 1, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
	if(sqlite3_step(s) == SQLITE_ROW) {
        exists = true;
	}
    sqlite3_reset(s);
	if(!exists) {
		cout << "No such event. Bad eventid?" << sql;
		return;
	}

}

string Event::getName() {
	sqlite3_stmt *s;
	string name;
	const char *sql = "select name from events where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return "";
	}
	retval = sqlite3_bind_int(s, 1, eventid);
	if(retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return "";
	}
	if(sqlite3_step(s) == SQLITE_ROW) {
		if(sqlite3_column_text(s, 0) != NULL) {
			name = string(reinterpret_cast<const char*>(sqlite3_column_text(s,0)));
		} else {
			name = "NULL";
		}
	} else {
		cout << "Bad event id? " << eventid;
	}
	sqlite3_reset(s);
	return name;
}

time_t Event::getStartDate() {
	sqlite3_stmt *s;
	time_t start;
	const char *sql = "select start from events where eventid = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		start = (time_t)sqlite3_column_int(s, 0);
	}
	return start;
}

User* Event::getOrganizer() {
	sqlite3_stmt *s;
	int orgid;
	const char *sql = "select organizer from events where eventid = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
			orgid = sqlite3_column_int(s, 0);
	}
	//TODO should prob check that is valid int somehow
    return new User(orgid);
}

time_t Event::getEndDate() {
	sqlite3_stmt *s;
	time_t end;
	const char *sql = "select end from events where eventid = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		end = (time_t)sqlite3_column_int(s, 0);
	}
	return end;
}

string Event::getDescription() {
	sqlite3_stmt *s;
	string desc;
	const char *sql = "select desc from events where eventid = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		desc = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return desc;
}

string Event::getLocation() {
	sqlite3_stmt *s;
	string loc;
	const char *sql = "select location from events where eventid = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		loc = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return loc;
}

//Returns information about vacancies as a vector of strings, one for each
//posid in the event. Each string is delimited by semicolons in the format
//name;desc;posid;openings
//The last two will have to be converted back into ints later
vector<string> Event::getVacancies(){
	sqlite3_stmt *s;
	vector<string> vacs;
	const char *sql = "select name, desc, posid, openings from vacancies where eventid = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		string newvac = "";
		newvac = newvac + string(reinterpret_cast<const char*>(sqlite3_column_text(s,0)));
		newvac = newvac + ";" + string(reinterpret_cast<const char*>(sqlite3_column_text(s,1)));
		stringstream stm;
		stm << ";" << sqlite3_column_int(s,2) << ";" << sqlite3_column_int(s,3) << ";";
		newvac = newvac + stm.str();
		vacs.push_back(newvac);
	}
	sqlite3_reset(s);
	return vacs;
}

void Event::setName(string _name) {
	sqlite3_stmt *s;
	const char *sql = "update events set name = ? where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_text(s, 1, _name.c_str(), _name.size(), SQLITE_STATIC);
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

void Event::setStartDate(time_t _start) {
	sqlite3_stmt *s;
	const char *sql = "update events set start = ? where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_int(s, 1, (int)_start);
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

void Event::setEndDate(time_t _end) {
	sqlite3_stmt *s;
	const char *sql = "update events set end = ? where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_int(s, 1, (int)_end);
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

void Event::setOrganizer(int _id) {
	sqlite3_stmt *s;
	const char *sql = "update events set organizer = ? where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_int(s, 1, _id);
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

void Event::setDescription(string _desc) {
	sqlite3_stmt *s;
	const char *sql = "update events set description = ?  where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_text(s, 1, _desc.c_str(), _desc.size(), SQLITE_STATIC);
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

void Event::setLocation(string _loc) {
	sqlite3_stmt *s;
	const char *sql = "update events set location = ? where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql << ": " << sqlite3_errcode(db);
        return;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return;
    }
    retval = sqlite3_bind_text(s, 1, _loc.c_str(), _loc.size(), SQLITE_STATIC);
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

vector<EventPosition*> Event::getVolunteers() {
	sqlite3_stmt *s;
	int _eposid;
	int _userid;
	int _posid;
    vector<EventPosition*> volunteers;
	const char *sql = "select eposid, userid, posid from eventpositions where eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return volunteers; //is this right?
	}
	retval = sqlite3_bind_int(s, 1, eventid);
	if(retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return volunteers;
	}
	while(sqlite3_step(s) == SQLITE_ROW) {
		_eposid = sqlite3_column_int(s, 0);
		_userid = sqlite3_column_int(s, 1);
		_posid = sqlite3_column_int(s, 2);
    	EventPosition *ep = new EventPosition(eventid, _userid, _posid );
    	volunteers.push_back(ep);
	}
	sqlite3_reset(s);
    return volunteers;
}

int Event::getEventId(){
	return eventid;
}
