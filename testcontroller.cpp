#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream> 
#include "controller.h"
#include "creation.h"
#include "gtest/gtest.h"
using namespace std;


TEST(Controller, sendUser)
{
	Controller* c = new Controller();

	int id = -1;
	vector<string> v;
	v.push_back("Tierney Irwin");
	v.push_back("8888888888");
	v.push_back("JoePass2");
	int uId = c->sendUser(v,id);
	User* u = new User(uId);
	string name = u->getName();
	string num = u->getPhoneNumber();
	ASSERT_EQ(false, uId == -1);
}

TEST(Controller, sendUser2)
{
	Controller* c = new Controller();
	Creation* create = new Creation();
	int id = create->createUser("Tierney Irwin", "1234567890", "myPassword"); 
	vector<string> v;
	v.push_back("Joe Blow");
	v.push_back("8889990000");
	v.push_back("Hello");
	ASSERT_EQ(true, c->sendUser(v, id) == -1);
}

TEST(Controller, sendEvent) 
{
	Controller* cont = new Controller();
	int id = 11;
	string uId;
	ostringstream convert;   
	convert << id;      
	uId = convert.str(); 

	vector<vector<string> > event;
	event.push_back(vector<string>());
	event.push_back(vector<string>());

	event[0].push_back("EventName");
	event[0].push_back("Desc");
	event[0].push_back("2018-05-03 10:00");
	event[0].push_back("2018-05-03 12:00");
	//event[0].push_back(uId);
	event[0].push_back("location");
	event[0].push_back("1");

	event[1].push_back("name");
	event[1].push_back("3");


	int eId = cont->sendEvent(event, id);

	Event* e = new Event(eId);
	string eName = e->getName();
	string eDesc = e->getDescription();
	vector<string>* eVacancies = e->getVacancies();

	ASSERT_EQ(false, eId == -1);
}

TEST(Controller, showUserInfo)
{
	Controller* cont = new Controller();
	Creation* c = new Creation();
	int id = c->createUser("Tierney Irwin", "8887776666", "JoePass2");
	vector<string> v = cont->showUserInfo(id);
	ASSERT_EQ(true, v.at(0) == "Tierney Irwin" && v.at(1) == "8887776666");
}

TEST(Controller, updateProfile) 
{
	Controller* cont = new Controller();
	Creation* c = new Creation();
	int id = c->createUser("Tierney Irwin", "8887776666", "JoePass2");
	User* u = new User(id);
	vector<string> v;
	v.push_back("Tierney Irwin2");
	v.push_back("1112225555");
	v.push_back("JoePass2");

	cont->updateProfile(v, id);	

	ASSERT_EQ(true, u->getName() == "Tierney Irwin2" && u->getPhoneNumber() == "1112225555");

}

TEST(Controller, updateEvent)
{
	Controller* cont = new Controller();
	Creation* c = new Creation();
	int eventId = c->createEvent("EName","Desc.",222222222222222, 2222222222222223, "Stetsoon");
//	c->createEventPosition(eventId, 1, "Name", 2, 13);
//	EventPosition* ep = new EventPosition(eventId, 12, 1);
	
	vector<vector<string> > event;
	event.push_back(vector<string>());
	event.push_back(vector<string>());

	Event* e = new Event(eventId);
	
	c->createVacancy(eventId, 1, "Vacancy", 5);
	
	// make event position and add it to event 1.
	
	vector<vector<string> > v;
	v.push_back(vector<string>());
	v.push_back(vector<string>());
	v[0].push_back("Newname");
	v[0].push_back("NewDesc");
	v[0].push_back("2222222222222222");
	v[0].push_back("2222222222222222");
	v[0].push_back("Stetson.");
	v[1].push_back("meep");
	v[1].push_back("1");
	v[1].push_back("3");

	cont->updateEvent(v, eventId, 12);


	ASSERT_EQ(true, e->getName() == "Newname"); 

}


TEST(Controller, signInPass)
{
 	Controller* cont = new Controller();
 	//	Creation* c = new Creation();

 	vector<string> v;
 	v.push_back("8887776666");
 	v.push_back("JoesPass2");

 	vector<string> result;
 	result = cont->signIn(v);
 	ASSERT_EQ(true, result.at(0) == "true");
	ASSERT_EQ(true, result.at(1) != -1); 
}



// Hellooo
TEST(Controller, signInFail)
{
 	Controller* cont = new Controller();
 	//	Creation* c = new Creation();

 	vector<string> v;
 	v.push_back("8887776666");
 	v.push_back("JoesPa2");

 	vector<string> result;
 	result = cont->signIn(v);
 	ASSERT_EQ(true, result.at(0) == "false");
}

