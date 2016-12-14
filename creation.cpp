#include <openssl/sha.h>
#include <openssl/rand.h>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "user.h"
#include "event.h"
#include "eventposition.h"
#include <cstring>
#include <string.h>
#include "sqlite3.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iostream>
#include "creation.h"
#include "string.h"
#include <vector>
using namespace std;

Creation::Creation() {
	retval = sqlite3_open("/tmp/csci221_dmcmahon1.db", &db);
	if(retval != 0)
	{
		cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
		return;
	}
}

int Creation::logIn(string _phone, string _pass) {
    cout<<"inside login"<<endl;	
    int userid = -1;
    sqlite3_stmt *s;
    //string phone = _phoneNumber;
    string password;
    string salt;
    const char *sql = "select password, id from users where phone = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return userid;
    }
    cout<<"prepared sql stmt"<<endl;
    retval = sqlite3_bind_text(s, 1, _phone.c_str(), _phone.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return userid;
    }
    cout<<"bound sql stmt"<<endl;
    while (sqlite3_step(s) == SQLITE_ROW) {
        cout<<"inside while for sql stmt"<<endl;
        password = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 0)));
        userid = sqlite3_column_int(s, 1);
    }
    //Hash the password inputed with the salt.
    char *hash;
    char *cstr = new char[password.size() + 1];
    strcpy(cstr, password.c_str());
    char tmp = '$';
    const char* delim = &tmp;
    salt = strtok(cstr, delim);
    hash = strtok(NULL, delim);
    string saltedPass = salt + _pass;  

    string stringmd = SHA256string(saltedPass); 	
    
    string temp(hash);   
 
    if (temp.compare(stringmd) != 0) {
        cout<<"hashs didn't match"<<endl;
        return -1;
    }

    return userid;

}

string Creation::to_hex(unsigned char s)
{
    stringstream ss;
    ss << s;
    return ss.str(); 
}

string Creation::SHA256string(string line)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, line.c_str(), line.length());
    SHA256_Final(hash, &sha256);

    string output = "";    
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += to_hex(hash[i]);
    }
    return output; 
}

int Creation::searchUser(string _phoneNumber) {
    sqlite3_stmt *s;
    int userid = -1;
    string phone = _phoneNumber;
    const char *sql = "select id from users where phone = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return userid;
    }
    retval = sqlite3_bind_text(s, 1, _phoneNumber.c_str(), _phoneNumber.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return userid;
    }
    while (sqlite3_step(s) == SQLITE_ROW) {
        userid = sqlite3_column_int(s, 0);
    }
    sqlite3_reset(s);
    return userid;
}

bool Creation::findUser(int _userid) {
    bool found = false;
    sqlite3_stmt *s;
    const char *sql = "select count(id) from users where id = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    retval = sqlite3_bind_int(s,1,_userid);
    if (retval != SQLITE_OK){
        cout << "Error in SQL statement " << sql;
        return false;
    }
    while (sqlite3_step(s) == SQLITE_ROW) {
        if (sqlite3_column_int(s, 0) == 1) found = true;
        else if (sqlite3_column_int(s, 0) > 1) {
            cout << "Multiple entries with the same primary key (userid) in the users table.";
            return true;
        }
    }
    return found;
}

bool Creation::findEvent(int _eventid) {
    sqlite3_stmt *s;
    bool found = false;
    const char *sql = "SELECT count(eventid) FROM events WHERE eventid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    retval =sqlite3_bind_int(s,1,_eventid);
    if (retval != SQLITE_OK){
        cout << "Error in SQL statement " << sql;
        return false;
    }
    while (sqlite3_step(s) == SQLITE_ROW) {
        if (sqlite3_column_int(s, 0) == 1) found = true;
        else if (sqlite3_column_int(s, 0) > 1) {
            cout << "Multiple entries with the same primary key (eventid) in the events table.";
            found = true;
        }
    }
    return found;
}

int Creation::createUser(string _name, string _phoneNumber, string _password) {

    //Hashing and salting the password.

    SHA256_CTX context;
    unsigned char salttmp[64];
    RAND_bytes(salttmp, 64);
    unsigned char md[SHA256_DIGEST_LENGTH]; //This is the password hash!

    SHA256_Init(&context);
    string salt = string(reinterpret_cast<char*>(salttmp));
    string saltedPass = salt + _password;
    //Hash of password + salt.

    SHA256_Update(&context, saltedPass.c_str(), saltedPass.size());
    SHA256_Final(md, &context);
    string tmpmd = string(reinterpret_cast<char*>(md));
    string hash = salt + "$" + tmpmd;

    int userid = -1;
    sqlite3_stmt *s;
    const char *sql = "insert into users (name, phone, password) values (?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return userid;
    }
    retval = sqlite3_bind_text(s, 1, _name.c_str(), _name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement 1 " << sql;
        return userid;
    }
    retval = sqlite3_bind_text(s, 2, _phoneNumber.c_str(), _phoneNumber.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement 2 " << sql;
        return userid;
    }
    retval = sqlite3_bind_text(s, 3, _password.c_str(), _password.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement 3 " << sql;
        return userid;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
    }
    sqlite3_reset(s);
    //Finished creating new User, now getting userid to return.


    sql = "select id from users where phone = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement 4 " << sql;
        return userid;
    }

    retval = sqlite3_bind_text(s, 1, _phoneNumber.c_str(), _phoneNumber.size(), SQLITE_STATIC);
    while (sqlite3_step(s) == SQLITE_ROW) {
        userid = sqlite3_column_int(s, 0);
        if (userid == -1) {
            cout << "Bad userid.";
        }	
    }
    return userid;
}

