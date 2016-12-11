#include <iostream>
#include <vector>
#include <string>
#include "controller.h"
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "styles.h"
#include <cgicc/HTTPCookie.h>
using namespace std;
using namespace cgicc;
void print_event(vector<string> info,int event_id);
int main(int argc, char** argv){
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
        cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
        cout << html().set("lang", "en").set("dir", "ltr") << endl;
        cout << html() <<endl;                
        cout << head() << endl;
        cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>" << endl;
        //cout << style() << comment() << endl;
        //cout << styles;
        //cout << comment() << style() <<endl;
        cout << title() << "Home" << title() << endl;
        cout <<"<link rel=\"stylesheet\" href=\"css/main.css\" />"<<endl;
        cout << head() << endl; 
        cout << "<body class=\"index\">" << endl;
        cout<<"<div id=\"page-wrapper\">"<<endl;
        //HEADER
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
        cout<<"<li><a href=\"event_list.cgi\">Upcoming Events</a></li>"<<endl;
        cout<<"<li><a href=\"eventcreation.cgi\">Create Event</a></li>"<<endl;
        cout<<"<li><a href=\"my_events.cgi\">My Events</a></li>"<<endl;
        cout<<"</ul>"<<endl;
        cout<<"</li>"<<endl;
        cout<<"<li><a href=\"userprofile.cgi\">Profile</a></li>"<<endl;
        cout<<"<li><a href=\"#\">News</a></li>"<<endl;
        cout<<"<li><a href=\"#\">Contact</a></li>"<<endl;
        cout<<"<li><a href=\"#\">Donate</a></li>"<<endl;

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
        //<!-- Banner -->
        cout<<"<section id=\"banner\">"<<endl;    
        cout<<"<div class=\"inner\">"<<endl;
        cout<<"<header>"<<endl;
        cout<<"<h2>HELPERS HELP ME</h2>"<<endl;
        cout<<"</header>"<<endl;
        cout<<"<p>Create and Join volunteering events!</p>"<<endl;
        cout<<"<footer>"<<endl;
        cout<<"<ul class=\"buttons vertical\">"<<endl;
        cout<<"<li><a href=\"#main\" class=\"button fit scrolly\">Tell Me More</a></li>"<<endl;
        cout<<"</ul>"<<endl;
        cout<<"</footer>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"</section>"<<endl;
        //<!-- Main -->
        cout<<"<article id=\"main\">"<<endl;

        cout<<"<header class=\"special container\">"<<endl;
        cout<<"<span class=\"icon fa-bar-chart-o\"></span>"<<endl;
        cout<<"<h2>The best website for volunteers and organizers\
            <br />to come together.</h2>"<<endl;
        cout<<"<p><strong>Helpers Help Me</strong> was designed to allow any volunteer to organize and get\
            <br />involved in events.</p>"<<endl;
        cout<<"</header>"<<endl;
        //<!-- One -->
        cout<<"<section class=\"wrapper style2 container special-alt\">"<<endl;
        cout<<"<div class=\"row 50%\">"<<endl;
        cout<<"<div class=\"8u 12u(narrower)\">"<<endl;
        cout<<"<header>"<<endl;
        cout<<"<h2>Joining is free and will give you access to many opportunities.</h2>"<<endl;
        cout<<"</header>"<<endl;
        cout<<"<p>Once you register you will have many options. Our tools and easy web design</br>\
            will make everything for you</p>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"<div class=\"4u 12u(narrower) important(narrower)\">"<<endl;
        cout<<"<ul class=\"featured-icons\">"<<endl;
        cout<<"<li><span class=\"icon fa-clock-o\"><span class=\"label\">Feature 1</span></span></li>"<<endl;
        cout<<"<li><span class=\"icon fa-volume-up\"><span class=\"label\">Feature 2</span></span></li>"<<endl;
        cout<<"<li><span class=\"icon fa-laptop\"><span class=\"label\">Feature 3</span></span></li>"<<endl;
        cout<<"<li><span class=\"icon fa-inbox\"><span class=\"label\">Feature 4</span></span></li>"<<endl;
        cout<<"<li><span class=\"icon fa-lock\"><span class=\"label\">Feature 5</span></span></li>"<<endl;
        cout<<"<li><span class=\"icon fa-cog\"><span class=\"label\">Feature 6</span></span></li>"<<endl;
        cout<<"</ul>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"</section>"<<endl;
        //<!-- Two -->
        cout<<"<section class=\"wrapper style1 container special\">"<<endl;
        cout<<"<div class=\"row\">"<<endl;
        cout<<"<div class=\"4u 12u(narrower)\">"<<endl;
        cout<<"<section>"<<endl;
        cout<<"<span class=\"icon featured fa-check\"></span>"<<endl;
        cout<<"<header>"<<endl;
        cout<<"<h3>Join Events</h3>"<<endl;
        cout<<"</header>"<<endl;
        cout<<"<p>Join events made by our users,\
            you will get the date, time, and location of the event.</p>"<<endl;
        cout<<"</section>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"<div class=\"4u 12u()\">"<<endl;
        cout<<"<section>"<<endl;
        cout<<"<span class=\"icon featured fa-check\"></span>"<<endl;
        cout<<"<header>"<<endl;
        cout<<"<h3>Create Events</h3>"<<endl;
        cout<<"</header>"<<endl;
        cout<<"<p>Create you own event, set the number of volunteers you\
            will need, time, and location.</p>"<<endl;
        cout<<"</section>"<<endl;
        cout<<"</div>"<<endl;
       /* cout<<"<div class=\"4u 12u(narrower)\">"<<endl;
        cout<<"<section>"<<endl;
        cout<<"<span class=\"icon featured fa-check\"></span>"<<endl;
        cout<<"<header>"<<endl;
        cout<<"<h3>Rankings</h3>"<<endl;
        cout<<"</header>"<<endl;
        cout<<"<p>See how you are doing in the ranking table.\
            Keep volunteering and gain points to climb\
            on the table.</p>"<<endl;
        cout<<"</section>"<<endl;
        cout<<"</div>"<<endl;*/
        cout<<"</div>"<<endl;
        cout<<"</section>"<<endl;
        cout<<"</article>"<<endl;
        //<!-- Three -->
        cout<<"<article id=\"main\">"<<endl;
        cout<<"<section class=\"wrapper style3 container special\">"<<endl;
        cout<<"<header class=\"major\">"<<endl;
        cout<<"<h2>Popular Events</strong></h2>"<<endl;
        cout<<"</header>"<<endl;
        cout<<"<div class =\"row\">"<<endl;
        /*vector <int> events_id;
        vector <string> example_event;
        example_event.push_back("Soccer Game");
        example_event.push_back("10/12/2016 12:00 PM");
        example_event.push_back("Stetson University");    
        events_id.push_back(123);
        
        print_event(example_event,events_id[0]);
        print_event(example_event,events_id[0]);
        print_event(example_event,events_id[0]);
        print_event(example_event,events_id[0]);
        print_event(example_event,events_id[0]);
        print_event(example_event,events_id[0]);*/
    
        Controller myController;
        vector<int> eventNum = myController.showAllUpcoming();
        for(unsigned x = 0; x < eventNum.size(); x++){
            print_event(myController.showEvent(eventNum.at(x)), eventNum.at(x));
            if ( x == 5) { break; }
        }

        cout<<"</div>"<<endl;

        cout<<"<footer class=\"major\">"<<endl;
        cout<<"<ul class=\"buttons\">"<<endl;
        cout<<"<li><a href=\"event_list.cgi\" class=\"button\">See More</a></li>"<<endl;
        cout<<"</ul>"<<endl;

        cout<<"</section>"<<endl;
        cout<<"</article>"<<endl;
        //<!-- CTA -->
        cout<<"<section id=\"cta\">"<<endl;
        cout<<"<header>"<<endl;
        if(id[3]=="true"){
            cout<<"<h2>Thanks for joining our <strong>Community</strong></h2>"<<endl;
            cout<<"</header>"<<endl;
            cout<<"<footer>"<<endl;
            cout<<"<ul class=\"buttons\">"<<endl;
            cout<<"<li><a href=\"userprofile.cgi\" class=\"button special\">My Profile</a></li>"<<endl;
            cout<<"<li><a href=\"my_events.cgi\" class=\"button\">My Events</a></li>"<<endl;

        }else{
            cout<<"<h2>Ready to join our <strong>Community</strong>?</h2>"<<endl;
        cout<<"</header>"<<endl;
        cout<<"<footer>"<<endl;
        cout<<"<ul class=\"buttons\">"<<endl;
            cout<<"<li><a href=\"login.cgi#login\" class=\"button special\">Log In</a></li>"<<endl;
            cout<<"<li><a href=\"login.cgi#signup\" class=\"button\">Sign Up</a></li>"<<endl;
        }
        cout<<"</ul>"<<endl;
        cout<<"</footer>"<<endl;
        cout<<"</section>"<<endl;
        //<!-- Footer -->
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
        //"<!-- Scripts -->
        cout<<"<script src=\"js/jquery.min.js\"></script>"<<endl;
        cout<<"<script src=\"js/jquery.dropotron.min.js\"></script>"<<endl;
        cout<<"<script src=\"js/jquery.scrolly.min.js\"></script>"<<endl;
        cout<<"<script src=\"js/jquery.scrollgress.min.js\"></script>"<<endl;
        cout<<"<script src=\"js/skel.min.js\"></script>"<<endl;
        cout<<"<script src=\"js/util.js\"></script>"<<endl;
        cout<<"<script src=\"js/main.js\"></script>"<<endl;
        cout << body() <<endl;
        cout << html() <<endl;    
        return EXIT_SUCCESS;
    } catch(exception& e) {
        cout << " Error " << e.what() << endl;
        return EXIT_SUCCESS;
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
    cout<<"<form name=\"event\" method=\"get\" action=\"eventpage.cgi\">"<<endl;
    cout<<"<input type=\"hidden\" name=\"event_id\" value=\""<<event_id<<"\">"<<endl; 
    cout<<"<button class = \"button small\"/>Learn More</button>" << endl;
    cout<<"</form>"<<endl;
    cout<<"</ul>"<<endl;
    cout<<"</footer>"<<endl;
    cout<<"</section>"<<endl;
    cout<<"</div>"<<endl;

}
