#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
#include "event.h"
#include "eventposition.h"
#include "user.h"
#include "creation.h"

using namespace std;

class Controller {

	public:

		Controller();
		int sendUser(vector<string> v, int id);
		int sendEvent(vector<vector<string> > v, int userId);
		vector<string> showUserInfo(int id);
		vector<vector<string> > showEventInfo(int id);
		void updateProfile(vector<string> v, int id);
		void updateEvent(vector<vector<string> > v, int id, int userId);
		vector<string> signIn(vector<string> v);
		void addVolunteer(int eventId, int userId, int posId);
		bool removeVolunteer(int eventId, int userId);	
		double showStats(int id);
		vector<int> showAllUpcoming();
		vector<string> showEvent(int id);
		vector<int> showOrganizedEvents(int id);
		vector<int> showEventsWorked(int id);
		string showEventPosition(int userid,int eventid);
		vector<int> showAllEvents();

};

#endif
