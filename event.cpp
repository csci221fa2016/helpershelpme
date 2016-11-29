#include <string>
#include "event.h"
#include "user.h"
#include "eventposition.h"

Event::Event(int _eventid) : eventid(_eventid) {}

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


