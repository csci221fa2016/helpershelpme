#ifndef EVENTPOSITIONH
#define EVENTPOSITIONH
#include <string>
using namespace std;

class EventPosition
{
	private:
		int eposid;
		int eventid;
	
	public:
		EventPosition(int eposid, int eventid);
		User* getVolunteer();
		Event* getEvent();
		string getDescription();
		string getStartTime();
		string getEndTime();
		void setVolunteer(User* _user);
		void setDescription(string _description);
		void setStartTime(string _start);
		void setEndTime(string _end);
};

#endif
