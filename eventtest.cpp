#include <iostream>
#include "user.h"
#include "gtest/gtest.h"

TEST(event, getName)
{
	Event e = new Event(1);
	ASSERT_EQ(true,e->getName=="EventName");	
}
TEST(event, setName) {
	Event e = new event(2);
	e->setName("fart");
	ASSERT_EQ(false,e->getName(==
}
