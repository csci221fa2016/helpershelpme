#include <string>
#include <functional>
using namespace std;

class Creation {
     public:
	Creation();
	size_t login(string _phoneNumber);
	int searchUser(string _phoneNumber);
	bool findUser(int userid);
	bool findEvent(int eventid);
	int createUser(string _name, string _phoneNumber, size_t _password);
	int createEvent(string _name, string _description, string _endTime, int userid, string _location);
	int createEventPosition(int eventid, int eposid, string _name, string _description, int _openings);
};
