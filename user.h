#include <string>
#include <vector.h>
using namespace std;

class Event;
class EventPosition;

class User {
     private:
	int userid;
    
     public:
	User(int _userid);
	string getName();
	string getPhoneNumber();
	EventPosition*[] getEventsWorked();
	EventPosition*[] getOrganizedEvents();
	bool setName(string _name);
	bool setPhoneNumber(string _phoneNumber);
	void addEvent(Event* _event);
	void addOrganizedEvent(Event* _event);
	bool leaveEvent(Event* _event);
	Event*[] listUserEvents();
	int getUserId();
	void setPassword(string _pass);
	bool checkPassword(string _pass);
};
