GTEST_DIR = ../gtest-1.7.0
CXX = g++
CXXFLAGS = -ansi -Wall -ggdb3 -isystem $(GTEST_DIR)/include -Wextra -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: user event eventposition creation controller userprofile.o eventpage.cgi login.cgi home.cgi

testviet-all.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

event_test.o: event_test.cpp event.h $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c event_test.cpp

event_test: event_test.o gtest_main.a
	$(CXX) $(CXXFLAGS) -o event_test event_test.o gtest_main.a

main.o: main.cpp controller.h user.h event.h eventposition.h
	g++ -ldl -g -Wall -c main.cpp

controller: controller.o event.o user.o eventposition.o main.o creation.o
	g++ -ldl -lpthread -lsqlite3 -g -Wall -o controller controller.o event.o user.o eventposition.o main.o

controller.o: controller.h controller.cpp event.h user.h eventposition.h creation.h
	g++ -ldl -g -Wall -c controller.cpp

user: user.o sqlite3.o event.o eventposition.o main.o
	g++ -ldl -pthread -lsqlite3 -o user user.o sqlite3.o event.o eventposition.o  main.o

user.o: user.h user.cpp sqlite3.h event.h eventposition.h
	$(CXX) -c user.cpp

event: event.o sqlite3.o user.o eventposition.o main.o
	g++ -ldl -pthread -lsqlite3 -o event event.o sqlite3.o main.o user.o eventposition.o

event.o: event.h user.h eventposition.h sqlite3.h event.cpp
	$(CXX) -c event.cpp

eventposition: eventposition.o sqlite3.o user.o event.o main.o
	g++ -ldl -pthread -lsqlite3 -o eventposition eventposition.o sqlite3.o main.o user.o event.o

eventposition.o: user.h event.h eventposition.h sqlite3.h eventposition.cpp
	$(CXX) -std=c++11 -c eventposition.cpp

creation: creation.o eventposition.o sqlite3.o user.o event.o main.o
	g++ -ldl -pthread -lsqlite3 -o creation.o sqlite3.o main.o user.o event.o eventposition.o

creation.o: creation.h user.h event.h eventposition.h sqlite3.h creation.cpp
	$(CXX) -std=c++11 -c creation.cpp

home.cgi: home.o controller.o user.o event.o eventposition.o sqlite3.o creation.o
	g++ -ldl -lpthread -lsqlite3 -lcgicc -o home.cgi home.o controller.o user.o event.o eventposition.o sqlite3.o

home.o: home.cpp controller.h styles.h
	$(CXX) -std=c++11 -c home.cpp

login.cgi: login.o controller.o user.o event.o sqlite3.o eventposition.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -o login.cgi login.o controller.o user.o event.o eventposition.o sqlite3.o

login.o: login.cpp controller.h styles.h
	$(CXX) -std=c++11 -c login.cpp

userprofile.cgi: userprofile.o controller.o user.o event.o eventposition.o sqlite3.o creation.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -o userprofile.cgi userprofile.o user.o event.o eventposition.o sqlite3.o

userprofile.o: userprofile.cpp controller.h userprofile.cpp
	$(CXX) -std=c++11 -c userprofile.cpp

eventpage.cgi: eventpage.o controller.o user.o event.o eventposition.o
	$(CXX) -ldl -lpthread -lsqlite3 -lcgicc -o eventpage.cgi eventpage.o controller.o user.o event.o eventposition.o sqlite3.o

eventpage.o: eventpage.cpp styles.h controller.h
	$(CXX) -std=c++11 -c eventpage.cpp

sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

.PHONY: clean
clean:
	rm -f *.o *.cgi controller.o controller event.o event eventposition eventposition.o login.cgi login.o home.cgi home.o
