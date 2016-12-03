#include "controller.h"
#include "creation.h"
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <tr1/functional>
#include <cstddef>
#include <ctime>
#include <string.h>
#include <cstdlib>

using namespace std;
using tr1::hash;

Controller::Controller() {}

int Controller::sendUser(vector<string> v, int id) {
	if (id == 0) {
		// make a new user
		Creation* c = new Creation();
		// 0 -name, 1 - phone#, 2-pass
		if (!v[0].empty() && !v[1].empty() && !v[2].empty())
		{
			tr1::hash<string> str_hash;
			int newUserId =  c->createUser(v[0], v[1], str_hash(v[2]));
			return newUserId;

		}
		else {
			throw runtime_error("Empty field.");
			return 0;
		}
	}
	else {
		// runtime error
		throw runtime_error("User attempted invalid signup.");
		return 0;
	}
}

int Controller::sendEvent(vector<vector<string> > v, int userId) {
	if (userId == -1) {
		// runtime error. no one is making an event.
		throw runtime_error("No active user is making the event.");
	}else{

		Creation* c = new Creation();

		// This is the start time that the view is passing to us
		char date[] = v[0][2];
		tm *stm;

		char* start_pch;
		start_pch = strtok(date, " ,.-:");
		stm->tm_year = atoi(start_pch); //get the year value
		stm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		stm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		stm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		stm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
		stm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value			

		// This coverts the tm* ltm to time_t
		mktime (stm);

		// This is the end time that the view is passing to us
		char date[] = v[0][3];
		tm *etm;

		char* end_pch;
		end_pch = strtok(date, " ,.-:");
		etm->tm_year = atoi(end_pch); //get the year value
		etm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		etm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		etm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		etm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
		etm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value                  

		// This coverts the tm* ltm to time_t
		mktime (etm);


		// third and fourth thing passed in here should be time_t's now
		c->createEvent(v[0][0], v[0][1], stm, etm, userId, v[0][4]);
		
		// Think this is not needed anymore???
		/*for(int i = 0; i < (v.size()-1); ++i){
			//	c->createEventPosition
		}*/
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

	// Convert StartDate and EndDate from time_t to string to pass back to view
	
	time_t start_rawdate = e->getStartDate();
  	time (&start_rawdate);

	time_t end_rawdate = e->getEndDate();
        time (&end_rawdate);
	

	a[0].push_back(e->getName());
	a[0].push_back(e->getOrganizer()->getName());
	
	// ctime converts the time to a string format = Www Mmm dd hh:mm:ss yyyy
	a[0].push_back(ctime (&start_rawdate));
	a[0].push_back(ctime (&end_rawdate));
	a[0].push_back(e->getDescription());
	a[0].push_back(e->getLocation());
	for (int i = 0; i < ep_arr.size(); ++i ) {
		a[i+1].push_back(ep_arr[i]->getVolunteer()->getName());
		a[i+1].push_back(ep_arr[i]->getDescription());
		
		time_t stat_rawtime = ep_arr[i]->getStartTime();
        	time (&start_rawtime);

        	time_t end_rawtime = ep_arr[i]->getEndTime();
        	time (&end_rawtime);

		a[i+1].push_back(ctime (&start_rawtime));
		a[i+1].push_back(ctime (&end_rawtime));
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

void Controller::updateEvent(vector<string> v, int id){
	Event* e = new Event(id);

	//	if(!v[0].empty() && !v[1].empty() && !v[2].empty() ...){

	//	}
}

vector<string> Controller::signIn(vector<string> v) {
	//  hash<string> pw_hash;
	//  const size_t dbPass = pw_hash(v[1]);
	//send to database to verify
	//if(whatanot) return true; else return false;
	//Hash only given to database to check
	Creation* c = new Creation();
	size_t dbpass = c->login(v[0]);
	tr1::hash<string> str_hash;
	vector<string> ret;
	if(str_hash(v[1]) == dbpass){
		int uId = c->searchUser(v[0]);
		ret.push_back("true");
		ret.push_back(to_string(uId));
		return ret;
	}else{
		ret.push_back("false");
		throw runtime_error("Invalid Login");
		return ret;
	}
	ret.push_back("false");
	throw runtime_error("Sign in Error");
	return ret;
}

void Controller::addVolunteer(vector<string> v, int eventId, int userId, int eposId) {
	// add Volunteer to event
	Creation* c = new Creation();
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

void Controller::showStats(int id) {//convert to datetime for calculations
	// show the user profile to the view. (hours, etc.)


}
//Combine all these functions -useraccess. for home page showing upcoming events need vector<vector<string>>

vector<vector<string> > Controller::showAllUpcoming(string currentDate){

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
