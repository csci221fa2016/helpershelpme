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
	Controller* c = new Controller();
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
	event[0].push_back("2016-05-03 10:00");
	event[0].push_back("2016-05-03 12:00");
	//event[0].push_back(uId);
	event[0].push_back("location");
	event[0].push_back("1");

	event[1].push_back("name");
	event[1].push_back("3");


	int eId = c->sendEvent(event, id);

	Event* e = new Event(eId);
	string eName = e->getName();
	string eDesc = e->getDescription();
	vector<string> eVacancies = e->getVacancies();

	ASSERT_EQ(false, eId == -1);

}

TEST(Controller, showUserInfo)
{
	Controller* cont = new Controller();
	Creation* c = new Creation();
	int id = c->createUser("Tierney Irwin", "8887776666", "JoePass2");
	vector<string> v = cont->showUserInfo(id);
	ASSERT_EQ(true, v.at(0) == "Tierney Irwin");
}

TEST(Controller, showEventInfo)
{
	Controller* cont = new Controller();
	Creation* c = new Creation();
	//vector<vector<string> > a;
	//vector<string> event;
	int eventId = c->createEvent("EName","Desc.",2222222222222222222222222222222222222, 2222222222222222222222222222223, "1");
	c->createEventPosition(eventId, 1, "Name", 2, 13);
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
