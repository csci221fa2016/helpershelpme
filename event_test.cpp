#include <iostream>
#include "event.h"
#include "gtest/gtest.h"
using namespace std;

TEST(event, getName)
{
    Event e = new Event(0);

    ASSERT_EQ(true, e->getName() == "Joe Blow");

}

TEST(event, getStartDate)
{
    Event e = new Event(0);

    ASSERT_EQ(true, e->getStartDate() == "2016-11-22 15:33:00");
}

TEST (event, getEndDate())
{
    Event e = new Event(0);

    ASSERT_EQ(true, e->getEndDate() == "2016-11-22 16:33:00");
}

TEST (event, getDescription)
{
    Event e = new Event(0);

    ASSERT_EQ(true, e->getDescription() == "A great event for friends and family");
}

TEST (event, getLocation)
{
    Event e = new Event(0);

    ASSERT_EQ(true, e->getLocation() == "Stetson U");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
