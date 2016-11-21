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
	vector<VolunteerPosition*> getVolunteers();
	string getDescription();
	string getLocation();
	void setStartTime(string _date);
	void setEndTime(string _date);
	void addVolunteer(VolunteerPosition* _volunteer);
	void setDescription(string _description);
	void setLocation(string _location);
	void removeVolunteer(VolunteerPosition* _volunteer);
	int getEventId();
};
