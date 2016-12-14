#include <iostream>
#include "creation.h"
#include "gtest/gtest.h"

TEST(creation, login) {
	Creation* c = new Creation();
	int l = c->logIn("4074933565","password");
	//cout<<"the userid is: "<<l<<endl;
	ASSERT_EQ(true, l != 0);
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
