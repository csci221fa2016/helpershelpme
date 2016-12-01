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
	retval = sqlite3_exec(db, "create table if not exists users (id integer primary key, name text, phone text, eventid integer);", NULL, NULL, &errmsg);
	
string User::getName() {	
	sqlite3_stmt *s;
	string name;
	const char *sql = "select name from users where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		count << "error in sql statement " << sql;
		return;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		count << "Error in binding sql stmnt " << sql;
		return;
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
		count << "error in sql statement " << sql;
		return;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		count << "Error in binding sql stmnt " << sql;
		return;
	} 
	while(sqlite3_step(s)==SQLITE_ROW) {
		phone = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return phone;


}

vector<EventPosition*> User::getEventsWorked() {
	sqlite3_stmt *s;
	string phone;
	const char *sql = "select phone from users where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		count << "error in sql statement " << sql;
		return;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		count << "Error in binding sql stmnt " << sql;
		return;
	} 
	while(sqlite3_step(s)==SQLITE_ROW) {
		phone = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return phone;

	
}	
bool User::setPhoneNumber(string _phoneNumber) {
	sqlite3_stmt *s;
	const char *sql = "update users set phone = ? where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s, 2, userid);
	retval = sqlite3_bind_text(s,1,_phoneNumber);
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
	retval = sqlite3_bind_text(s,1,_pass);
	if(sqlite3_step(s) != SQLITE_DONE) {
		cout <<"error";
		return false;	
	}
	return true;}
bool User::setName(string _name) {
	sqlite3_stmt *s;
	const char *sql = "update users set name = ? where id = ?";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	retval = sqlite3_bind_int(s, 2, userid);
	retval = sqlite3_bind_text(s,1,_name);
	if(sqlite3_step(s) != SQLITE_DONE) {
		cout <<"error";
		return false;	
	}
	return true;
}

Event* User::getOrganizedEvents() {
	sqlite3_stmt *s;
	int event;
	const char *sql = "select eventid from eventpositions where userid = ? and posid = 0";
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if (retval != SQLITE_OK) {
		count << "error in sql statement " << sql;
		return;
	}
	retval = sqlite3_bind_int(s, 1, userid);
	if (retval != SQLITE_OK) {
		count << "Error in binding sql stmnt " << sql;
		return;
	} 
	while(sqlite3_step(s)==SQLITE_ROW) {
		event = sqlite3_column_int(s, 0);
	}
	return new Event(event);
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

