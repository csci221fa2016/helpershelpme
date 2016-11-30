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
	return desc;
}

string Event::getStartDate() {
	sqlite3_stmt *s;
	string start;
	const char *sql = "select start from events where id = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		start = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return start;
}

User* Event::getOrganizer() {
	sqlite3_stmt *s;
	int orgid;
	const char *sql = "select organizer from events where id = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		start = sqlite3_column_int(s, 0);
	}
	//TODO should prob check that is valid int somehow
    return new User(orgid);
}

string Event::getEndDate() {
	sqlite3_stmt *s;
	string end;
	const char *sql = "select end from events where id = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		end = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return end;
}

string Event::getDescription() {
	sqlite3_stmt *s;
	string desc;
	const char *sql = "select end from events where id = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		desc = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return desc;
}

string Event::getLocation() {
	sqlite3_stmt *s;
	string loc;
	const char *sql = "select end from events where id = " + (char)eventid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		loc = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return loc;
}

// UPDATE WITH SQLITE!!!!!!!!!

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

void Event::setStartDate(string _date) {
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
    retval = sqlite3_bind_text(s, 1, _date.c_str(), _date.size(), SQLITE_STATIC);
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

void Event::setEndDate(string _date) {
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
    retval = sqlite3_bind_text(s, 1, _date.c_str(), _date.size(), SQLITE_STATIC);
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
    vector<EventPosition*> volunteers;
    EventPosition *ep = new EventPosition(1, 1, 1);
    ep->setDescription("foo bar!"); // just for demo purposes
    volunteers.push_back(ep);
    return volunteers;
}


