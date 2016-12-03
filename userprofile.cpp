/*
 * Profile page of the user, unique to every user
 * Primary Use:
 *      View personal information
 *      Create an event
 *      View initial list of events created
 *      View initial list of volunteer positions held
 *
 * Author: Luisa M, CSC221 fall 2016
 * Date: 11/21/2016
 */

#include <iostream>
#include <vector>
#include <string>

#include "cgicc/Cgicc.h"
#include "cgicc/CgiDefs.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "cgicc/HTTPRedirectHeader.h"

#include "controller.h"
#include "styles.h"

using namespace std;
using namespace cgicc;

int z;

bool evaluate(const Cgicc& cgi);
void userID(string ui);

//show all the information relating to the user if they are logged in
//i.e personal information, events they have organized,
//      volunteer positions they have held, etc.
//Redirects to the login page if verification fails
void printform(const Cgicc& cgi, Controller& c) {
   if (evaluate(cgi)) {
       vector<string> userinfo = c.showUserInfo(z);
       vector<int> eventinfo = c.showOrganizedEvents(z);
       vector<int> posinfo = c.showEventsWorked(z);
       cout   << "<table>\n"
              << "<tr><th>User E-Mail</th>\n"
              << "<td>" << userinfo[0] << "</td></tr>\n"
              << "<tr><th>Phone Number</th>\n"
              << "<td>" << userinfo[1] << "</td></tr>\n"
              << "<tr><th>Hours Volunteered</th>\n"
              << "<td>N/A</td></tr>\n"
              << "</table>\n";
       
       cout   << "<hr>\n <form action=\"helpers-help.me/createEvent.cgi\">\n"
              << "<form action=\"helpers-help.me/createEvent.cgi\">\n"
              << "<input type=\"submit\" value=\"Create Event\"/>\n"
              << " </form>\n";
               
       cout   << "<!--<form name=\"delete event\">\n"
              << "<input type=\"submit\" value=\"Delete Event\"/>\n"
              << "</form>-->\n";
       
       cout   << "<!-- Will recieve events/positions related to user one at a time, in vector of strings\n"
              << "i.e. a vector with event/position title, desc., etc as string val in vector-->\n"
              << " <p><h3>Events 'User' created</h3></p>\n"
              << " <dl>\n";
       int x;
    //***********IMPORTANT: go into controller later and verify the
    //positions of the information AND function names.
       for( x = 0; x < eventinfo.size(); ++x){
           vector<vector<string> > einfo = c.showEvent(eventinfo[x]);
           cout   << "<dt><a href=\"\">" << einfo[x][0] << " in " << einfo[x][1] << "</a></dt>\n"
                  << "<dd>1a" << einfo[x][2] << "</dd>\n";
       }
       cout  << "</dl>\n";
       cout << "<p><h3>Previous Positions</h3></p>\n"
            << "<dl>\n";
       for( x = 0; x < posinfo.size(); ++x){
//          do Position name, event name, hours worked
           vector<string> pinfo = c.showEventPositions(posinfo[x]);
           cout << "<dt>Position: " << pinfo[x][0] // << " in event " 
                << " " << "</dt>\n"
//                << "<dd>Hours Worked: " <<  pinfo[x][2]
//                << "</dd>\n";
       }
       cout   << "</dl>" << endl;
   } else {
//         cout << HTTPRedirectHeader("helpers-help.me/login.cgi")) << endl;
         cout << HTTPRedirectHeader("helpers-help.me/view/lulu/login.cgi") << endl;
//         cout << HTTPRedirectHeader("helpers-help.me/view/isarmien/login.cgi")) << endl;
//         cout << HTTPRedirectHeader("helpers-help.me/view/jtoledo/login.cgi")) << endl;
   }
}

/*
 * Determines whether the person accessing
 * the page is signed in
 * */
bool evaluate(const Cgicc& cgi) {
   const CgiEnvironment& env = cgi.getEnvironment();

   if(!env.getCookieList().empty()) {
       const_cookie_iterator it;
       for (it = env.getCookieList().begin();
            it != env.getCookieList().end(); ++it) {
           if(it->getName() == "Authenticated") {
               if(it->getValue().find("true")) {
                  userID(it->getValue());
                  return true;
               }
               break;
           }
       }
   }
   return false;
}

/*
 * finds and sets the userId to 
 * a global variable
 * @author: Luisa Molina
 * */
void userID(string ui) {
    int x = ui.find(";");
    ui = ui.substr(x);
    x = ui.find(";");
    ui = ui.substr(0, x);
    z = stoi(ui);
}

