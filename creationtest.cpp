#include <iostream>
#include "creation.h"
#include "gtest/gtest.h"

TEST(creation, login) {
	Creation* c = new Creation();
	c->createUser("hayden2", "8043171637", "please");
    int l = c->logIn("8043171637","please");

    c->createUser("erica", "8889990000", "help");
    c->logIn("8889990000", "help");
	cout<<"the userid is: "<<l<<endl;
	ASSERT_EQ(true, l != 0);
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
