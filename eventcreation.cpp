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

	const CgiEnvironment& env = cgi.CgiEnvironment();
	const_cookie_iterator iter;

   for(iter= env.getCookieList().begin(); iter!= env.getCookierList().end(); ++iter){
   
   if(iter->getName()=="Authenticated"){
	string namedCookie = iter->getName();
	
	if(iter->getValue().find("true")){

   cout << "<table>" << endl;

   cout << "<tr><td class=\"title\">Event Name</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"ename\" value=\"fundraiser\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Description</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"edescription\" value=\"What is it about? What will people do at it?\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Location</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"elocation\" value=\"Where will it be at?\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Date Start</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"estart\" value=\"When does it start? (DD/MM/YYYY)\""
        << "</td></tr>" 
 
   cout << "<tr><td class=\"title\">Event Date End</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"efinish\" value=\"When does it end? (YYYY/MM/DD)\""
        << "</td></tr>"

   << endl;  cout << "</table>" << endl;

   cout << "<div class=\"center\"><p>"
        << "<input type=\"button\" name=\"epos\"  value=\"Add Event Position\" />"
        << "</p></div></form>" << endl;

   cout << "<div class=\"center\"><p>"
        << "<input type=\"submit\" name=\"login\"  value=\"Log In\" />"
        << "</p></div></form>" << endl;
	
	}
	else
	{
//	cout << HTTPRedirectHeader(string("helpers-help.me/userprofile.cgi?id=").append(success[1])) << endl;
//	cout << "<meta http-equiv=\"refresh\" content=\"0; helpers-help.me/view/lulu/userprofile.cgi?id=" << namedCookie << "\">" << endl;
	cout << "<meta http-equiv=\"refresh\" content=\"0; helpers-help.me/view/isarmien/userprofile.cgi\">" << endl;
//	cout << "<meta http-equiv=\"refresh\" content=\"0; helpers-help.me/view/jtoledo/userprofile.cgi?id=" << namedCookie << "\">" << endl;
	}
	break;
   }
   }
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
	 
	 //EventCreation Code
	

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

