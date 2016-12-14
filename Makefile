GTEST_DIR = /var/www/html/csci221fa2016/googletest/googletest
INCLUDEMAIN = /var/www/html/csci221fa2016/googletest/build/googlemock/gtest
CXX = g++
CXXFLAGS = -ansi -Wall -g -ggdb3 -isystem $(GTEST_DIR)/include -Wextra -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: main user event eventposition creation controller home.cgi login.cgi log_out.cgi my_events.cgi login_info.cgi event_list.cgi eventcreation_info.cgi sign_up_info.cgi userprofile.cgi eventpage.cgi eventcreation.cgi

.PHONY: test
test: testcontroller user_test creationtest

gtest-all.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest_main.cc

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) gtest_main.a gtest-all.o gtest_main.o

user_test.o: user_test.cpp user.h $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -lsqlite3 -c user_test.cpp

user_test: user_test.o gtest_main.a user.o event.o eventposition.o
	$(CXX) $(CXXFLAGS) -lpthread -lsqlite3 -o user_test user_test.o gtest_main.a user.o event.o eventposition.o

creationtest.o: creationtest.cpp creation.h $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -lsqlite3 -c creationtest.cpp

creationtest: creationtest.o gtest_main.a user.o event.o eventposition.o creation.o
	$(CXX) $(CXXFLAGS) -lpthread -lsqlite3 -lcrypto -o creationtest creationtest.o gtest_main.a user.o event.o eventposition.o creation.o


testcontroller.o: testcontroller.cpp controller.h event.h user.h eventposition.h creation.h $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c testcontroller.cpp

testcontroller: testcontroller.o controller.h controller.o creation.o user.o event.o eventposition.o gtest_main.a
	$(CXX) $(CXXFLAGS) -lsqlite3 -lcrypto -o testcontroller testcontroller.o controller.o event.o eventposition.o creation.o user.o gtest_main.a

main.o: main.cpp controller.h user.h event.h eventposition.h
	$(CXX) -ldl -g -Wall -c main.cpp

user: user.o sqlite3.o event.o eventposition.o main.o
	$(CXX) -ldl -pthread -lsqlite3 -o user user.o sqlite3.o event.o eventposition.o  main.o

user.o: user.h user.cpp sqlite3.h event.h eventposition.h creation.h
	$(CXX) -lsqlite3 -c user.cpp

event: event.o sqlite3.o user.o eventposition.o main.o
	$(CXX) -ldl -pthread -lsqlite3 -o event event.o sqlite3.o main.o user.o eventposition.o

event.o: event.h user.h eventposition.h sqlite3.h event.cpp
	$(CXX) -lsqlite3 -c event.cpp

eventposition: eventposition.o sqlite3.o user.o event.o main.o
	$(CXX) -ldl -pthread -lsqlite3 -o eventposition eventposition.o sqlite3.o main.o user.o event.o

eventposition.o: user.h event.h eventposition.h sqlite3.h eventposition.cpp
	$(CXX) -std=c++11 -c eventposition.cpp

creation: creation.o eventposition.o sqlite3.o user.o event.o main.o
	$(CXX) -ldl -pthread -lsqlite3 -lcrypto -o creation creation.o sqlite3.o main.o user.o event.o eventposition.o

creation.o: creation.h user.h event.h eventposition.h sqlite3.h creation.cpp
	$(CXX) -std=c++11 -c creation.cpp

controller: controller.o event.o user.o eventposition.o main.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -g -Wall -lcrypto -o controller controller.o creation.o event.o user.o eventposition.o main.o

controller.o: controller.h controller.cpp event.h user.h eventposition.h creation.h
	$(CXX) $(CXXFLAGS) -c controller.cpp

home.cgi: home.o controller.o user.o event.o eventposition.o sqlite3.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcrypto -lcgicc -o home.cgi home.o controller.o user.o event.o eventposition.o creation.o sqlite3.o

home.o: home.cpp controller.h styles.h
	$(CXX) -std=c++11 -c home.cpp

login.cgi: login.o controller.o user.o event.o sqlite3.o eventposition.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o login.cgi login.o controller.o user.o event.o eventposition.o creation.o sqlite3.o

login.o: login.cpp controller.h styles.h
	$(CXX) -std=c++11 -c login.cpp

log_out.cgi: log_out.o user.o event.o sqlite3.o eventposition.o creation.o controller.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o log_out.cgi log_out.o controller.o user.o event.o eventposition.o creation.o sqlite3.o

log_out.o: log_out.cpp styles.h controller.h
	$(CXX) -std=c++11 -c log_out.cpp

my_events.cgi: my_events.o user.o event.o sqlite3.o eventposition.o creation.o controller.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o my_events.cgi my_events.o controller.o user.o event.o eventposition.o creation.o sqlite3.o

my_events.o: my_events.cpp styles2.h controller.h
	$(CXX) -std=c++11 -c my_events.cpp

login_info.cgi: login_info.o user.o event.o sqlite3.o eventposition.o creation.o controller.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o login_info.cgi login_info.o controller.o user.o event.o eventposition.o creation.o sqlite3.o

login_info.o: login_info.cpp styles.h controller.h
	$(CXX) -std=c++11 -c login_info.cpp

event_list.cgi: event_list.o user.o event.o sqlite3.o eventposition.o creation.o controller.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o event_list.cgi event_list.o controller.o user.o event.o eventposition.o creation.o sqlite3.o

event_list.o: event_list.cpp styles2.h controller.h
	$(CXX) -std=c++11 -c event_list.cpp

eventcreation_info.cgi: eventcreation_info.o user.o event.o sqlite3.o eventposition.o creation.o controller.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o eventcreation_info.cgi eventcreation_info.o controller.o user.o event.o eventposition.o creation.o sqlite3.o

eventcreation_info.o: eventcreation_info.cpp styles.h controller.h
	$(CXX) -std=c++11 -c eventcreation_info.cpp

sign_up_info.cgi: sign_up_info.o user.o event.o sqlite3.o eventposition.o creation.o controller.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o sign_up_info.cgi sign_up_info.o controller.o user.o event.o eventposition.o creation.o sqlite3.o
	
sign_up_info.o: sign_up_info.cpp styles.h controller.h
	$(CXX) -std=c++11 -c sign_up_info.cpp

userprofile.cgi: userprofile.o controller.o user.o event.o eventposition.o sqlite3.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o userprofile.cgi userprofile.o user.o event.o eventposition.o creation.o sqlite3.o controller.o

userprofile.o: userprofile.cpp styles2.h controller.h
	$(CXX) -std=c++11 -c userprofile.cpp

eventpage.cgi: eventpage.o controller.o user.o event.o eventposition.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcrypto -lcgicc -o eventpage.cgi eventpage.o controller.o creation.o user.o event.o eventposition.o sqlite3.o

eventpage.o: eventpage.cpp styles3.h controller.h
	$(CXX) -std=c++11 -c eventpage.cpp

eventcreation.cgi: eventcreation.o controller.o user.o event.o eventposition.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -lcrypto -o eventcreation.cgi eventcreation.o controller.o creation.o user.o event.o eventposition.o sqlite3.o

eventcreation.o: eventcreation.cpp styles.h controller.h
	$(CXX) -std=c++11 -c eventcreation.cpp

sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c
main: main.cpp user.o event.o eventposition.o
	$(CXX) $(CXXFLAGS) -lsqlite3 -o main main.cpp user.o event.o eventposition.o
.PHONY: clean
clean:
	rm -f *.o *.cgi controller user event eventposition creation main user_test testcontroller
