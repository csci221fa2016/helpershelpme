#ifndef EVENTPOSITIONH
#define EVENTPOSITIONH
#include <string>
#include <ctime>
#include "sqlite3.h"
using namespace std;

class EventPosition
{
	private:
		int eposid;
		int eventid;
		int userId;
		int posid;
		int retval;
		sqlite3 *db;
			
	public:
		EventPosition(int _eposid, int _eventid, int _userid, int _posid);
		User* getVolunteer();
		Event* getEvent();
		string getDescription();
		time_t getStartTime();
		time_t getEndTime();
		void setDescription(string _description);
		void setVolunteer(int _userId);
		void setPosType(int _posid);
		void setStartTime(string _start);
		void setEndTime(string _end);
};

#endif
