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
		EventPosition(int _eventid, int _userid, int _posid);
		User* getVolunteer();
		Event* getEvent();
		string getDescription();
		time_t getStartTime();
		time_t getEndTime();
		void setDescription(string _description);
		void setVolunteer(int _userId);
		void setPosType(int _posid);
		void setStartTime(time_t _start);
		int getPosId();
		void setEndTime(time_t _end);
};

#endif
