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


}

    
