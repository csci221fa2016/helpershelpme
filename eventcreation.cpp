#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPCookie.h"
#include "cgicc/HTTPRedirectHeader.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <cgicc/CgiEnvironment.h>

#include "sqlite3.h"
#include "styles.h"
#include "controller.h"


using namespace std;
using namespace cgicc;


void printForm(const Cgicc& cgi)
{

	cout << "<div class = \"form\">" << endl;
	cout << "<h1>Create your own Event!</h1>"<< endl;
	cout << "<form action = \"eventcreation_info.cgi\" method = \"post\">"<< endl;	
	cout << "<div class = \"field-wrap\">"<< endl;
	cout << "<label>Event Name<span class = \"req\">*</span></label>" << endl;
	cout << "<input type = \"text\" name=\"e_name\" required autocomplete = \"off\"/>" << endl;
	cout << "</div>" << endl;
	cout << "<div class = \"field-wrap\">"<< endl;
	cout << "<label>Event Description (20 Character Max)<span class = \"req\">*</span></label>" << endl;
	cout << "<input type = \"text\" name=\"e_descrip\" required autocomplete = \"off\"/>" << endl;
	cout << "</div>" << endl;
	cout << "<div class = \"field-wrap\">"<< endl;
	cout << "<label>Event Location<span class = \"req\">*</span></label>" << endl;
	cout << "<input type = \"text\" name=\"e_location\" required autocomplete = \"off\"/>" << endl;
	cout << "</div>" << endl;
	cout << "<div class = \"field-wrap\">"<< endl;
	cout << "<label>___________________________Event Date Start<span class = \"req\">*</span></label>" << endl;
	cout << "<input type = \"datetime-local\" name=\"e_date_start\" required autocomplete = \"off\"/>" << endl;
	cout << "</div>" << endl;
	cout << "<div class = \"field-wrap\">"<< endl;
	cout << "<label>___________________________Event Date End<span class = \"req\">*</span></label>" << endl;
	cout << "<input type = \"datetime-local\" name=\"e_date_end\" required autocomplete = \"off\"/>" << endl;
	cout << "</div>" << endl;
	cout << "<div id =\"new-field\">"<<endl;
	cout<<"<div>"<<endl;
	cout << "<div class = \"field-wrap\">"<< endl;
	cout << "<label>____________Position number 1:</label>" << endl;
	cout << "<input type = \"text\" name=\"e_position_1\" required autocomplete = \"off\"/>" << endl;
	cout << "</div>" << endl;
	cout << "<div class = \"field-wrap\">"<< endl;
	cout << "<label>____________# of volunteers for position 1:<span class = \"req\">*</span></label>" << endl;
	cout << "<input type = \"number\" name=\"e_position_1_number\" required autocomplete = \"off\"/>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" <<endl;
	cout <<"</div>"<<endl;	
	cout<<"<input type=\"button\" id=\"new-field\" onclick=\"add_fields();\" value=\"Add More Positions\" />"<<endl;
	cout << "<button type = \"submit\" class = \"button button-block\">Submit</button>" << endl;
	cout<<"</form>"<<endl;
	cout << "</div>"<<endl;
	cout<<"</div>"<<endl;

}


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
		cout <<"<link rel=\"stylesheet\" href=\"css/main2.css\" />"<<endl;
		cout << style() << comment() << endl;
		cout << styles;
		cout << comment() << style() <<endl;
		cout << title() << "Login/Sign Up" << title() << endl;
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
		cout<<"<li><a href=\"#\">See All Events</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Upcoming Events</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Closed Events</a></li>"<<endl;
		cout<<"<li><a href=\"eventcreation.cgi\">Create Event</a></li>"<<endl;
		cout<<"<li><a href=\"#\">My Events</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</li>"<<endl;
		cout<<"<li><a href=\"#\">Rankings</a></li>"<<endl;
		cout<<"<li><a href=\"#\">News</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Donate</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Contact</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</li>"<<endl;
		if(id[3]=="true"){
			cout<<"<li><a href=\"log_out.cgi\" class=\"button special\">Log Out</a></li>"<<endl;
		}
		else{
			cout<<"<li><a href=\"login.cgi\" class=\"button special\">Log in</a></li>"<<endl;
		}
		cout<<"</ul>"<<endl;
		cout<<"</nav>"<<endl;
		cout<<"</header>"<<endl;
		cout<<"<section id=\"banner\">"<<endl;
		printForm(cgi);
		//<=========================================FOOTER DON'T TOUCH=============================================================>
		cout<<"</section>"<<endl;
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
		cout<<"<script src=\"js/add_field.js\"></script>"<<endl;
		cout << body() <<endl;
		cout << html() <<endl; 

	} catch(exception& e) {
	}
}

