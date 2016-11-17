all: test.cgi

test.cgi: test.o sqlite3.o
	g++ -ldl -lpthread -lcgicc -o test.cgi test.o sqlite3.o

test.o: test.cpp sqlite3.h
	g++ -c test.cpp

# Use gcc to compile this C code
sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

