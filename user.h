using namespace std;
#include <string>

class User;
	public:
		User(int _userid);
		string getName();
		string getPhoneNumber();
		VolunteerPosition* getEventsWorked();
		Event* getOrganizedEvents();
		bool setName(string _name);
		bool setPhoneNumber(string _phoneNumber);
		void addEvents(Event _event);
		void addOrganizedEvent(Event _event);
		void leaveEvent(Event _event);
		Event* listUserEvents();
		User* getUserid();
	private:
		int userid;

