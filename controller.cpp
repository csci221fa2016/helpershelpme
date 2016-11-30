#include "controller.h"

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

vector<vector<string> > Controller::showEventInfo(int id) {
		Event* e = new Event(id);
		// for Event info page
		// convert array of EventPositions to array of strings
		// then add them to a new array a[]

		vector<EventPosition*> ep_arr = e->getVolunteers();
		vector<vector<string> > a;
		for (int i = 0; i < ep_arr.size()+1; ++i) {
				a.push_back(vector<string>());
		}

		a[0].push_back(e->getName());
		a[0].push_back(e->getOrganizer()->getName());
		a[0].push_back(e->getStartDate());
		a[0].push_back(e->getEndDate());
		a[0].push_back(e->getDescription());
		a[0].push_back(e->getLocation());
		for (int i = 0; i < ep_arr.size(); ++i ) {
				a[i+1].push_back(ep_arr[i]->getVolunteer()->getName());
				a[i+1].push_back(ep_arr[i]->getDescription());
				a[i+1].push_back(ep_arr[i]->getStartTime());
				a[i+1].push_back(ep_arr[i]->getEndTime());
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
	Event* e = new Event(id);
	
	if(!v[0].empty() && !v[1].empty() && !v[2].empty() ...){

	}
}

bool Controller::signIn(vector<string> v) {
		//  hash<string> pw_hash;
		//  const size_t dbPass = pw_hash(v[1]);
		//send to database to verify
		//if(whatanot) return true; else return false;
	//Hash only given to database to check
	Creation c = new Creation();
	size_t dbpass = c->login(v[0]);
	hash<string> str_hash;
	if(str_hash(v[1]) == dbpass){
		return true;
	}else{
		throw runtime_error("Invalid Login");
		return false;
	}
		throw runtime_error("Sign in Error");
		return false;
}

void Controller::addVolunteer(vector<string> v, int eventId, int userId, int eposId) {
		// add Volunteer to event
		Creation c = new Creation();
		if(c->findUser(userId) && c->findEvent(eventId)){
			User* u = new User(userId);
			Event* e = new Event(eventId);
			EventPosition* ep = new EventPosition(eposId);
			u->addEvent(e);
			ep->setVolunteer(u);
			e->addVolunteer(ep);
			// Does this add a user to an event or adds an event position to a event?
		}else{

		}

}

void Controller::showStats(int id) {
		// show the user profile to the view. (hours, etc.)

}
//Combine all these functions -useraccess. for home page showing upcoming events need vector<vector<string>>

vector<vector<string>> Controller::showAllUpcoming(string currentDate){

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
