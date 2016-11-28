#include "eventposition.h"
#include "gtest/gtest.h"
using namespace std;

TEST(eventposition, getVolunteer) {
	EventPosition e = new EventPosition(1,1,1);
	ASSERT_EQ(true, e->getVolunteer()!=NULL);
}

TEST(eventposition, getEvent) {
	EventPosition e = new EventPosition(1,1,1);
	ASSERT_EQ(true, e->getEvent()!=NULL);
} 

TEST(eventposition, getDescription) {
	EventPosition e = new EventPosition(1,1,1);
	ASSERT_EQ(true, e->getDescription()!=NULL);
}

TEST(eventposition, getStartTime) {
	EventPosition e = new EventPosition(1,1,1);
	ASSERT_EQ(true, e->getStartTime()!=NULL);
}

TEST(eventposition, getEndTime) {
	EventPosition e = new EventPosition(1,1,1);
	ASSERT_EQ(true, e->getEndTime()!=NULL);
}


