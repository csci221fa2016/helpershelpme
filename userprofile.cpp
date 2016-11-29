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

#include "controller.h"
#include "styles.h"

using namespace std;
using namespace cgicc;

void printform(const Cgicc& cgi) {
   cout   << "<table>\n"
          << "<tr><th>User E-Mail</th>\n"
          << "<td>anon@ymous.global</td></tr>\n"
          << "<tr><th>Phone Number</th>\n"
          << "<td>1-800-888-888</td></tr>\n"
          << "<tr><th>Hours Volunteered</th>\n"
          << "<td>0</td></tr>\n"
          << "</table>\n"
   
   cout   << "<hr>\n""<form action=\"helpers-help.me/createEvent.cgi\">\n"
          << "<form action=\"helpers-help.me/createEvent.cgi\">\n"
          << "<input type=\"submit\" value=\"Create Event\"/>\n"
          << " </form>\n"
           
   cout   << "<!--<form name=\"delete event\">\n"
          << "<input type=\"submit\" value=\"Delete Event\"/>\n"
          << "</form>-->\n"
   
   cout   << "<!-- Will recieve events/positions related to user one at a time, in vector of strings\n"
          << "i.e. a vector with event/position title, desc., etc as string val in vector-->\n"
          << " <p><h3>Events 'User' created</h3></p>\n"
          << " <dl>\n"
          << "<dt>Event1</dt>\n"
          << "<dd>Event1 desc, date, times, loc</dd>\n"
          << "<dt>Event2</dt>\n"
          << "<dd>Event2 desc, date, times, loc</dd>\n"
          << "</dl>\n"
          << "<p><h3>Previous Positions</h3></p>\n"
          << "<dl>\n"
          << "<dt>Position1</dt>\n"
          << "<dd>Event date, time worked, loc</dd>\n"
          << "</dl>" << endl;
}

int main(int /*argc*/, char** /**/) {
       Cgicc cgi;
  
       cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::html) << endl;
       cout << html().set("lang", "en").set("dir", "ltr") << endl;
       cout << html() <<endl;
       cout << head 
       cout   <<d() << endl;
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
       cout << title("Home") <<endl;
       cout << head() << endl;
       cout << body() << endl 
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
 
       cout   << "<table>\n"
              << "<tr><th>User E-Mail</th>\n"
              << "<td>anon@ymous.global</td></tr>\n"
              << "<tr><th>Phone Number</th>\n"
              << "<td>1-800-888-888</td></tr>\n"
              << "<tr><th>Hours Volunteered</th>\n"
              << "<td>0</td></tr>\n"
              << "</table>\n"
       
       cout   << "<hr>\n""<form action=\"helpers-help.me/createEvent.cgi\">\n"
              << "<form action=\"helpers-help.me/createEvent.cgi\">\n"
              << "<input type=\"submit\" value=\"Create Event\"/>\n"
              << " </form>\n"
               
       cout   << "<!--<form name=\"delete event\">\n"
              << "<input type=\"submit\" value=\"Delete Event\"/>\n"
              << "</form>-->\n"
       
       cout   << "<!-- Will recieve events/positions related to user one at a time, in vector of strings\n"
              << "i.e. a vector with event/position title, desc., etc as string val in vector-->\n"
              << " <p><h3>Events 'User' created</h3></p>\n"
              << " <dl>\n"
              << "<dt>Event1</dt>\n"
              << "<dd>Event1 desc, date, times, loc</dd>\n"
              << "<dt>Event2</dt>\n"
              << "<dd>Event2 desc, date, times, loc</dd>\n"
              << "</dl>\n"
              << "<p><h3>Previous Positions</h3></p>\n"
              << "<dl>\n"
              << "<dt>Position1</dt>\n"
              << "<dd>Event date, time worked, loc</dd>\n"
              << "</dl>" << endl;
 
       //Footer
       cout << "<div class=
aass=\"wrapper row4\">"<< endl;
       cout << "<footer id=\"footer\" class=\"clear\">" <<  endl;
       cout << "<p class=\"fl_left\">Copyright &copy; 2013 - All Rights Reserved - <a href=\"#\">Domain Name</a></p>" <<endl;
       cout << "<p class=\"fl_right\">Template by <a href=\"http://www.os-templates.com/\" title=\"Free Website Templates\">OS Templates</a></p>"<<endl;
       cout << "</footer>" <<endl;
       cout << "</div>" << endl;
       cout << body() << endl;
       return EXIT_SUCCESS;
   } catch(exception& e) {

      return EXIT_SUCCESS;
   }
}
