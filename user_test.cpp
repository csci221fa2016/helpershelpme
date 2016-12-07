#include <iostream>
#include "user.h"
#include "gtest/gtest.h"

TEST(user, getName)
{
	User* u = new User(1);
	u->setName("not duncan");
	ASSERT_EQ(true, u->getName() == "not duncan");
}
TEST(user, getPhoneNumber) {
	User* u = new User(1);
	u->setPhoneNumber("8889990000");
	ASSERT_EQ(true, u->getPhoneNumber() == "8889990000");
}
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
