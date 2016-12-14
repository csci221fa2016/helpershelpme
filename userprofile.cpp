/*
 * Profile page of the user, unique to every user
 * Primary Use:
 *      View personal information
 *      Create an event
 *      View initial list of events created
 *      View initial list of volunteer positions held
 *
 * Author: Juan Toledo, Luisa M, CSC221 fall 2016
 * Date: 11/21/2016
 */

#include <iostream>
#include <vector>
#include <string>

#include "cgicc/Cgicc.h"
#include "cgicc/CgiDefs.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTTPRedirectHeader.h"
#include "cgicc/HTMLClasses.h"

#include "controller.h"
#include "styles3.h"

using namespace std;
using namespace cgicc;

//show all the information relating to the user if they are logged in
//i.e personal information, events they have organized,
//      volunteer positions they have held, etc.
//Redirects to the login page if verification fails
//void printform(const Cgicc& cgi, Controller& c) {
void printform(const Cgicc& cgi, int& id) {

   Controller c;
   vector<string> userinfo = c.showUserInfo(id);
   int stats = c.showStats(id);
   if(userinfo[0] != "-1"){
       cout << "<section>" << endl;
       cout << "<header>" << endl;
       cout << "<h3>My Information</h3>" << endl;
       cout << "</header>" << endl;
       cout << "<p><strong>User Name:</strong>" 
            <<  userinfo[0] << "</br><strong>Phone Number:</strong> "
            << userinfo[1] << "</br><strong>Hours "
            << "Volunteering: </strong>" << stats << "</p>" << endl;
       cout << "<footer>" << endl;
       cout << "<ul class=\"buttons\">" << endl;
       cout << "<form name=\"my-events\" action=\"my_events.cgi\">" << endl;
       cout << "<button class = \"button small\"/>My Events</button>" << endl;
       cout << "</form>" << endl;
       cout << "<form name=\"my-events\" action=\"eventcreation.cgi\">" << endl;
       cout << "<button class = \"button small\"/>Create Event</button>" << endl;
       cout << "</form>" << endl;
       cout << "</ul>" << endl;
       cout << "</footer>" << endl;
       cout << "</section>" << endl;
   }
   else {
   cout << "<section><header>" << endl;
        cout << h4() << "Not logged in" << h4() << "<header>" << endl;
        cout << h5() << a().set("href", "login.cgi")
            << b() << "Click to log in" << b() 
            << a() << h5() << endl;
        cout << "</section>" << endl;
   }

   /*cout <<"<section>" << endl;
   cout <<"<header>" << endl;
   cout <<"<h3>My Information</h3>" << endl;
   cout <<"</header>" << endl;
   cout <<"<p><strong>User Name:</strong> User Name</br><strong>Phone Number:</strong> 888-999-000  </br><strong>Hours Volunteering:</strong> 123 </p>" << endl;
   cout <<"<footer>" << endl;
   cout <<"<ul class=\"buttons\">" << endl;
   cout <<"<form name=\"my-events\" action=\"my_events.cgi\">" << endl;
   cout <<"<button class = \"button small\"/>My Events</button>" << endl;
   cout <<"</form>" << endl;
   cout <<"<form name=\"my-events\" action=\"eventcreation.cgi\">" << endl;
   cout <<"<button class = \"button small\"/>Create Event</button>" << endl;
   cout <<"</form>" << endl;
   cout <<"</ul>" << endl;
   cout <<"</footer>" << endl;
   cout <<"</section>" << endl;*/
}

