#include "event.h"
#include "creation.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Creation, createEvent) 
{
	Creation* c = new Creation();
	int eId = c->createEvent("Name", "desc", 22324343434243, 43432532554535345, 11, "loc");
	Event* e = new Event(eId);
	string name = e->getName();
	string desc = e->getDescription();
	ASSERT_EQ(true, name == "Name");
	
} 

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

