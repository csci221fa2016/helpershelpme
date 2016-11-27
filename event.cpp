
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

