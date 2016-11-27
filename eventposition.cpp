#ifndef EVENTPOSITION
#define EVENTPOSITION
#include "user.h"
#include "event.h"
#include "eventposition.h"
#include "sqlite3.h"
#include <string>
using namespace std;

EventPosition::EventPosition(int _eposid, int _eventid, int _userid) {
	eposid = _eposid;
	eventid = _eventid;
	userid = _userid;
	char *errmsg;
	retval = squlite3_open("csci221_dmcmahon.db", &db);
	retval = squlite3_exec(db, "create table if not exists eventpositions (eposid integer primary key, eventid integer, userid integer, description text, start text, end text);", NULL, NULL, &errmsg);
}

User* EventPosition::getVolunteer(){
	return new User(userid);
}

Event* EventPostion::getEvent(){
	return new Event(eventid);
}

string EventPosition::getDescription(){
	squlite_stmt *s;
	string desc;
	const char *sql = "select description from eventpositions where id = " + (char)eposid;
	retval = squlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		desc = string(reinterpret_cast<const char*>(squlite3_column_text(s, 0)));
	}
	return desc;
}

string EventPosition::getStartTime(){
	squlite_stmt *s;
	string start;
	const char *sql = "select start from eventpositions where id = " + (char)eposid;
	retval = squlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		start = string(reinterpret_cast<const char*>(squlite3_column_text(s, 0)));
	}
	return start;
}

string EventPosition::getEndTime(){
	squlite_stmt *s;
	string end;
	const char *sql = "select start from eventpositions where id = " + (char)eposid;
	retval = squlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		end = string(reinterpret_cast<const char*>(squlite3_column_text(s, 0)));
	}
	return end;
}

void EventPosition::setVolunteer(int _userId);
	userId = _userId;
}

void EventPosition::setDescription(string _description);
	
}

void EventPosition::setStartTime(string _start){

}

void EventPosition::setEndTime(string _end){

}

#endif
