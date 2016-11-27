#ifndef EVENTPOSITIONH
#define EVENTPOSITIONH
#include <string>
using namespace std;

class EventPosition
{
	private:
		int eposid;
		int eventid;
		int userId;
	
	public:
		EventPosition(int _eposid, int _eventid, int _userid);
		User* getVolunteer();
		Event* getEvent();
		string getDescription();
		string getStartTime();
		string getEndTime();
		void setVolunteer(int _userId);
		void setDescription(string _description);
		void setStartTime(string _start);
		void setEndTime(string _end);
};

#endif
