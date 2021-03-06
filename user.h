#ifndef USER
#define USER
#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;

class Event;
class EventPosition;

class User {
     private:
	int userid;
	int retval;
	sqlite3 *db;
	char *errmsg;
    
     public:
	User(int _userid);
	string getName();
	string getPhoneNumber();
	vector<EventPosition*> getEventsWorked();
	vector<Event*> getOrganizedEvents();
	bool setName(string _name);
	bool setPhoneNumber(string _phoneNumber);
	void addEvent(Event* _event);
	void addOrganizedEvent(Event* _event);
	bool leaveEvent(Event* _event);
	vector <Event*> listUserEvents();
	int getUserId();
	void setPassword(string _pass);
	bool checkPassword(string _pass);

};
#endif



