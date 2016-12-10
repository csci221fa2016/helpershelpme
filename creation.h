#ifndef CREATION_H
#define CREATION_H

#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;

class Creation {
    private:
	int retval;
	sqlite3 *db; 
    public:
	Creation();
	string logIn(string _phoneNumber);
	int searchUser(string _phoneNumber);
	bool findUser(int _userid);
	bool findEvent(int _eventid);
	int createUser(string _name, string _phoneNumber, string _password);
	int createEventPosition(int eventid, int posid, int _userid);
	int createEvent(string _name, string _description, time_t _startTime, time_t _endTime, string _location);
	vector<int> getUpcoming();
	vector<int> getAllEvents();
	void createVacancy(int eventid, int posid, string name, int openings);
};

#endif
