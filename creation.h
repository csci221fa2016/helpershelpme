#include <string>
#include "sqlite3.h"
using namespace std;

class Creation {
    private:
	int retval;
	sqlite3 *db; 
    public:
	Creation();
	string logIn(string _phoneNumber);
	int searchUser(string _phoneNumber);
	bool findUser(int userid);
	bool findEvent(int eventid);
	int createUser(string _name, string _phoneNumber, string _password);
	int createEvent(string _name, string _description, time_t _startTime, time_t _endTime, int userid, string _location);
	int createEventPosition(int eventid, int eposid, string _description, int _openings, int userid);
	vector<int> getUpcoming();
};
