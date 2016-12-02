#include <string>
#include <functional>
using namespace std;

class Creation {
     public:
	size_t login(string _phoneNumber);
	int searchUser(string _phoneNumber);
	bool findUser(int userid);
	bool findEvent(int eventid);
};
