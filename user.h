#include <string>
#include <vector.h>
using namespace std;

class Event;
class VolunteerPosition;

class User {
     private:
	int userid;
    
     public:
	User(int _userid);
	string getName();
	string getPhoneNumber();
	vector<VolunteerPosition*> getEventsWorked();
	vector<Event*> getOrganizedEvents();
	bool setName(string _name);
	bool setPhoneNumber(string _phoneNumber);
	void addEvent(Event _event);
	void addOrganizedEvent(Event _event);
	bool leaveEvent(Event _event);
	vector<Event*> listUserEvents();
	int getUserId();
};