int main(int /*argc*/, char** /**/) {
   try{
       Cgicc cgi;
  
       cout << HTTPHTMLHeader() << endl;
       cout << html().set("lang", "en").set("dir", "ltr") << endl;
       cout << html() << endl;
       cout << head() << endl;
       cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << endl;
       cout << style() << comment() << endl;
       cout << styles;
       cout << comment() << style() <<endl;
       cout << "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js\"></script>" << endl;
       cout << "<script>" << endl;
       cout << "jQuery.noConflict()(function ($) {\
           $(\"<form id='mobilemenu'><select /></form>\").appendTo(\"#topnav\");\
           $(\"<option />\", {\
               \"selected\": \"selected\",\
               \"value\": \"\",\
               \"text\": \"Please Click Here To Navigate\"\
           }).appendTo(\"#topnav select\");\
           $(\"#topnav a\").each(function () {\
               var el = $(this);\
               var prefix = '';\
               switch (el.parents().length) {\
                   case (6):\
                       prefix = '';\
                       break;\
                   case (8):\
                       prefix = '- - - ';\
                      break;\
                   case (10):\
                       prefix = '- - - - - ';\
                       break;\
                   case (12):\
                       prefix = '- - - - - - - ';\
                       break;\
                   default:\
                       prefix = '';\
                       break;\
               }\
               $(\"<option />\", {\
                   \"value\": el.attr(\"href\"),\
                   \"text\": prefix + el.text()\
               }).appendTo(\"#topnav select\");\
               $(\"#topnav select\").change(function () {\
                   window.location = $(this).find(\"option:selected\").val();\
               });\
           });\
       });"<< endl;
       cout << "</script>" << endl;
       cout << title("Profile") <<endl;
       cout << head() << endl;
       cout << body() << endl; 
       //header
       cout << "<div class=\"wrapper row1\">" << endl;
       cout << "<header id=\"header\" class=\"clear\">" << endl;
       cout << "<div id=\"hgroup\">" << endl;
       cout << "<h1><a href=\"#\">helpers help me</a></h1>" << endl;
       cout << "<h2>testing home</h2>" << endl;
       cout << "</div>" << endl;
       cout << "</header>" << endl;
       cout << "</div>" <<endl;
       cout << "<div class=\"wrapper row2\">" << endl;
       cout << "<nav id=\"topnav\">" << endl;
       cout << "<ul class=\"clear\">" << endl;
       cout << "<li class=\"active first\"><a href=\"home.cgi\">homepage</a></li>" << endl;
       cout << "<li><a class=\"drop\" href=\"#\">event</a>" << endl;
       cout << "<ul>" << endl;
       cout << "<li><a href=\"#\">list open events</a></li>" << endl;
       cout << "<li><a href=\"#\">list available positions</a></li>" << endl;
       cout << "<li><a class=\"drop\" href=\"#\">level 2 + drop</a>" << endl;
       cout<< "<ul>" << endl;
       cout << "<li><a href=\"#\">level 3</a></li>" << endl;
       cout << "<li><a class=\"drop\" href=\"#\">level 3 + drop</a>" << endl;
       cout << "<ul>" << endl;
       cout << "<li><a href=\"#\">level 4</a></li>" <<endl;
       cout << "<li><a href=\"#\">level 4</a></li>" <<endl;
       cout << "</ul>" <<endl;
       cout << "</li>" << endl;
       cout << "<li><a href=\"#\">level 3</a></li>" <<endl;
       cout<< "</ul>" <<endl;
       cout << "</li>" <<endl;
       cout << "</ul>" <<endl;
       cout << "</li>" << endl;
       cout << "<li><a href=\"#\">profile</a></li>" << endl;
       cout << "<li><a href=\"#\">full width</a></li>" << endl;
       cout << "<li><a href=\"#\">gallery</a></li>" <<endl;
       cout << "<li><a href=\"#\">portfolio</a></li>" << endl;
       cout << "<li><a href=\"#\">a long link text here</a></li>" <<endl;
       cout << "<li class=\"last-child\"><a class=\"drop\" href=\"#\">user</a>" <<endl;
       cout << "<ul>" << endl;
       cout << "<li><a href=\"login.cgi\">log in</a></li>" << endl;
       cout << "<li><a href=\"#\">sign up</a></li>" << endl;
       cout << "<li><a class=\"drop\" href=\"#\">level 2 + drop</a>" << endl;
       cout << "<ul class=\"negative\">" << endl;
       cout <<"<li><a href=\"#\">level 3</a></li>" <<endl;
       cout <<"<li><a href=\"#\">level 3</a></li>" << endl;
       cout <<"<li><a href=\"#\">level 3</a></li>" << endl;
       cout << "</ul>" << endl;
       cout << "</li>" << endl;
       cout << "</ul>" << endl;
       cout <<"</li>"<< endl;
       cout <<"</ul>"<< endl;
       cout << " </nav>" << endl;
       cout << "</div>" << endl;
     
       //Footer
       cout << "<div class=\"wrapper row4\">"<< endl;
       cout << "<footer id=\"footer\" class=\"clear\">" <<  endl;
       cout << "<p class=\"fl_left\">Copyright &copy; 2013 - All Rights Reserved - <a href=\"#\">Domain Name</a></p>" <<endl;
       cout << "<p class=\"fl_right\">Template by <a href=\"http://www.os-templates.com/\" title=\"Free Website Templates\">OS Templates</a></p>"<<endl;
       cout << "</footer>" <<endl;
       cout << "</div>" << endl;
       cout << body() << endl;
       return EXIT_SUCCESS;
   } catch(exception& e) {
      cout << "<pre>" << e.what() << "</pre>";
      return EXIT_SUCCESS;
   }
}
