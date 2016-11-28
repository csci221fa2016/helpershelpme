#include <iostream>
#include "user.h"
#include "gtest/gtest.h"
using namespace std;

TEST(user, getName)
{
	User u = new User(0);
	ASSERT_EQ(true, e->getName() == NULL);
}
TEST(user, getPhoneNumber) {
	User u = new User(0);
	ASSERT_EQ(true, u->getPhoneNumber() == NULL);
}
TEST(user, getEventsWorked) {
	User u = new User(0);
	ASSERT_EQ(true, u->getEventsWorked() != NULL);
}
