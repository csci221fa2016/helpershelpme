#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
#include "event.h"
#include "eventposition.h"
#include "user.h"

using namespace std;

class Controller {

	public:

		Controller();
		int sendUser(vector<string> v, int id);
		int sendEvent(vector<string> v, int eventId, int userId);
		vector<string> showUserInfo(int id);
		vector<vector<string> > showEventInfo(int id);
		void updateProfile(vector<string> v, int id);
		void updateEvent(vector<string> v, int id);
		vector<string> signIn(vector<string> v);
		void addVolunteer(vector<string> v, int eventId, int userId, int posId);
		void showStats(int id);
		vector<vector<string> > showAllUpcoming(string currentDate);
		void showEvent(int id);
		vector<int> showOrganizedEvents(int id);
		vector<int> showEventsWorked(int id);
		void showEventTitle(int id);
		void showEventDate(int id);
		void checkUserAccess();

};

#endif
