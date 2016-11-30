#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "styles.h"
#include "controller.h"

using namespace std;
using namespace cgicc;

void
printForm(const Cgicc& cgi)
{

   cout << "<form method=\"post\".hash action=\""
        << cgi.getEnvironment().getScriptName() << "\">" << endl;


   cout << "<table>" << endl;

   cout << "<tr><td class=\"title\">Phone Number</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"pnumber\" value=\"8889990000\" id=\"1\"/>"
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Password</td>"
        << "<td class=\"form\">"
        << "<input type=\"password\" name=\"password\" value=\"password\""
        << " maxlength=\"\" autocomplete=\"off\" data-validate=\"{required: true}\"/>"
        << "</td></tr>" << endl;

   cout << "</table>" << endl;

   cout << "<div class=\"center\"><p>"
        << "<input type=\"submit\" name=\"login\"  value=\"Log In\" />"
        << "</p></div></form>" << endl;
}

int main(int argc, char **argv) {
   try{
      Cgicc cgi;
      cout << HTTPHTMLHeader() << endl;
      cout << html().set("lang","en").set("dir","ltr") <<endl;
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
      cout << title("Log In") <<endl;
      cout << head() << endl;
      cout << body() << endl;
     
      

   	  //HEADER
	  cout << "<div class=\"wrapper row1\">" << endl;
      cout << "<header id=\"header\" class=\"clear\">" << endl;
         cout << "<div id=\"hgroup\">" << endl;
            cout << "<h1><a href=\"#\">Helpers Help Me</a></h1>" << endl;
            cout << "<h2>Testing home</h2>" << endl;
         cout << "</div>" << endl;
      cout << "</header>" << endl;

      cout << "</div>" <<endl;
      cout << "<div class=\"wrapper row2\">" << endl;
          cout << "<nav id=\"topnav\">" << endl;
             cout << "<ul class=\"clear\">" << endl;
                cout << "<li class=\"active first\"><a href=\"home.cgi\">Homepage</a></li>" << endl;
                cout << "<li><a class=\"drop\" href=\"#\">Event</a>" << endl;
                   cout << "<ul>" << endl;
                      cout << "<li><a href=\"#\">List Open Events</a></li>" << endl;
                      cout << "<li><a href=\"#\">List Available Positions</a></li>" << endl;
                      cout << "<li><a class=\"drop\" href=\"#\">Level 2 + Drop</a>" << endl;
                          cout<< "<ul>" << endl;
                             cout << "<li><a href=\"#\">Level 3</a></li>" << endl;
                             cout << "<li><a class=\"drop\" href=\"#\">Level 3 + Drop</a>" << endl;
                                cout << "<ul>" << endl;
                                   cout << "<li><a href=\"#\">Level 4</a></li>" <<endl;
                                   cout << "<li><a href=\"#\">Level 4</a></li>" <<endl;
                                cout << "</ul>" <<endl;
                             cout << "</li>" << endl;
                             cout << "<li><a href=\"#\">Level 3</a></li>" <<endl;
                          cout<< "</ul>" <<endl;
                      cout << "</li>" <<endl;
                   cout << "</ul>" <<endl;
                cout << "</li>" << endl;
                cout << "<li><a href=\"#\">Profile</a></li>" << endl;
                cout << "<li><a href=\"#\">Full Width</a></li>" << endl;
                cout << "<li><a href=\"#\">Gallery</a></li>" <<endl;
                cout << "<li><a href=\"#\">Portfolio</a></li>" << endl;
                cout << "<li><a href=\"#\">A Long Link Text Here</a></li>" <<endl;
                cout << "<li class=\"last-child\"><a class=\"drop\" href=\"#\">User</a>" <<endl;
                   cout << "<ul>" << endl;
                      cout << "<li><a href=\"login.cgi\">Log In</a></li>" << endl;
                      cout << "<li><a href=\"#\">Sign up</a></li>" << endl;
                      cout << "<li><a class=\"drop\" href=\"#\">Level 2 + Drop</a>" << endl;
                         cout << "<ul class=\"negative\">" << endl;
                            cout <<"<li><a href=\"#\">Level 3</a></li>" <<endl;
                            cout <<"<li><a href=\"#\">Level 3</a></li>" << endl;
                            cout <<"<li><a href=\"#\">Level 3</a></li>" << endl;
                         cout << "</ul>" << endl;
                      cout << "</li>" << endl;
                   cout << "</ul>" << endl;
                cout <<"</li>"<< endl;
             cout <<"</ul>"<< endl;
          cout << " </nav>" << endl;
          cout << "</div>" << endl;
	  cout << br() << endl;
	  printForm(cgi);
   	  cout << hr().set("class", "half") << endl;
	  #if HAVE_UNAME
   	  struct utsname info;
   	  if(uname(&info) != -1) {
         cout << ". Running on " << info.sysname;
         cout << ' ' << info.release << " (";
         cout << info.nodename << ")." << endl;
   	  }
	  #else
      	cout << "." << endl;
	  #endif

	  #if HAVE_GETTIMEOFDAY
      	timeval end;
   		gettimeofday(&end, NULL);
      	long us = ((end.tv_sec - start.tv_sec) * 1000000)
      	+ (end.tv_usec - start.tv_usec);
      	cout << br() << "Total time for request = " << us << " us";
      	cout << " (" << static_cast<double>(us/1000000.0) << " s)";
	  #endif

	

	  //FOOTER
	   cout <<"<div class=\"wrapper row4\">"<< endl;
          cout << "<footer id=\"footer\" class=\"clear\">" <<  endl;
             cout << "<p class=\"fl_left\">Copyright &copy; 2013 - All Rights Reserved - <a href=\"#\">Domain Name</a></p>" <<endl;
              cout << "<p class=\"fl_right\">Template by <a href=\"http://www.os-templates.com/\" title=\"Free Website Templates\">OS Templates</a></p>"<<endl;
               cout << "</footer>" <<endl;
               cout << "</div>" << endl;
               cout << body() << endl;
    } catch(exception& e) {
    }
}

