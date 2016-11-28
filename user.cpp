#ifndef USER
#define USER
#include "user.h"
#include "event.h"
#include "eventposition.h"
#include <string>
#include "string.h"
#include <vector>
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
	const char *sql = "select name from users where id = " + (char)userid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		name = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return name;

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
	events.push_back(new EventPosition(1,1,1));
	return events;
}
bool User::setPhoneNumber(string _phoneNumber) {
	retval = sqlite3_exec(db, "insert into users "+_phoneNumber+" where id ="+ char(userid);
if(retval != SQLITE_OK)
{
	return false;
}
return true;			
}



#endif
