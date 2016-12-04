#include <iostream>
#include <string>
#include <vector>

#include "cgicc/Cgicc.h"
#include "cgicc/CgiDefs.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "styles.h"
#include "controller.h"

using namespace std;
using namespace cgicc;

int main(int /*argc*/, char** /*argv*/) {
    try {
        Cgicc cgi;

        cout << HTTPHTMLHeader() << endl;
        cout << html().set("lang", "en").set("dir", "ltr") << endl;
        cout << html() << head() << endl;
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

        //print out the everything related to the event
        // description, time, location, volunteer positions
        // add button to sign up for event
        vector<vector<string> > evinfo;
        cout << "<dl><dt><b>" << evinfo[0][0] << " Organizer: "
            << evinfo[0][1] << "</b><dt>"
            << "<p><dd>Date(s): " << evinfo[0][2] 
            << " to " << evinfo[0][3] << "</dd></p>"
            << "<dt> Event Positions: </dt>\n"
            << "<dd>";
        cout << "<form method=\"post\" action=\"\">;
            for (int x =1; x < evinfo.size(); ++x) {
                cout << "<p>" << evinfo[x][0] << "</p>\n";
                cout << evinfo[x][1]
                    << " from " << evinfo[x][2] << " to " 
                    << evinfo[x][3] 
                    << "<input type=\"radio\" name=\"volunteer\" value=\"" 
                    <</*pos id*/ evinfo[x][4]<< "\"><br>\n";
            }
        cout << "</form>" << endl;
        cout << "</dd></dl>" << endl;;

        string posID = cgi("volunteer");
        


		//FOOTER
		cout <<"<div class=\"wrapper row4\">"<< endl;
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
