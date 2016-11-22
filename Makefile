GTEST_DIR = ../gtest-1.7.0
CXX = g++
CXXFLAGS = -ansi -Wall -ggdb3 -isystem $(GTEST_DIR)/include -Wextra -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: test.cgi

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

testview.o: testview.cpp
	g++ -c testview.cpp

test.o: test.cpp sqlite3.h
	g++ -c test.cpp

# Use gcc to compile this C code
sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

home.cgi: home.o
	g++ -ldl -lpthread -lcgicc -o home.cgi home.o

home.o: home.cpp
	g++ -c home.cpp

clean:
	rm -f *.o testll gtest.a gtest_main.a
