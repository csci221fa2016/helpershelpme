#include <iostream>
#include <string>
#include <vector>

#include "cgicc/Cgicc.h"
#include "cgicc/CgiDefs.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "cgicc/HTTPRedirectHeader.h"
#include "cgicc/FormEntry.h"


#include "styles3.h"
#include "controller.h"

using namespace std;
using namespace cgicc;

int main(int /*argc*/, char** /*argv*/) {
    try {
        Cgicc cgi;

        const CgiEnvironment& env = cgi.getEnvironment();
        vector<string> id;
        int uID = 0;
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
            uID = stoi(id[1]);
        }
        else{
            cout<<HTTPRedirectHeader("login.cgi")<<endl;
        }
        cout << HTTPHTMLHeader() << endl;
        cout << html().set("lang", "en").set("dir", "ltr") << endl;
        cout << head() << endl;
        cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << endl;
        cout <<"<link rel=\"stylesheet\" href=\"css/main2.css\" />"<<endl;
        cout << style() << comment() << endl;
        cout << styles;
        cout << comment() << style() <<endl;
        cout << title() << "Event Page" << title() << endl;
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
        cout<<"<li><a href=\"event_list.cgi\">Upcoming Events</a></li>"<<endl;    
        cout<<"<li><a href=\"my_events.cgi\">My Events</a></li>"<<endl;
        cout<<"<li><a href=\"eventcreation.cgi\">Create Event</a></li>"<<endl;
        cout<<"</ul>"<<endl;
        cout<<"</li>"<<endl;
        cout<<"<li><a href=\"userprofile.cgi\">Profile</a></li>"<<endl;
        cout<<"<li><a href=\"#\">News</a></li>"<<endl;
        cout<<"<li><a href=\"#\">Contact</a></li>"<<endl;
        cout<<"<li><a href=\"#\">Donate</a></li>"<<endl;
        cout<<"</ul>"<<endl;
        cout<<"</li>"<<endl;
        cout<<"<li><a href=\"log_out.cgi\" class=\"button special\">Log Out</a></li>"<<endl;
        cout<<"</ul>"<<endl;
        cout<<"</nav>"<<endl;
        cout<<"</header>"<<endl;

        //<=================Event Page Information=====================>
        //print out the everything related to the event
        // description, time, location, volunteer positions
        // add button to sign up for event
        // once cookies are done add the usability here
//<===============Event Specific Information====================>
        string eID, name, posID, positionID;
        vector<string> eventID;
        bool volunteering=false, creator= false;
        vector<int> positions;
        Controller c;
        int pID, count = 0;

        name = c.showUserInfo(uID).at(0);
        form_iterator it = cgi.getElement("event_id");
        if( !it->isEmpty() && it != (*cgi).end())
            eventID.push_back(**it);      
        int evID = stoi(eventID.at(0));
        vector<vector<string> > evinfo;
        evinfo = c.showEventInfo(evID);
        positions = c.showEventsWorked(uID);
        for(int x = 0; x < positions.size(); ++x){
            if(positions.at(x) == evID) {
                volunteering = true;
                posID = positions.at(x);
            }
        }


        cout<<"<article id=\"main\">"<<endl;
        cout<<"<header class=\"special container\">"<<endl;
        cout<<"<span class=\"icon fa-laptop\"></span>"<<endl;

  //print out General Event Information in more detail
        vector<vector<string> >::iterator evIt;
        for(evIt = evinfo.begin(); evIt < evinfo.end(); ++evIt) {
            if(count == 0) {
                cout << h2() << "Event: " << strong() 
                    <<evinfo[0][0] << strong() << h2() << endl;
                cout<<"</header>"<<endl;    
                cout<<"<section class=\"wrapper style3 container special\">"<<endl;
                cout<<"<div class=\"row\">"<<endl;
                cout << cgicc::div().set("class", "form");
                cout << p() << h4() << b()
                    <<  " Organizer: "
                    << evinfo[0][1] << b() << h4() << br()
                    << "Date(s): " << evinfo[0][2] 
                    << " to " << evinfo[0][3]
                    << br() << "Event Information: " 
                    << evinfo[0][4] << br() << " located at: "
                    << evinfo[0][5] << br()
                    << " Event Positions: " << br();
                break;
            }
        }

   //print out Event Position Information in detail
        cout << evinfo[0][1] << " " << name  << " " << volunteering << endl;
        if(evinfo[0][1] != name) {
            if(volunteering == false) {
                cout << "<form method=\"post\" action=\"\">";
                for (int x = 1; x < evinfo.size(); ++x) {
                    cout << evinfo[x][0] << "</p>\n";
                    cout << "Open Positions: " 
                        << evinfo[x][2]
                        << input().set("type", "radio").set("name", "volunteer").set("value", evinfo[x][1]) 
                        << br() << endl;
                }
                cout<<"<button class = \"button small\"/>Volunteer</button>" << endl;
                cout << "</form>" << endl;
                it = cgi.getElement("volunteer");
                positionID = **it;
                pID = stoi(positionID);
                c.addVolunteer(evID, 1, pID);
            }
            else {
                cout << "<form method=\"post\" action=\"\">";
                for (int x = 1; x < evinfo.size(); ++x) {
                    cout << evinfo[x][0] << "</p>\n";
                    cout << "Open Positions: " 
                        << evinfo[x][2]
                        << br() << endl;
                }
                cout << input().set("type", "hidden").set("name", "leave_position").set("value", posID) << endl;
                cout <<"<button class = \"button small\"/>Leave Event</button>" << endl;
                cout << "</form>" << endl;
                it = cgi.getElement("leave_position");
                positionID = **it;
                pID = stoi(positionID);
                c.removeVolunteer(evID, 1, pID);
            }
        }
        else {
            cout << "<form method=\"post\" action=\"\">";
            for (int x = 1; x < evinfo.size(); ++x) {
                cout << evinfo[x][0] << "</p>\n";
                cout << "Open Positions: " 
                    << evinfo[x][2]
                    << br() << endl;
            }
           /* 
            cout<<"<button class = \"button small\"/>Delete Event</button>" << endl;
            
            */
            cout << "</form>" << endl;
        }

        cout << cgicc::div() << endl;
        
        //<==============Filler in case of Error in connection=========>
        /*cout << "<div class=\"form\" >" << endl;
        cout << "<table>\n" << endl;
        cout << "<tr><th class=\"title\">Event Name: Dog Party <td>"
            << "</th></tr>" << endl;
        cout << tr() << th() << "Organizer: Mega Mega Dog Lover"
            << th() << tr();
        cout << "<tr><td class=\"title\">Event Location: Mars, Volcanic Base<td>"
            << "</td></tr>" << endl;
        cout << "<tr><td class=\"title\">Event Description: Gathering of Pooches from the alpha center, booth to rent grav balls, floaties, and grav surfboards, food banquet free for all, there will be real grass!!!<td>"
            << "</td></tr>" << endl;
        cout << "<tr><td class=\"title\">Event Start: 3020 January 20 4:50 am <td>"
            << "</td></tr>" << endl;
        cout << "<tr><td class=\"title\">Event Finish: 3020 January 20 1:00 pm<td>"
            << "</td></tr>" << endl;
        cout << "<tr><th class=\"title\">Event Positions: <th>"
            << "</td></tr>" << endl;
        cout << tr() << td() << "Booth Cashier: " << b() << "Open: "
            << b() << "25" << b() <<  "Filled: " << b() << "3" << b() << endl;
        cout << "<tr><td class=\"title\">Event Available Positions:  <td>"
            << "</td></tr>" << endl;
        cout << "</table>" << endl;

        cout << "</div>" << endl;*/
        cout << cgicc::div() << endl;
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
        cout << "</body>" <<endl;
        cout << html() <<endl;

        return EXIT_SUCCESS;
    } catch(exception& e) {
        cout << "<pre>" << e.what() << "</pre>";
        return EXIT_SUCCESS;
    }
}