// Need to finish this
TEST(Controller, addVolunteer)
{ 
	Controller* c = new Controller();
	int id = 19;
	string uId;
	ostringstream convert;   
	convert << id;      
	uId = convert.str(); 

	vector<vector<string> > event;
	event.push_back(vector<string>());
	event.push_back(vector<string>());

	event[0].push_back("EventName");
	event[0].push_back("Desc");
	event[0].push_back("2016-05-03 10:00");
	event[0].push_back("2016-05-03 12:00");
	//event[0].push_back(uId);
	event[0].push_back("location");
	event[0].push_back("1");

	event[1].push_back("name");
	event[1].push_back("3");


	int eId = 4;

	Event* e = new Event(eId);
	string eName = e->getName();
	string eDesc = e->getDescription();
	vector<string>* eVacancies = e->getVacancies();
    
    c->addVolunteer(eId, id, 1);
    User* u = new User(id);

    ASSERT_EQ(true, u->getEventsWorked().at(0)->getVolunteer()->getUserId() == id);    
    
}

TEST(Controller, showStats)
{
 	Controller* cont = new Controller();
 	Creation* c = new Creation();
	
 	int uId = c->createUser("Tierney I.", "8049997777", "Password");
 	ASSERT_EQ(true, cont->showStats(uId) == 0);
}

TEST(Controller, showStats2)
{
	Controller* cont = new Controller();
	
	vector<vector<string> > event;
	event.push_back(vector<string>());
	event.push_back(vector<string>());

	event[0].push_back("EventName");
	event[0].push_back("Desc");
	event[0].push_back("2016-05-03 10:00");
	event[0].push_back("2016-05-03 12:00");
	event[0].push_back("location");
	event[0].push_back("1");

	event[1].push_back("name");
	event[1].push_back("3");

	int eId = cont->sendEvent(event, 11);
	
	cont->addVolunteer(eId, 11, 1);
	
	ASSERT_EQ(true, cont->showStats(11) == 2);
}

TEST(Controller, showAllUpcoming)
{
	Controller* cont = new Controller();
	vector<int> v = cont->showAllUpcoming();
	ASSERT_EQ(true, v.at(0) == 25);	
}

TEST(Controller, showEvent)
{
	Controller* cont = new Controller();
	int id = 11;

	vector<vector<string> > event;
	event.push_back(vector<string>());
	event.push_back(vector<string>());

	event[0].push_back("EventName");
	event[0].push_back("Desc");
	event[0].push_back("2018-05-03 10:00");
	event[0].push_back("2018-05-03 12:00");
	event[0].push_back("location");
	event[0].push_back("1");

	event[1].push_back("name");
	event[1].push_back("3");


	int eId = cont->sendEvent(event, id);

	Event* e = new Event(eId);
	string eName = e->getName();
	string eDesc = e->getDescription();
	vector<string>* eVacancies = e->getVacancies();


	vector<string> v = cont->showEvent(eId);
	ASSERT_EQ(true, v.at(0) == "EventName" && v.at(2) == "location");
}

TEST(Controller, showAllEvents)
{
	Controller* cont = new Controller();
	vector<int> v = cont->showAllEvents();
	
	for (int i = 0; i < v.size(); i++) {
		ASSERT_EQ(true, v[i] != -1) << "Broke at: " << i;
	}
}

TEST(Controller, showEventInfo)
{
	Controller* cont = new Controller();
	Creation* c = new Creation();
	//vector<vector<string> > a;
	//vector<string> event;
	int eventId = c->createEvent("EName","Desc.",2222222222222222, 222222222222222223, "1");
	//c->createEventPosition(eventId, 1, 13);
	EventPosition* ep = new EventPosition(eventId, 12, 1);
	//vector<string> eposinfo;
	//eposinfo.push_back("Name");
	//string posId;
	//ostringstream ss;
	//ss << 2;
	//posId = ss.str(); 
	//eposinfo.push_back(posId);
	//eposinfo.push_back("1");
	//a.push_back(event);
	//a.push_back(eposinfo);
	//int eId = cont->sendEvent(a, 13);
	Event* event = new Event(eventId);
	string name = ep->getDescription();
	vector<vector<string> > check = cont->showEventInfo(eventId);
	ASSERT_EQ(true, check.at(1).at(0) == ep->getDescription());	
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}		
