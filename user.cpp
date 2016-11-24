#include "user.h"
#include <string>
#include "string.h"
using namespace std;

User::User(int _userid) {
	userid = _userid;
	char *errmsg;
	retval=sqlite3_open("csci221_dmcmahon.db", &db);
	retval = sqlite3_exec(db, "create table if not exists users (id integer primary key, name text, phone text);", NULL, NULL, &errmsg);
	
}

string User::getName() {	
	sqlite3_stmt *s;
	string name;
	const char *sql = "select name from users where id = " + (char)userid;
	retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	while(sqlite3_step(s)==SQLITE_ROW) {
		name = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
	}
	return name;

}

