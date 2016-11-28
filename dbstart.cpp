#include <iostream>
#include "sqlite3.h"
using namespace std;

int main(){
	sqlite3 *db;
	int retval=sqlite3_open("test.db", &db);

	if (retval != 0) {
	    cout << "Cannot open test.db: " << sqlite3_erorcode(db) << endl;
	    exit(1);
	}

	retval = sqlite3_exec(db, "CREATE TABLE  users (id int INTEGER PRIMARY KEY, name text);");
	retval = sqlite_exec(db, "insert into users (name) values(\"Duncan McMahon\");"
}
