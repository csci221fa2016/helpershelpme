#include <iostream>
#include "controller.h"
#include "gtest/gtest.h"
using namespace std;


TEST(controller, sendUser)
{
	Controller c = new Controller();
	int id = 0;
	vector<string> v = new vector<string>;
	v[0] = "Joe Blow";
	v[1] = "8888888888";
	v[2] = "JoePass2";
	ASSERT_EQ(true, c->sendUser(v, id) != -1);
}
TEST(controller, sendUser2)
{
    	Controller c = new Controller();
    	int id = 1;
    	vector<string> v = new vector<string>;
    	v[0] = "Joe Blow";
    	v[1] = "8888888888";
    	v[2] = "JoePass2";
    	ASSERT_EQ(true, c->sendUser(v, id) == 0);
}
TEST(controller, showUserInfo)
{
	Controller cont = new Controller();
	Creation c = new Creation();
        int id = c->createUser("Joe Blow", "8888888888", "JoePass2");
	vector<string> v = cont->showUserInfo(id);
	ASSERT_EQ(true, v[0] == "Joe Blow");
	ASSERT_EQ(true, v[1] == "8888888888");
}
TEST(controller, showEventInfo)
{
	Controller cont = new Controller;
		
