all: test.cgi


testview.cgi: testview.o
	g++ -ldl -lpthread -lcgicc -o testview.cgi testview.o

test.cgi: test.o sqlite3.o
	g++ -ldl -lpthread -lcgicc -o test.cgi test.o sqlite3.o

testview.o: testview.cpp
	g++ -c testview.cpp

test.o: test.cpp sqlite3.h
	g++ -c test.cpp

# Use gcc to compile this C code
sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