int main(int /*argc*/, char** /**/) {
    try{
    	Cgicc cgi;

        int uID = 0;
    	const CgiEnvironment& env = cgi.getEnvironment();
    	vector<string> id;
    	const_cookie_iterator iter;
    	if(env.getCookieList().empty()){
    		id.push_back(" NO COOKIES YET");
    		id.push_back(" NO COOKIES YET");
    		id.push_back(" NO COOKIES YET");
    		id.push_back(" NO COOKIES YET");
    	}else{
    		for(iter = env.getCookieList().begin(); iter != env.getCookieList().end(); ++iter) {
    			id.push_back(iter->getName());
    			id.push_back(iter->getValue());
    		}
    	}
    	if(id[3]=="true"){
    		cout << HTTPHTMLHeader() << endl;
            uID = stoi(id[1]);
    	}
    	else{
    		cout <<HTTPRedirectHeader("login.cgi")<<endl;
    	}
    	cout << html().set("lang", "en").set("dir", "ltr") << endl;
    	cout << head() << endl;
    	cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>" << endl;
    	cout <<"<link rel=\"stylesheet\" href=\"css/main.css\" />" << endl;
    	cout << style() << comment() << endl;
    	cout << styles;
    	cout << comment() << style() <<endl;
    	cout << title() << "Profile" << title() << endl;
    	cout << head() << endl;
    	cout << "<body class =\"index\">" << endl;
    	cout <<"<div id=\"page-wrapper\">" << endl;
    	//<================================================HEADER DONT TOUCH=========================================================>
    	cout <<"<header id=\"header\" class=\"alt\">" << endl;
    	cout <<"<h1 id=\"logo\"><a href=\"home.cgi\">Helpers Help Me</a></h1>" << endl;
    	cout <<"<nav id=\"nav\">" << endl;
    	cout <<"<ul>" << endl;
    	cout <<"<li class=\"current\"><a href=\"home.cgi\">Welcome</a></li>" << endl;
    	cout <<"<li class=\"submenu\">" << endl;
    	cout <<"<a href=\"#\">Menu</a>" << endl;
    	cout <<"<ul>" << endl;
    	cout <<"<li class=\"submenu\">" << endl;
    	cout <<"<a href=\"#\">Events</a>" << endl;
    	cout <<"<ul>" << endl;
//  	cout <<"<li><a href=\"#\">See All Events</a></li>" << endl;
    	cout <<"<li><a href=\"event_list.cgi\">Upcoming Events</a></li>" << endl;	
    	cout <<"<li><a href=\"my_events.cgi\">My Events</a></li>" << endl;
    	cout <<"<li><a href=\"eventcreation.cgi\">Create Event</a></li>" << endl;
    	cout <<"</ul>" << endl;
    	cout <<"</li>" << endl;

    	cout <<"<li><a href=\"userprofile.cgi\">Profile</a></li>" << endl;
//  	cout <<"<li><a href=\"#\">News</a></li>" << endl;
//  	cout <<"<li><a href=\"#\">Contact</a></li>" << endl;
//  	cout <<"<li><a href=\"#\">Donate</a></li>" << endl;
    	cout <<"</ul>" << endl;
    	cout <<"</li>" << endl;
    	cout <<"<li><a href=\"log_out.cgi\" class=\"button special\">Log Out</a></li>" << endl;
    	cout <<"</ul>" << endl;
    	cout <<"</nav>" << endl;
    	cout <<"</header>" << endl;
    	cout <<"<article id=\"main\">" << endl;
    	cout <<"<header class=\"special container\">" << endl;
    	cout <<"<span class=\"icon fa-laptop\"></span>" << endl;
    	cout <<"<h2>My<strong> Profile</strong></h2>" << endl;
    	cout <<"</header>" << endl;	
    	cout <<"<section class=\"wrapper style3 container special\">" << endl;
    	cout <<"<div class=\"row\">" << endl;

    	printform(cgi, uID);
    	cout <<"</div>" << endl;
    	cout <<"</section>" << endl;
    	cout <<"</article>" << endl;

    	//<=========================================FOOTER DON'T TOUCH=============================================================>
    	cout <<"<footer id=\"footer\">" << endl;
    	cout <<"<ul class=\"icons\">" << endl;
    	cout <<"<li><a href=\"#\" class=\"icon circle fa-twitter\"><span class=\"label\">Twitter</span></a></li>" << endl;
    	cout <<"<li><a href=\"#\" class=\"icon circle fa-facebook\"><span class=\"label\">Facebook</span></a></li>" << endl;
    	cout <<"<li><a href=\"#\" class=\"icon circle fa-google-plus\"><span class=\"label\">Google+</span></a></li>" << endl;
    	cout <<"<li><a href=\"#\" class=\"icon circle fa-github\"><span class=\"label\">Github</span></a></li>" << endl;
    	cout <<"<li><a href=\"#\" class=\"icon circle fa-dribbble\"><span class=\"label\">Dribbble</span></a></li>" << endl;
    	cout <<"</ul>" << endl;
    	cout <<"<ul class=\"copyright\">" << endl;
    	cout <<"<li>&copy; Helpers Help me</li><li>Design: <a href=\"http://html5up.net\">HTML5 UP</a></li>" << endl;
    	cout <<"</ul>" << endl;
    	cout <<"</footer>" << endl;
    	cout <<"</div>" << endl;

    	cout <<"<script src=\"js/jquery.min.js\"></script>" << endl;
    	cout <<"<script src=\"js/login.js\"></script>" << endl;
    	cout <<"<script src=\"js/jquery.dropotron.min.js\"></script>" << endl;
    	cout <<"<script src=\"js/jquery.scrolly.min.js\"></script>" << endl;
    	cout <<"<script src=\"js/jquery.scrollgress.min.js\"></script>" << endl;
    	cout <<"<script src=\"js/skel.min.js\"></script>" << endl;
    	cout <<"<script src=\"js/util.js\"></script>" << endl;
    	cout <<"<script src=\"js/main.js\"></script>" << endl;
    	cout << "</body>" << endl;
    	cout << html() << endl;
    	return EXIT_SUCCESS;
    } catch(exception& e) {
    	cout << "<pre>" << e.what() << "</pre>";
    	return EXIT_SUCCESS;
    }
}
