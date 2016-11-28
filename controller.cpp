#include "controller.h"
#include "event.h"
#include "eventposition.h"
#include "user.h"

#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <functional>
#include <cstddef>

using namespace std;

Controller::Controller() {}

void Controller::sendUser(vector<string> v, int id) {
  if (id == 0) {
    // make a new user
    User* u = new User(1);

    if (!v[0].empty() && !v[1].empty() && !v[2].empty())
    {
      u->setName(v[0]);
      u->setPhoneNumber(v[1]);
      u->setPassword(v[2]);
    }
    else {
      throw runtime_error("Empty field.");
    }
  }
  else {
    // runtime error
    throw runtime_error("User attempted invalid signup.");
  }
}

void Controller::sendEvent(vector<string> v, int eventId, int userId) {
   if (userId == 0) {
      // make a new event
      Event* e = new Event(1);
      e->setName(v[0]);
      e->setStartDate(v[1]); // Need to convert to DateTime.
      e->setEndDate(v[2]); // Need to convert to DateTime.
      e->setDescription(v[3]);
      e->setLocation(v[4]);
    
      // add EventPosition later.
    
      e->setOrganizer(userId);
   }

  else {
     // runtime error. no one is making an event.
     throw runtime_error("No active user is making the event.");
  }
}

vector<string> Controller::showUserInfo(int id) {
  vector<string> v;
  User* u = new User(id);
  v.push_back(u->getName());
  v.push_back(u->getPhoneNumber());
  return v;
}

string** Controller::showEventInfo(int id) {
  Event* e = new Event(id);

  // convert array of EventPositions to array of strings
  // then add them to a new array a[]

  vector<EventPosition*> arr = e->getVolunteers();
  string** a;
  a = new string*[arr.size()+1];
  for (int i = 0; i < arr.size()+1; ++i) {
	a[i] = new string[6];
  }

  a[0][0] = e->getName();
  a[0][1] = e->getOrganizer()->getName();
  a[0][2] = e->getStartDate();
  a[0][3] = e->getEndDate();
  a[0][4] = e->getDescription();
  a[0][5] = e->getLocation();
  for (int i = 1; i < arr.size(); ++i ) {
    for (int j = 0; j < 4; ++j) {
      // string s = to_string(arr[i]->getVolunteer());
      // a[i][j] = s;
      switch(j){
        case 0: a[i][j] = arr[i]->getVolunteer()->getName();
                break;
        case 1: a[i][j] = arr[i]->getDescription();
                break;
        case 2: a[i][j] = arr[i]->getStartTime();
                break;
        case 3: a[i][j] = arr[i]->getEndTime();
                break;
        default: a[i][j] = "Error in inputting";
                break;
      }
    }
  }

  return a;
}

void Controller::updateProfile(vector<string> v, int id) {
  User* u = new User(id);

  if (!v[0].empty() && !v[1].empty() && !v[2].empty())
  {
    u->setName(v[0]);
    u->setPhoneNumber(v[1]);
    u->setPassword(v[2]);
  }
  else {
    throw runtime_error("Empty update.");
  }
}

void updateEvent(vector<string> v, int id) {

}

bool Controller::signIn(vector<string> *v) {
//  hash<string> pw_hash;
//  const size_t dbPass = pw_hash(v[1]);
  //send to database to verify
  //if(whatanot) return true; else return false;
  return true;
}

void Controller::addVolunteer(vector<string> v, int eventId, int userId) {
  // add Volunteer to event


}

void Controller::showStats(int id) {
  // show the user profile to the view. (hours, etc.)

}

void Controller::showEvent(int id) {
  // show event info to the view

}

void Controller::showEventTitle(int id) {
  // give event title to home page.

}

void Controller::showEventDate(int id) {
  // give event date to home page.

}

void Controller::checkUserAccess() {
  // permissions with buttons

}
