#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>

class Controller {

	public:

		Controller();
		sendUser(vector<string> v, int id);
		sendEvent(vector<string> v, int eventId, int userId);
		updateProfile(vector<string> v, int id);
		updateEvent(vector<string> v, int id);
		signIn(vector<string> v);
		addVolunteer(vector<string> v, int eventId, int userId);
		showStats(int id);
		showEvent(int id);
		showEventTitle(int id);
		showEventDate(int id);
		vector<string> showUserInfo(int id);
		vector<string> showEventInfo(int id);
		checkUserAccess();

};

#endif
