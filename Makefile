GTEST_DIR = ../gtest-1.7.0
CXX = g++
CXXFLAGS = -ansi -Wall -ggdb3 -isystem $(GTEST_DIR)/include -Wextra -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: user event eventposition controller test.cgi login.cgi home.cgi

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

controller: controller.o event.o user.o eventposition.o
	g++ -g -Wall -o controller controller.o

controller.o: controller.h controller.cpp event.h user.h eventposition.h
	g++ -g -Wall -c controller.cpp

user: user.o sqlite3.o event.o eventposition.o
	g++ -o user user.o sqlite3.o

user.o: user.h user.cpp sqlite3.h event.h eventposition.h
	g++ -c user.cpp

event: event.o sqlite3.o user.o eventposition.o 
	g++ -o event event.o sqlite3.o

event.o: event.h user.h eventposition.h sqlite3.h event.cpp
	g++ -c event.cpp

eventposition: eventposition.o sqlite3.o user.o event.o
	g++ -o eventposition eventposition.o sqlite.o

eventposition.o: user.h event.h eventposition.h sqlite3.h eventposition.cpp
	g++ -c eventposition.cpp

login.cgi: login.o controller.o
	$(CXX) -ldl -lpthread -lcgicc -o login.cgi login.o

login.o: login.cpp controller.cpp
	$(CXX) -c login.cpp

home.cgi: home.o controller.o
	g++ -ldl -lpthread -lcgicc -o home.cgi home.o

home.o: home.cpp controller.cpp
	g++ -c home.cpp

sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

.PHONY: clean
clean:
	rm -f *.o *.cgi
