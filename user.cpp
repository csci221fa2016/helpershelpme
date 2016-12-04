#include "user.h"
#include "event.h"
#include "eventposition.h"
#include <string>
#include <cstring>
#include "sqlite3.h"
#include <vector>
#include <iostream>
using namespace std;

User::User(int _userid) {
	userid = _userid;
	char *errmsg;
	retval=sqlite3_open("/tmp/csci221_dmcmahon.db", &db);
	retval = sqlite3_exec(db, "create table if not exists users (id integer primary key, name text, phone text primary key, eventid integer, password text);", NULL, NULL, &errmsg);
}	
string User::getName() {	
	sqlite3_stmt *s;
	string name;
	const char *sql = "select name from users where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "error in sql statement " << sql;
		return NULL;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding sql stmnt " << sql;
		return NULL;
	} 
	while(sqlite3_step(s)==SQLITE_ROW) {
		name = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return name;

}

string User::getPhoneNumber() {	
	sqlite3_stmt *s;
	string phone;
	const char *sql = "select phone from users where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "error in sql statement " << sql;
		return NULL;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding sql stmnt " << sql;
		return NULL;
	} 
	while(sqlite3_step(s)==SQLITE_ROW) {
		phone = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return phone;


}

vector<EventPosition*> User::getEventsWorked() {
	vector<EventPosition*> events;
	sqlite3_stmt *s;
	int event;
	const char *sql = "select * from eventpositions where userid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "error in sql statement " << sql;
		return events;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding sql stmnt " << sql;
		return events;
	} 
	while(sqlite3_step(s)==SQLITE_ROW) {
		EventPosition* e = new EventPosition(sqlite3_column_int(s, 1),sqlite3_column_int(s,2),sqlite3_column_int(s,3));
		events.push_back(e);
	}
	return events;
	
}	
bool User::setPhoneNumber(string _phoneNumber) {
	sqlite3_stmt *s;
	const char *sql = "update users set phone = ? where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s, 2, userid);
	retval = sqlite3_bind_text(s,1,_phoneNumber.c_str(),_phoneNumber.size(), SQLITE_STATIC);
	if(sqlite3_step(s) != SQLITE_DONE) {
		cout <<"error";
		return false;	
	}
	return true;			
}

//make it a const size_t
void User::setPassword(string _pass) {
	sqlite3_stmt *s;
	const char *sql = "update users set password = ? where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s, 2, userid);
	retval = sqlite3_bind_text(s,1,_pass.c_str(), _pass.size(), SQLITE_STATIC);
	if(sqlite3_step(s) != SQLITE_DONE) {
		cout <<"error";	
	}
}
bool User::setName(string _name) {
	sqlite3_stmt *s;
	const char *sql = "update users set name = ? where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s, 2, userid);
	retval = sqlite3_bind_text(s,1,_name.c_str(), _name.size(), SQLITE_STATIC);
	if(sqlite3_step(s) != SQLITE_DONE) {
		cout <<"error";
		return false;	
	}
	return true;
}

vector<Event*> User::getOrganizedEvents() {
	vector<Event*> events;
	sqlite3_stmt *s;
	const char *sql = "select eventid from eventpositions where userid = ? and posid = 1";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		cout << "error in sql statement " << sql;
		return events;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		cout << "Error in binding sql stmnt " << sql;
		return events;
	} 
	while(sqlite3_step(s)==SQLITE_ROW) {
		Event* e = new Event(sqlite3_column_int(s, 0));
		events.push_back(e);
	}
	return events;
}

bool User::leaveEvent(Event* _event) {
	Event* e = _event;
	sqlite3_stmt *s;
	const char *sql = "delete from eventpositions where userid = ? and eventid = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s, 1, userid);
	retval = sqlite3_bind_int(s,2,e->getEventId());
	if(sqlite3_step(s) != SQLITE_DONE) {
		cout <<"error";
		return false;	
	}
	return true;
}


int User::getUserId() {
	return userid;
}

