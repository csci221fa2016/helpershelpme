#include "user.h"
#include "event.h"
#include "eventposition.h"
#include <cstring>
#include "sqlite3.h"
#include <iostream>
#include <string>
#include <ctime>
#include "creation.h"
#include "string.h"
#include <vector>
using namespace std;

Creation::Creation() {
	retval = sqlite3_open("/tmp/csci221_dmcmahon.db", &db);
	if(retval != 0)
	{
		cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
		return;
	}
}

string Creation::logIn(string _phoneNumber) {
	sqlite3_stmt *s;
	string phone = _phoneNumber;
	string password;
	const char *sql = "select password from users where phone = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return NULL;
	}
	retval = sqlite3_bind_text(s, 1, phone.c_str(), phone.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return NULL;
	}
	while (sqlite3_step(s) == SQLITE_ROW) {
		password = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 4)));
	}	
	sqlite3_reset(s);
	return password;
}

int Creation::searchUser(string _phoneNumber) {
	sqlite3_stmt *s;
	int userid = -1;
	string phone = _phoneNumber;
	const char *sql = "select id from users where phone = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return userid;
	}
	retval = sqlite3_bind_text(s, 1, phone.c_str(), phone.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return userid;
	}
	while (sqlite3_step(s) == SQLITE_ROW) {
		userid = sqlite3_column_int(s, 0);
	}
	sqlite3_reset(s);
	return userid;
}

bool Creation::findUser(int _userid) {
	bool found = false;
	sqlite3_stmt *s;
	const char *sql = "select count(id) from users where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s,1,_userid);
	if (retval != SQLITE_OK){
		cout << "Error in SQL statement " << sql;
		return false;
	}
	while (sqlite3_step(s) == SQLITE_ROW) {
		if (sqlite3_column_int(s, 0) == 1) found = true;
		else if (sqlite3_column_int(s, 0) > 1) {
			cout << "Multiple entries with the same primary key (userid) in the users table.";
			return true;
		}
	}
	return found;
}

bool Creation::findEvent(int _eventid) {
	sqlite3_stmt *s;
	bool found = false;
	const char *sql = "SELECT count(eventid) FROM events WHERE eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval =sqlite3_bind_int(s,1,_eventid);
	if (retval != SQLITE_OK){
		cout << "Error in SQL statement " << sql;
		return false;
	}
	while (sqlite3_step(s) == SQLITE_ROW) {
		if (sqlite3_column_int(s, 0) == 1) found = true;
		else if (sqlite3_column_int(s, 0) > 1) {
			cout << "Multiple entries with the same primary key (eventid) in the events table.";
			found = true;
		}
	}
	return found;
}

int Creation::createUser(string _name, string _phoneNumber, string _password) {
	int userid = -1;
	sqlite3_stmt *s;
	const char *sql = "insert into users (name, phone, password) values (?, ?, ?)";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return userid;
	}
	retval = sqlite3_bind_text(s, 1, _name.c_str(), _name.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement 1 " << sql;
		return userid;
	}
	retval = sqlite3_bind_text(s, 2, _phoneNumber.c_str(), _phoneNumber.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement 2 " << sql;
		return userid;
	}
	retval = sqlite3_bind_text(s, 3, _password.c_str(), _password.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement 3 " << sql;
		return userid;
	}
	if (sqlite3_step(s) != SQLITE_DONE) {
		cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
	}
	sqlite3_reset(s);
	//Finished creating new User, now getting userid to return.
	
	
	sql = "select id from users where phone = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement 4 " << sql;
		return userid;
	}
	
	retval = sqlite3_bind_text(s, 1, _phoneNumber.c_str(), _phoneNumber.size(), SQLITE_STATIC);
	while (sqlite3_step(s) == SQLITE_ROW) {
		userid = sqlite3_column_int(s, 0);
		if (userid == -1) {
			cout << "Bad userid.";
		}	
	}
	return userid;
}

