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
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <time.h> 

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
			// tr1::hash<string> str_hash;
			int newUserId =  c->createUser(v[0], v[1], v[2]);
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
		string s = v[0][2];
		char * date = new char[s.size()+1]; //mutable string
		strcpy(date, s.c_str());

		// char date[] = v[0][2];

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


		string s1 = v[0][3];
		char * date1 = new char[s1.size()+1]; //mutable string
		strcpy(date1, s1.c_str());
		//char date1[] = v[0][3];
		tm *etm;

		char* end_pch;
		end_pch = strtok(date1, " ,.-:");
		etm->tm_year = atoi(end_pch); //get the year value
		etm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		etm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		etm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		etm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
		etm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value                  

		// This coverts the tm* ltm to time_t
		mktime (etm);


		//need to set start time end time 0 -name, 1 -description, 2-openings		
		int eventId = c->createEvent(v[0][0], v[0][1], stm, etm, userId, v[0][4]);
		for(int i = 1; i <v.size(); ++i){ 
			c->createEventPosition(eventId, i,  v[i][0], v[i][1], v[i][2]);

		}
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
	string Result;
        ostringstream Convert;
       	Convert << id;
        Result = Convert.str();
	a[0].push_back(Result);

	for (int i = 0; i < ep_arr.size(); ++i ) {
		a[i+1].push_back(ep_arr[i]->getVolunteer()->getName());
		a[i+1].push_back(ep_arr[i]->getDescription());

		time_t start_rawtime = ep_arr[i]->getStartTime();
		time (&start_rawtime);

		time_t end_rawtime = ep_arr[i]->getEndTime();
		time (&end_rawtime);

		a[i+1].push_back(ctime (&start_rawtime));
		a[i+1].push_back(ctime (&end_rawtime));
		string Result;
                ostringstream Convert;
                Convert << (ep_arr[i]->getPosId());
                Result = Convert.str();
		a[i+1].push_back(Result);
	}

	return a;
}

void Controller::updateProfile(vector<string> v, int id) {
	User* u = new User(id);

	if (!v[0].empty() && !v[1].empty() && !v[2].empty())
	{
		u->setName(v[0]);
		u->setPhoneNumber(v[1]);
		// tr1::hash<string> str_hash;  
		u->setPassword(v[2]);
	}
	else {
		throw runtime_error("Empty update.");
	}
}

void Controller::updateEvent(vector<vector<string> > v, int id,int userId){
	Event* e = new Event(id);

	if (userId != (e->getOrganizer()->getUserId())) {
		// runtime error. no one is making an event.
		throw runtime_error("Only organizer can edit this event.");
	}else {

		// This is the start time that the view is passing to us
		string s = v[0][2];
		char * date = new char[s.size()+1]; //mutable string
		strcpy(date, s.c_str());

		//char date[] = v[0][2];
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

		string s1 = v[0][3];
		char * date1 = new char[s1.size()+1]; //mutable string
		strcpy(date1, s1.c_str());
		// char date1[] = v[0][3];
		tm *etm;

		char* end_pch;
		end_pch = strtok(date1, " ,.-:");
		etm->tm_year = atoi(end_pch); //get the year value
		etm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		etm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		etm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		etm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
		etm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value                  

		// This coverts the tm* ltm to time_t
		mktime (etm);


		// third and fourth thing passed in here should be time_t's now
		e->setName(v[0][0]);
		//convert v[1], v[2] to times
		e->setDescription(v[0][3]);
		e->setLocation(v[0][4]);
		for(int i = 1; i<v.size();++i){
			EventPosition* ep = new EventPosition(id, userId, i);
			ep->setName(v[i][0]);
			ep->setDescription(v[i][1]);
			//set openings?
		}
		// Think this is not needed anymore???
		/*for(int i = 0; i < (v.size()-1); ++i){
		//	c->createEventPosition
		}*/
	}
}

vector<string> Controller::signIn(vector<string> v) {
	hash<string> pw_hash;
	const size_t dbPass = pw_hash(v[1]);
	//send to database to verify
	tr1::hash<string> str_hash;
	vector<string> ret;
	Creation* c = new Creation();
	if(str_hash(v[1]) == dbPass){
		int uId = c->searchUser(v[0]);
		ret.push_back("true");
		string Result;
		ostringstream Convert;
		Convert << uId;
		Result = Convert.str();
		ret.push_back(Result);
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

void Controller::addVolunteer(int eventId, int userId, int posId) {
	// add Volunteer to event
	Creation* c = new Creation();
	if(c->findUser(userId) && c->findEvent(eventId)){
		EventPosition* ep = new EventPosition(eventId, userId, posId);
		// Does this add a user to an event or adds an event position to a event?
	}else{
		throw runtime_error("User/Event is invalid");
	}

}

double Controller::showStats(int id) {//convert to datetime for calculations
	// show the user profile to the view. (hours, etc.)
	User* u = new User(id);
	double total_hours;
	for (int i = 0; i < u->getEventsWorked().size(); i++) {
		total_hours += difftime(u->getEventsWorked()[i]->getEndTime(), u->getEventsWorked()[i]->getStartTime())/360;
	}
	return total_hours;
}
//Combine all these functions -useraccess. for home page showing upcoming events need vector<vector<string>>

vector<int > Controller::showAllUpcoming(){                 

	//	time_t now;
	//	struct tm upcoming = etm;
	//	double seconds;
	//
	//	time(&now);  /* get current time; same as: now = time(NULL)  */
	//
	//	upcoming = *localtime(&now);
	//
	//	upcoming.tm_hour = 0;
	//	upcoming.tm_min = 0;
	//	upcoming.tm_sec = 0;
	//	upcoming.tm_mon = 0; 
	//	upcoming.tm_mday = 1;
	//
	//	seconds = difftime(now,mktime(&upcoming));
	//	
	//	// This is now hours.
	//	seconds = seconds/360;
	//
	//	// This would give us the days.
	//	if (seconds > 24) {
	//		seconds = seconds/24;
	//	}

	Creation *c = new Creation();
	vector<int> upcoming = c->getUpcoming();
	return upcoming;
}
vector<string> Controller::showEvent(int id) {
	Event* event = new Event(id);
	vector<string> a;
	time_t start_rawdate;
	a.push_back(event->getName());
	start_rawdate = event->getStartDate();
	time (&start_rawdate);
	a.push_back(ctime (&start_rawdate));
	a.push_back(event->getLocation());
	return a;
}

vector<int> Controller::showOrganizedEvents(int id){
	// get Organized events then getEventId, then return the vector of ints
	User* u = new User(id);
	vector<int> num_organized_events;
	vector<Event*> e = u->getOrganizedEvents();
	for (int i = 0; i < e.size(); i++) {
		num_organized_events.push_back(e[i]->getEventId());
	}
	return num_organized_events;	
}

vector<int> Controller::showEventsWorked(int id){
	User* u = new User(id);
	vector<int> num_events_worked;
	vector<EventPosition*> ep = u->getEventsWorked();
	for (int i = 0; i < ep.size(); i++) {
		num_events_worked.push_back(ep[i]->getEvent()->getEventId());
	}
	return num_events_worked;
}

vector<string> Controller::showEventPositions(int id){
	vector<string> c;
	return c;
}

