#ifndef EVENT
#define EVENT
#include <string>
#include <ctime>
#include "sqlite3.h"
#include <vector>
using namespace std;

class User;
class EventPosition;

class Event {
     private:
	int eventid;
	int retval;
	sqlite3 *db;
     public:
	Event(int _eventid);
	string getName();
	time_t getStartDate();
	time_t getEndDate();
	User* getOrganizer();
	vector<EventPosition*> getVolunteers();
	string getDescription();
	string getLocation();
	vector<string>* getVacancies();
	void setStartDate(time_t _start);
	void setEndDate(time_t _start);
	void addVolunteer(vector<EventPosition*> _volunteer);
	void setDescription(string _description);
	void setLocation(string _location);
	void removeVolunteer(vector<EventPosition*> _volunteer);
	int getEventId();
	void setName(string _name);
	void setOrganizer(int _userid);
};

#endif
