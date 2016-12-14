#include "event.h"
#include "eventposition.h"
#include "user.h"
#include "creation.h"
#include "controller.h"
int main() {
    User* u = new User(1);
    Event* e = new Event(0);
    EventPosition* p = new EventPosition(1,1,1);
    Creation* c = new Creation();
    return 0;
}
