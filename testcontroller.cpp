#include <iostream>
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
	ASSERT_EQ(false, c->sendUser(v, id) == -1);
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
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}		
