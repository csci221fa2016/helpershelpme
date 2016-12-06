#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <cgicc/HTTPRedirectHeader.h>

#include "styles.h"
#include "controller.h"

using namespace std;
using namespace cgicc;
int main(int argc, char **argv) {
	try{
		Cgicc cgi;
		cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
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
		cout<<"<li><a href=\"#\">Rankings</a></li>"<<endl;
		cout<<"<li><a href=\"#\">News</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Donate</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Contact</a></li>"<<endl;
		cout<<"<li class=\"submenu\">"<<endl;
		cout<<"<a href=\"#\">Events</a>"<<endl;
		cout<<"<ul>"<<endl;
		cout<<"<li><a href=\"#\">See All Events</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Upcoming Events</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Closed Events</a></li>"<<endl;
		cout<<"<li><a href=\"#\">New Events</a></li>"<<endl;
		cout<<"<li><a href=\"#\">Past Events</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</li>"<<endl;
		cout<<"<li><a href=\"#\" class=\"button special\">Log In</a></li>"<<endl;
		cout<<"</ul>"<<endl;
		cout<<"</nav>"<<endl;
		cout<<"</header>"<<endl;
		cout<<"<section id=\"banner\">"<<endl;
		//<=======================LOGIN WORK HERE=========================================>	
		cout << "<div class = \"form\">" << endl;
		cout << "<ul class = \"tab-group\">" << endl;
		cout<<"<li class=\"tab active\"><a href=\"#signup\">Sign Up</a></li>"<<endl;
		cout<<"<li class=\"tab\"><a href=\"#login\">Log In</a></li>"<<endl;
		cout << "</ul>" << endl;
		cout << "<div class = \"tab-content\">" << endl;
		cout << "<div id = \"signup\">" << endl;
		cout << "<h1>Sign Up for Free</h1>" << endl;
//		cout << "<form action = \"/view/jtoledo/login.cgi\" method = \"post\">"<< endl;
		cout << "<form action = \"/view/lulu/sign_up_info.cgi\" method = \"post\">"<< endl;
	//	cout << "<form action = \"/view/isarmien/login.cgi\" method = \"post\">"<< endl;
//		cout << "<form action = \"/login.cgi\" method = \"post\">"<< endl;
		cout << "<div class = \"top-row\">" << endl;
		cout << "<div class = \"field-wrap\">" << endl;
		cout << "<label> First Name<span class = \"req\">*</span> </label>" << endl;
		cout << "<input type = \"text\" name=\"user_first_name\" required autocomplete = \"off\"/>" << endl;
		cout << "</div>" << endl;
		cout << "<div class =\"field-wrap\">" << endl;
		cout << "<label> Last Name<span class = \"req\">*</span> </label>" << endl;
		cout << "<input type = \"text\" name= \"user_last_name\" required autocomplete = \"off\"/>" << endl;
		cout << "</div>" << endl;
		cout << "</div>" << endl;
		cout << "<div class = \"field-wrap\">" << endl;
		cout << "<label>Phone Number<span class = \"req\">*</span> </label>" << endl;
		cout << "<input type = \"number\"name=\"user_phone_number_s\"required autocomplete=\"off\"/>" << endl;
		cout << "</div>" << endl;
		cout << "<div class = \"field-wrap\">" << endl;
		cout << "<label> Set A Password<span class = \"req\">*</span> </label>" << endl;
		cout << "<input type = \"password\"name=\"user_password_s\"required autocomplete = \"off\"/>" << endl;
		cout << "</div>" << endl;
		cout << "<button type = \"submit\" class = \"button button-block\"/>" << endl;
		cout << "Get Started"<< endl;
		cout << "</button>"<< endl;
		cout << "</form>"<< endl;
		cout << "</div>"<< endl;
		cout << "<div id = \"login\">"<< endl;
		cout << "<h1>Welcome Back!</h1>"<< endl;
//		cout << "<form action = \"/view/jtoledo/login_info.cgi\" method = \"post\">"<< endl;
		cout << "<form action = \"/view/lulu/login_info.cgi\" method = \"post\">"<< endl;
	//	cout << "<form action = \"/view/isarmien/home.cgi\" method = \"post\">"<< endl;
//		cout << "<form action = \"login_info.cgi\" method = \"post\">"<< endl;
		cout << "<div class = \"field-wrap\">"<< endl;
		cout << "<label>Phone Number<span class = \"req\">*</span></label>" << endl;
		cout << "<input type = \"number\" name=\"user_phone_number\" value=\"\" required autocomplete = \"off\"/>" << endl;
		cout << "</div>" << endl;
		cout << "<div class = \"field-wrap\">" << endl;
		cout << "<label> Password<span class = \"req\">*</span></label>" << endl;
		cout << "<input type = \"password\" name=\"user_password\" value=\"\" required autocomplete = \"off\"/>" << endl;
		cout << "</div>" << endl;
		cout << "<p class = \"forgot\"><a href = \"#\">Forgot Password ?</a></p>" << endl;
		cout << "<button class = \"button button-block\"/>" << endl;
		cout << "Log In" << endl;
		cout << "</button>" << endl;
		cout << "</form>" << endl;
		cout << "</div>" << endl;
		cout << "</div>" << endl;
		cout << "</div>" << endl;
        
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
		cout << body() <<endl;
		cout << html() <<endl;

	Controller control;
	vector<string> newuser;
	string id;
	int uID;
    const_form_iterator firstname = cgi.getElement("user_first_name");
    if(firstname!= (*cgi).end() && ! firstname->isEmpty())
       newuser.push_back((*firstname).getStrippedValue());

    const_form_iterator pnum = cgi.getElement("user_phone_number_s");
    if(pnum!= (*cgi).end() && ! pnum->isEmpty())
       newuser.push_back((*pnum).getStrippedValue());
    const_form_iterator passw = cgi.getElement("user_password_s");
    if(passw!= (*cgi).end() && ! passw->isEmpty())
       newuser.push_back((*passw).getStrippedValue());

    const CgiEnvironment& env = cgi.getEnvironment();
    const_cookie_iterator iter;

    for(iter= env.getCookieList().begin(); iter!= env.getCookieList().end(); ++iter){
       if(iter->getName()=="Authenticated"){
          string namedCookie = iter->getName();
          if(iter->getValue().find("true")){
              size_t found = iter->getValue().find(";");
              id = iter->getValue().substr(found);
              uID = stoi(id);
              cout << "I logged in " << uID << endl;
          }
          break;
        }
    }

	if(uID>=0){
	cout << "Not Possible" << endl;
	} else{
	control.sendUser(newuser,-1);
	}

//	cout << "<form action = \"/view/isarmien/home.cgi\" method = \"post\">"<< endl;

 
	} catch(exception& e) {

	}
}

//<==============================================================TESTING FUNCTIONS===============================================================>


