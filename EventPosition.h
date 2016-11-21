#ifndef EVENTPOSITIONH
#define EVENTPOSITIONH
#include <string>
using namespace std;

class EventPosition
{
	private:
		int eposid;
	
	public:
		EventPosition(int eposid);
		User * getVolunteer();
		Event * getEvent();
		string getDescription();
		DateTime getStartTime();
		DateTime getEndTime();
		void setVolunteer(int _userId);
		void setDescription(string _description);
		void setStartTime(DateTime _start);
		void setEndTime(DateTime _end);
}

#endif
