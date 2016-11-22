#include "user.h"
#include "string"
using namespace std;

user::user(int _userid) {
	userid = _userid;
	sqlite3 *db;
	retval=sqlite3_open("csci221_dmcmahon.db", &db);
	retval = sqlite3_exec(db, "create table if not exists users (id integer primary key, name text, phone text);");
	
}

user::getName() {
	string x = "select name from users where id = " +to_string(id);	
	sqlite3_stmt *s;
	const char *sql = "select name from users where id = " +to_string(id);
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	
	string = sqlite3_column_string(s, 0);
	return s;

}

