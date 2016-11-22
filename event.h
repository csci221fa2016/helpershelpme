#include <string>
#include <vector>
using namespace std;

class User;
class VolunteerPosition;

class Event {
     private:
	int eventid;
     public:
	Event(int _eventid);
	string getName();
	string getStartDate();
	string getEndDate();
	User* getOrganizer();
	EventPosition*[] getVolunteers();
	string getDescription();
	string getLocation();
	void setStartTime(string _date);
	void setEndTime(string _date);
	void addVolunteer(EventPosition* _volunteer);
	void setDescription(string _description);
	void setLocation(string _location);
	void removeVolunteer(EventPosition* _volunteer);
	int getEventId();
	void setName(string _name);
	void setOrganizer(int _userid)
};