int Creation::createEvent(string _name, string _description, time_t _start, time_t _end, string _location) {
	int eventid = -1;
	sqlite3_stmt *s;
	const char *sql = "insert into events (name, description, start, end, location) values (?, ?, ?, ?, ?)";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in the SQL statement " << sql;
		return eventid;
	}
	retval = sqlite3_bind_text(s, 1, _name.c_str(), _name.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eventid;
	}
	retval = sqlite3_bind_text(s, 2, _description.c_str(), _description.size(), SQLITE_STATIC);
        if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eventid;
	}
	retval = sqlite3_bind_int(s, 3, (int)_start);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eventid;
	}
	retval = sqlite3_bind_int(s, 4, (int)_end);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eventid;
	}
	retval = sqlite3_bind_text(s, 5, _location.c_str(), _location.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eventid;
	}
	

	if (sqlite3_step(s) != SQLITE_DONE) {
		cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
	}
	sqlite3_reset(s);

	//Get eventid to return to controller.

	sql = "select eventid from events where name = ? AND description = ? AND userid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return eventid;
	}
	retval = sqlite3_bind_text(s, 1, _name.c_str(), _name.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eventid;
	}
	retval = sqlite3_bind_text(s, 2, _description.c_str(), _description.size(), SQLITE_STATIC);
	if (retval != SQLITE_OK) {
		cout << "Error is binding SQL statement " << sql;
		return eventid;
	}
	while (sqlite3_step(s) == SQLITE_ROW) {
		eventid = sqlite3_column_int(s, 0);
		return eventid;
		//TODO make some error checkers here!
		if (eventid == -1) {
			cout << "Bad eventid.";
		}	
	}
	return eventid;
}

void Creation::createVacancy(int eventid, int posid, string name, int openings){
	sqlite3_stmt *s;
	const char *sql = "insert into vacancies (eventid, posid, name, openings) values (?, ?, ?, ?)";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s, 1, eventid);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
	}
	retval = sqlite3_bind_int(s, 2, posid);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
	}
	retval = sqlite3_bind_text(s, 3, name.c_str(), name.size(), SQLITE_STATIC);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
	}
	retval = sqlite3_bind_int(s, 4, openings);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
	}
	if(sqlite3_step(s) != SQLITE_DONE){
		cout << "Error in executing SQL statemtn" << sql;
	}
}

int Creation::createEventPosition(int eventid, int posid, int userid) {
	int eposid = -1;
	sqlite3_stmt *s;
	const char *sql = "insert into eventpositions (eventid, posid, userid) values (?, ?, ?)";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return eposid;
	}
	retval = sqlite3_bind_int(s, 1, posid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eposid;
	}
	retval = sqlite3_bind_int(s, 2, eventid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding SQL statement " << sql;
		return eposid;
	}
	retval = sqlite3_bind_int(s,3,userid);
	if( retval != SQLITE_OK) {
		cout << "error in binding sql statement 3" << sql;
		return eposid;
	}
	if (sqlite3_step(s) != SQLITE_DONE) {
		cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
	}
	return eposid;
}

vector<int> Creation::getUpcoming(){
	sqlite3_stmt *s;
	time_t timer = time(NULL);
	vector<int> upcoming;
	
	const char *sql = "SELECT eventid FROM events WHERE start > timer";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if(retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return upcoming;
	}
	while(sqlite3_step(s) == SQLITE_ROW) {
		upcoming.push_back(sqlite3_column_int(s,0));
	}
	sqlite3_reset(s);
	return upcoming;
}

vector<int> Creation::getAllEvents() {
	sqlite3_stmt *s;
	vector<int> allEvents;

	const char *sql = "SELECT eventid FROM events";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "Error in SQL statement " << sql;
		return allEvents;
	}
	while (sqlite3_step(s) == SQLITE_ROW) {
		allEvents.push_back(sqlite3_column_int(s, 0));
	}
	sqlite3_reset(s);
	return allEvents;
}
