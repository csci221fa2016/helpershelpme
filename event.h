#ifndef EVENT
#define EVENT
#include <string>
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
	string getStartDate();
	string getEndDate();
	User* getOrganizer();
	vector<EventPosition*> getVolunteers();
	string getDescription();
	string getLocation();
	vector<string> getVacancies();
	void setStartDate(string _date);
	void setEndDate(string _date);
	void addVolunteer(vector<EventPosition*> _volunteer);
	void setDescription(string _description);
	void setLocation(string _location);
	void removeVolunteer(vector<EventPosition*> _volunteer);
	int getEventId();
	void setName(string _name);
	void setOrganizer(int _userid);
};

#endif