int Creation::createEvent(string _name, string _description, time_t _start, time_t _end, string _location) {
    int eventid = -1;
    sqlite3_stmt *s;
    const char *sql = "insert into events (name, description, start, end, location) values (?, ?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in the SQL statement " << sql;
        return eventid;
    }
    retval = sqlite3_bind_text(s, 1, _name.c_str(), _name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return eventid;
    }
    retval = sqlite3_bind_text(s, 2, _description.c_str(), _description.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return eventid;
    }
    retval = sqlite3_bind_int(s, 3, (int)_start);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return eventid;
    }
    retval = sqlite3_bind_int(s, 4, (int)_end);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return eventid;
    }
    retval = sqlite3_bind_text(s, 5, _location.c_str(), _location.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return eventid;
    }


    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
    }
    sqlite3_reset(s);

    //Get eventid to return to controller.
    sql = "SELECT last_insert_rowid() FROM events";
    //sql = "select eventid from events where name = ? AND description = ? AND location = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return eventid;
    }
    //retval = sqlite3_bind_text(s, 1, _name.c_str(), _name.size(), SQLITE_STATIC);
    /*if (retval != SQLITE_OK) {
      cout << "Error in binding SQL statement " << sql;
      return eventid;
      }
      retval = sqlite3_bind_text(s, 2, _description.c_str(), _description.size(), SQLITE_STATIC);
      if (retval != SQLITE_OK) {
      cout << "Error is binding SQL statement " << sql;
      return eventid;
      }
      retval = sqlite3_bind_text(s, 3, _location.c_str(), _location.size(), SQLITE_STATIC);
      if (retval != SQLITE_OK) {
      cout << "Error in binding SQL statement " << sql;
      return eventid;
      }*/
    while (sqlite3_step(s) == SQLITE_ROW) {
        eventid = sqlite3_column_int(s, 0);
        cout<<"eventid is: "<<eventid<<endl;
        return eventid;
        //TODO make some error checkers here!
        if (eventid == -1) {
            cout << "Bad eventid.";
        }	
    }
    sqlite3_reset(s);
    return eventid;
}

void Creation::createVacancy(int eventid, int posid, string name, int openings){
    sqlite3_stmt *s;
    const char *sql = "insert into vacancies (eventid, posid, name, openings) values (?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    retval = sqlite3_bind_int(s, 1, eventid);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
    }
    retval = sqlite3_bind_int(s, 2, posid);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
    }
    retval = sqlite3_bind_text(s, 3, name.c_str(), name.size(), SQLITE_STATIC);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
    }
    retval = sqlite3_bind_int(s, 4, openings);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
    }
    if(sqlite3_step(s) != SQLITE_DONE){
        cout << "Error in executing SQL statemtn" << sql;
    }
    sqlite3_reset(s);
}

int Creation::createEventPosition(int eventid, int posid, int userid) {
    int eposid = -1;
    sqlite3_stmt *s;
    const char *sql = "insert into eventpositions (eventid, posid, userid) values (?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return eposid;
    }
    retval = sqlite3_bind_int(s, 1, posid);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return eposid;
    }
    retval = sqlite3_bind_int(s, 2, eventid);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return eposid;
    }
    retval = sqlite3_bind_int(s,3,userid);
    if( retval != SQLITE_OK) {
        cout << "error in binding sql statement 3" << sql;
        return eposid;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db);
        return eposid;
    }
    sqlite3_reset(s);
    sql = "update vacancies set openings = openings + 1 where eventid = ? and posid = ?)";
    retval=sqlite3_prepare(db, sql, strlen(sql), &s, NULL);;
    retval = sqlite3_bind_int(s, 1, eventid); 
    retval = sqlite3_bind_int(s, 2, posid);
    if(sqlite3_step(s) != SQLITE_DONE) {
        cout << "cannnot exec sql stmt in leave event" <<sql;
    }
    return eposid;
}

vector<int> Creation::getUpcoming(){
    sqlite3_stmt *s;
    time_t timer = time(NULL);
    vector<int> upcoming;

    const char *sql = "SELECT eventid FROM events WHERE start > ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return upcoming;
    }
    retval = sqlite3_bind_int(s, 1, timer);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql;
        return upcoming;
    }
    while(sqlite3_step(s) == SQLITE_ROW) {
        upcoming.push_back(sqlite3_column_int(s,0));
    }
    sqlite3_reset(s);
    return upcoming;
}

vector<int> Creation::getAllEvents() {
    sqlite3_stmt *s;
    vector<int> allEvents;

    const char *sql = "SELECT eventid FROM events";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in SQL statement " << sql;
        return allEvents;
    }
    while (sqlite3_step(s) == SQLITE_ROW) {
        allEvents.push_back(sqlite3_column_int(s, 0));
    }
    sqlite3_reset(s);
    return allEvents;
}
