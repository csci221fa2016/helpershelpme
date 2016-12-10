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
#include <istream> 

using namespace std;
using tr1::hash;

class Creation;

Controller::Controller() {}

int Controller::sendUser(vector<string> v, int id) {
	if (id == -1) {
		// make a new user
		Creation* c = new Creation();
		// 0 -name, 1 - phone#, 2-pass
		if (!v[0].empty() && !v[1].empty() && !v[2].empty())
		{
			// tr1::hash<string> str_hash;
			int newUserId =  c->createUser(v[0], v[1], v[2]);
			delete c;
			return newUserId;

		}
		else {
			throw runtime_error("Empty field.");
			delete c;
			return 0;
		}
	}
	else {
		// runtime error
		return -1;
	}
}

int Controller::sendEvent(vector<vector<string> > v, int userId) {
	if (userId == -1) {
		// runtime error. no one is making an event.
		throw runtime_error("No active user is making the event.");
		return -1;
	}else{

		Creation* c = new Creation();

		// This is the start time that the view is passing to us
		string s = v.at(0).at(2);
		char * date = new char[s.size()+1]; //mutable string
		strcpy(date, s.c_str());

		// char date[] = v[0][2];

		tm *stm = new tm();

		char* start_pch;
		start_pch = strtok(date, " ,.-:");
		stm->tm_year = atoi(start_pch); //get the year value
		stm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		stm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		stm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		stm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
//		stm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value			
		// This coverts the tm* ltm to time_t


		// This is the end time that the view is passing to us


		string s1 = v.at(0).at(3);
		char * date1 = new char[s1.size()+1]; //mutable string
		strcpy(date1, s1.c_str());
		//char date1[] = v[0][3];
		tm *etm = new tm();

		char* end_pch;
		end_pch = strtok(date1, " ,.-:");
		etm->tm_year = atoi(end_pch); //get the year value
		etm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		etm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		etm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		etm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
//		etm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value                  

		// This coverts the tm* ltm to time_t


		//need to set start time end time 0 -name, 1 -description, 2-openings
		int eventId = c->createEvent(v.at(0).at(0), v.at(0).at(1), mktime (stm), mktime (etm), v.at(0).at(4));
		string Result;
		ostringstream Convert;
		for(unsigned int i = 1; i <v.size(); ++i){ 

			string myStream = v.at(i).at(1);
			istringstream buffer(myStream);
			int value;
			buffer >> value;
			//c->createEventPosition(eventId, i,  v.at(i).at(0), value, userId);
			c->createVacancy(eventId, i, v.at(i).at(0), value);
		}

		return eventId;
	}
}

vector<string> Controller::showUserInfo(int id) {
	vector<string> v;
	Creation* c = new Creation();
	if(c->findUser(id)){
		User* u = new User(id);
		v.push_back(u->getName());
		v.push_back(u->getPhoneNumber());
		delete c;
		delete u;
		return v;
	}else{
		v.push_back("-1");
		delete c;
		return v;
	}
	delete c;
	return v;
}

