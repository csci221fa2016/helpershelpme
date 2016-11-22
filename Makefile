GTEST_DIR = ../gtest-1.7.0
CXX = g++
CXXFLAGS = -ansi -Wall -ggdb3 -isystem $(GTEST_DIR)/include -Wextra -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: test.cgi login.cgi home.cgi

testviet-all.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

testll.o: testll.cpp linkedlist.h node.h $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c testll.cpp

testll: testll.o gtest_main.a
	$(CXX) $(CXXFLAGS) -o testll testll.o gtest_main.a.cgi: testview.o
	g++ -ldl -lpthread -lcgicc -o testview.cgi testview.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o

test.cgi: test.o sqlite3.o
	g++ -ldl -lpthread -lcgicc -o test.cgi test.o sqlite3.o

testlogin.cgi: testlogin.o
	g++ -ldl -lpthread -lcgicc -o testlogin.cgi testlogin.o

testlogin.o: testlogin.cpp
	g++ -c testlogin.cpp

login.cgi: login.o
	$(CXX) -ldl -lpthread -lcgicc -o login.cgi login.o

login.o: login.cpp 
	$(CXX) -c login.cpp

home.cgi: home.o
	g++ -ldl -lpthread -lcgicc -o home.cgi home.o

home.o: home.cpp
	g++ -c home.cpp

.PHONY: clean
clean:
	rm -f *.o *.cgi
