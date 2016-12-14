#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <cgicc/HTTPRedirectHeader.h>

#include "styles2.h"
#include "controller.h"

using namespace std;
using namespace cgicc;
void print_event(vector<string> info, int e_id);
int main(int argc, char **argv) {
	try{
		Cgicc cgi;
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
            cout<<HTTPHTMLHeader()<<endl;
		}
		else{
			cout<<HTTPRedirectHeader("login.cgi")<<endl;
		}
		cout << html().set("lang", "en").set("dir", "ltr") << endl;
		cout << html() <<endl;
		cout << head() << endl;
		cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>" << endl;
		cout <<"<link rel=\"stylesheet\" href=\"css/main.css\" />"<<endl;
		cout << style() << comment() << endl;
		cout << styles;
		cout << comment() << style() <<endl;
		cout << title() <<"Events" << title() << endl;
		cout << head() << endl;
		cout << "<body class =\"index\">" << endl;
		cout<<"<div id=\"page-wrapper\">"<<endl;
		//<================================================HEADER DONT TOUCH=========================================================>
		cout<<"<header id=\"header\" class=\"alt\">"<<endl;
		cout<<"<h1 id=\"logo\"><a href=\"home.cgi\">Helpers Help Me</a></h1>"<<endl;
		cout<<"<nav id=\"nav\">"<<endl;
		cout<<"<ul>"<<endl;
		cout<<"<li class=\"current\"><a href=\"home.cgi\">Welcome</a></li>"<<endl;
		cout<<"<li class=\"submenu\">"<<endl;
		cout<<"<a href=\"#\">Menu</a>"<<endl;
		cout<<"<ul>"<<endl;
		cout<<"<li class=\"submenu\">"<<endl;
		cout<<"<a href=\"#\">Events</a>"<<endl;
		cout<<"<ul>"<<endl;
//		cout<<"<li><a href=\"#\">See All Events</a></li>"<<endl;
		cout<<"<li><a href=\"event_list.cgi\">Upcoming Events</a></li>"<<endl;
		cout<<"<li><a href=\"eventcreation.cgi\">Create Event</a></li>"<<endl;
		cout<<"<li><a href=\"my_events.cgi\">My Events</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</li>"<<endl;
		cout<<"<li><a href=\"userprofile.cgi\">Profile</a></li>"<<endl;
//		cout<<"<li><a href=\"#\">News</a></li>"<<endl;
//		cout<<"<li><a href=\"#\">Contact</a></li>"<<endl;
//		cout<<"<li><a href=\"#\">Donate</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</li>"<<endl;
		cout<<"<li><a href=\"log_out.cgi\" class=\"button special\">Log Out</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</nav>"<<endl;
		cout<<"</header>"<<endl;
		
		//<=======================WORK HERE=========================================>	
		
			cout<<"<article id=\"main\">"<<endl;
			cout<<"<header class=\"special container\">"<<endl;
			cout<<"<span class=\"icon fa-laptop\"></span>"<<endl;
			cout<<"<h2>All<strong> Events</strong></h2>"<<endl;
			cout<<"</header>"<<endl;	
			cout<<"<section class=\"wrapper style3 container special\">"<<endl;
			cout<<"<div class=\"row\">"<<endl;

   			Controller control;
			vector<int> eventNum = control.showAllUpcoming();
			for(unsigned i = 0; i < eventNum.size(); i++){
			   print_event(control.showEvent(eventNum.at(i)), eventNum.at(i));
			}

/*			vector<string> info;
			info.push_back("Computer work");
			info.push_back("12/12/32 12:00 pm");
			info.push_back("Stetson University");
			int n =3123;
			print_event(info,n);
			print_event(info,n);
			print_event(info,n);
			print_event(info,n);
			print_event(info,n);
			print_event(info,n);*/
			cout<<"</div>"<<endl;
			cout<<"</section>"<<endl;
			cout<<"</article>"<<endl;
		//<=========================================FOOTER DON'T TOUCH=============================================================>
		cout<<"<footer id=\"footer\">"<<endl;
		cout<<"<ul class=\"icons\">"<<endl;
		cout<<"<li><a href=\"#\" class=\"icon circle fa-twitter\"><span class=\"label\">Twitter</span></a></li>"<<endl;
		cout<<"<li><a href=\"#\" class=\"icon circle fa-facebook\"><span class=\"label\">Facebook</span></a></li>"<<endl;
		cout<<"<li><a href=\"#\" class=\"icon circle fa-google-plus\"><span class=\"label\">Google+</span></a></li>"<<endl;
		cout<<"<li><a href=\"#\" class=\"icon circle fa-github\"><span class=\"label\">Github</span></a></li>"<<endl;
		cout<<"<li><a href=\"#\" class=\"icon circle fa-dribbble\"><span class=\"label\">Dribbble</span></a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"<ul class=\"copyright\">"<<endl;
		cout<<"<li>&copy; Helpers Help me</li><li>Design: <a href=\"http://html5up.net\">HTML5 UP</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</footer>"<<endl;
		cout<<"</div>"<<endl;
		cout<<"<script src=\"js/jquery.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/login.js\"></script>"<<endl;
		cout<<"<script src=\"js/jquery.dropotron.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/jquery.scrolly.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/jquery.scrollgress.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/skel.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/util.js\"></script>"<<endl;
		cout<<"<script src=\"js/main.js\"></script>"<<endl;
		cout << body() <<endl;
		cout << html() <<endl; 
	} catch(exception& e) {

	}
}
void print_event(vector<string> info,int event_id) {
			cout<<"<div class=\"4u 12u(narrower)\">"<<endl;
			cout<<"<section>"<<endl;
			cout<<"<header>"<<endl;
			cout<<"<h3>"<<info[0]<<"</h3>"<<endl;
			cout<<"</header>"<<endl;
			cout<<"<p>Date: "<<info[1]<<"</br>Location: "<<info[2]<<"</p>"<<endl;
			cout<<"<footer>"<<endl;
			cout<<"<ul class=\"buttons\">"<<endl;
			cout<<"<form name=\"event\" method=\"get\" action=\"home.cgi\">"<<endl;
			cout<<"<input type=\"hidden\" name=\"event_id\" value=\""<<event_id<<"\">"<<endl; 
			cout<<"<button class = \"button small\"/>Learn More</button>" << endl;
			cout<<"</form>"<<endl;
			cout<<"</ul>"<<endl;
			cout<<"</footer>"<<endl;
			cout<<"</section>"<<endl;
			cout<<"</div>"<<endl;

}