vector<vector<string> > Controller::showEventInfo(int id) {
	Event* e = new Event(id);
	// for Event info page
	// convert array of EventPositions to array of strings
	// then add them to a new array a[]

	vector<EventPosition*> ep_arr = e->getVolunteers();
	vector<vector<string> > a;
	for (unsigned int i = 0; i < ep_arr.size()+1; ++i) {
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


	vector<string> v = e->getVacancies();	

	for (unsigned int i = 0; i < ep_arr.size(); ++i ) {

		//write test case for parser
		string str = v[i];
		stringstream ss;
		string s;
		char* info = new char[str.size()+1];
		strcpy(info, str.c_str());
		char* start;
		start = strtok(info,";");
		//name;posid;openings
		a[i+1].push_back(s);
		ss << start[1];
		ss >> s;
		a[i+1].push_back(s);
		ss << start[2];
		ss >> s;
		a[i+1].push_back(s);
		
		delete info; delete start;
		//string Result;
		//ostringstream Convert;
		//Convert << (ep_arr[i]->getPosId());
		//Result = Convert.str();
		//a[i+1].push_back(Result);
	}

	delete e;
	ep_arr.clear();
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
	delete u;
}

void Controller::updateEvent(vector<vector<string> > v, int id,int userId){
	Event* e = new Event(id);

	if (userId != (e->getOrganizer()->getUserId())) {
		// runtime error. no one is making an event.
		throw runtime_error("Only organizer can edit this event.");
	}else {

		// This is the start time that the view is passing to us
		string s = v.at(0).at(2);
		char * date = new char[s.size()+1]; //mutable string
		strcpy(date, s.c_str());

	
		tm *stm = new tm();

		char* start_pch;
		start_pch = strtok(date, " ,.-:");
		stm->tm_year = atoi(start_pch); //get the year value
		stm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		stm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		stm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		stm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
		stm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value			
		// This coverts the tm* stm to time_t

		// This is the end time that the view is passing to us

		string s1 = v.at(0).at(3);
		char * date1 = new char[s1.size()+1]; //mutable string
		strcpy(date1, s1.c_str());
		
		tm *etm = new tm();

		char* end_pch;
		end_pch = strtok(date1, " ,.-:");
		etm->tm_year = atoi(end_pch); //get the year value
		etm->tm_mon = atoi(strtok(NULL, " ,.-:"));  //get the month value
		etm->tm_mday = atoi(strtok(NULL, " ,.-:")); //get the day value
		etm->tm_hour = atoi(strtok(NULL, " ,.-:")); //get the hour value
		etm->tm_min = atoi(strtok(NULL, " ,.-:")); //get the min value
		etm->tm_sec = atoi(strtok(NULL, " ,.-:")); //get the sec value                  

		// This coverts the tm* ltm to time_t


		// third and fourth thing passed in here should be time_t's now
		e->setName(v.at(0).at(0));
		//convert v[1], v[2] to times
		e->setDescription(v.at(0).at(1));
		e->setLocation(v.at(0).at(4));
		for(unsigned int i = 1; i<v.size();++i){
			//set vacancies without user input, needs creation here
		}
	
	}
}

vector<string> Controller::signIn(vector<string> v) {
	Creation* c = new Creation();
	string dbPass = c->logIn(v[0]);
	//send to database to verify
	vector<string> ret;
	if(v[1] == dbPass){
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
	delete c;
	return ret;
}

void Controller::addVolunteer(int eventId, int userId, int posId) {
	Creation* c = new Creation();
	if(c->findUser(userId) && c->findEvent(eventId)){
		int eposId = c->createEventPosition(eventId, posId, userId);
		//EventPosition* ep = new EventPosition(eventId, userId, posId);
	}else{
		throw runtime_error("User/Event is invalid");
	}
	delete c;
	//return eposId?
}

double Controller::showStats(int id) {
	User* u = new User(id);
	double total_hours;
	for (unsigned int i = 0; i < u->getEventsWorked().size(); i++) {
		total_hours += difftime(u->getEventsWorked()[i]->getEndTime(), u->getEventsWorked()[i]->getStartTime())/360;
	}
	delete u;
	return total_hours;
}

vector<int > Controller::showAllUpcoming(){
	Creation *c = new Creation();
	vector<int> upcoming = c->getUpcoming();
	delete c;
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
	delete event;
	return a;
}

vector<int> Controller::showAllEvents() {
	Creation* c = new Creation();
	vector<int> all = c->getAllEvents();
	return all;
}

vector<int> Controller::showOrganizedEvents(int id){
	User* u = new User(id);
	vector<int> num_organized_events;
	vector<Event*> e = u->getOrganizedEvents();
	for (unsigned int i = 0; i < e.size(); i++) {
		num_organized_events.push_back(e[i]->getEventId());
	}
	delete u;
	e.clear();
	return num_organized_events;	
}

vector<int> Controller::showEventsWorked(int id){
	User* u = new User(id);
	vector<int> num_events_worked;
	vector<EventPosition*> ep = u->getEventsWorked();
	for (unsigned int i = 0; i < ep.size(); i++) {
		num_events_worked.push_back(ep[i]->getEvent()->getEventId());
	}
	delete u;
	ep.clear();
	return num_events_worked;
}

string Controller::showEventPosition(int userid,int eventid){
	User* u = new User(userid);
	string v;
	vector<EventPosition*> ep = u->getEventsWorked();
	for(unsigned int i = 0; i < ep.size(); ++i){
		Event* e = ep[i]->getEvent();
		if(e->getEventId() == eventid){
			v = ep[i]->getDescription();
			delete e;
			break;	
		}
	} 
	delete u;
	return v;
}

bool Controller::removeVolunteer(int eId, int uId){
	User* u = new User(uId);
	Event* e = new Event(eId);
	bool leave = u->leaveEvent(e);
	return leave;
}

