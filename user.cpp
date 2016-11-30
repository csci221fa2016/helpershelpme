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
	retval=sqlite3_open("csci221_dmcmahon.db", &db);
	retval = sqlite3_exec(db, "create table if not exists users (id integer primary key, name text, phone text, eventid integer);", NULL, NULL, &errmsg);
	
}

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

bool User::setName(string _name) {
    return 1;
}

string User::getPhoneNumber() {	
	sqlite3_stmt *s;
	string number;
	const char *sql = "select phone from users where id = " + (char)userid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		number = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return number;
}

vector<EventPosition*> User::getEventsWorked() {
	sqlite3_stmt *s;
	vector <EventPosition*> events;
	return events;
}	
bool User::setPhoneNumber(string _phoneNumber) {
	const char *phone = _phoneNumber.c_str();
	const char *sql = "insert into users phone 8889990000 where id = "+ (char)userid;
	retval = sqlite3_exec(db, sql, NULL, NULL, NULL); //Need to fix the null lol
if(retval != SQLITE_OK)
{
	return false;
}
return true;			
}

//make it a const size_t
void User::setPassword(string _pass) {
	retval = sqlite3_exec(db, "insert into users password where id = "+(char)userid, NULL, NULL, NULL); //Fix the null
}

