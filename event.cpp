#include <string>
#include "event.h"
#include "user.h"
#include "eventposition.h"

Event::Event(int _eventid) : eventid(_eventid) {
	char *errmsg;
	retval = sqlite3_open("/tmp/csci221_dmcmahon.db", &db);
	if(retval != 0)
	{
		cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
		return;
	}
	retval = sqlite3_exec(db, "create table if not exists event (eventid integer primary key, 
name text, description text, start text, end text, organizer integer, location text);", NULL, NULL, &errmsg);
	if(retval != SQLITE_OK)
	{
		cout << "Error in previous command: " << errmsg << endl;
		sqlite3_free(errmsg);
	}

	//make sure that event exists in db
	bool exists = false;
	sqlite3_stmt *s;
	const char *sql = "select * from events where eventid = ?"'
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
		sqlite3_stmt *s;
		//TODO const char *sql = "insert into 
	}
}

string Event::getName() {
    return "Joe Blow";
}

string Event::getStartDate() {
    return "2016-11-22 15:33:00";
}

User* Event::getOrganizer() {
    return new User(1);
}
string Event::getEndDate() {
	return "2016-11-22 16:33:00";
}
string Event::getDescription() {
	return "A great event for friends and family";
}

string Event::getLocation() {
	return "Stetson U";
}

// UPDATE WITH SQLITE!!!!!!!!!

void Event::setName(string _name) {
//	name = _name;
}

void Event::setStartDate(string _date) {
//	date = _date;
}

void Event::setEndDate(string _date) {
//	date = _date;
}

void Event::setOrganizer(int _id) {
//	userId = _id;
}

void Event::setDescription(string _desc) {
//	description = _desc;
}

void Event::setLocation(string _loc) {
	// location = _loc;
}

vector<EventPosition*> Event::getVolunteers() {
    vector<EventPosition*> volunteers;
    EventPosition *ep = new EventPosition(1, 1, 1);
    ep->setDescription("foo bar!"); // just for demo purposes
    volunteers.push_back(ep);
    return volunteers;
}


