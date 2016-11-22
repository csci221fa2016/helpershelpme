#include <iostream>
#include "sqlite3.h"
using namespace std;

int main(){
	sqlite3 *db;
	retval=sqlite3_open("test.db", &db);
	retval = sqlite3_exec(db, "CREATE TABLE  users (id int INTEGER PRIMARY KEY, name text);");
	retval = sqlite_exec(db, "insert into users (name) values(\"Duncan MaMahon\");"
}
