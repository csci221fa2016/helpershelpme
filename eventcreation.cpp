#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <cgicc/CgiEnvironment.h>

#include "sqlite3.h"

#if HAVE_SYS_UTSNAME_H
#  include <sys/utsname.h>
#endif

#if HAVE_SYS_TIME_H
#  include <sys/time.h>
#endif

/*
#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"*/
#include "styles.h"
#include "controller.h"


using namespace std;
using namespace cgicc;

//bool evaluate(const Cgicc& cgi);

void printForm(const Cgicc& cgi)
{
//  if(evaluate(cgi)){

   cout << "<table>" << endl;

   cout << "<tr><td class=\"title\">Event Name</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"ename\" value=\"\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Description</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"edescription\" value=\"\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Location</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"elocation\" value=\"\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Date Start</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"estart\" value=\"YYYY-MM-DD HH:MM\""
        << "</td></tr>" << endl;
 
   cout << "<tr><td class=\"title\">Event Date End</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"efinish\" value=\"YYYY-MM-DD HH:MM\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Position 1</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"epos1\" value=\"\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Position 1 Number</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"epos1num\" value=\"\""
        << "</td></tr>" << endl;

   cout << "<tr><td class=\"title\">Event Position 2</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"epos2\" value=\"\""
        << "</td></tr>" << endl;
 
   cout << "<tr><td class=\"title\">Event Position 2 Number</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"epos2num\" value=\"\""
        << "</td></tr>" << endl;
 
   cout << "<tr><td class=\"title\">Event Position 3</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"epos3\" value=\"\""
        << "</td></tr>" << endl;
 
   cout << "<tr><td class=\"title\">Event Position 3 Number</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"epos3num\" value=\"\""
        << "</td></tr>" << endl;
 
   cout << "</table>" << endl;

/*   cout << "<div class=\"center\"><p>"
        << "<input type=\"submit\" name=\"epos\"  value=\"Add Event Position\" />"
        << "</p></div></form>" << endl;*/

   cout << "<div class=\"center\"><p>"
        << "<input type=\"submit\" name=\"subEvent\"  value=\"Submit Event\" />"
//        << "</p></div></form>" << endl;
    << "<form action = \"/view/isarmien/home.cgi\" method = \"post\">"<< endl;
	
/*	}
	else
	{
//	cout << HTTPRedirectHeader(string("helpers-help.me/userprofile.cgi?id=").append(success[1])) << endl;
//	cout << "<meta http-equiv=\"refresh\" content=\"0; helpers-help.me/view/lulu/userprofile.cgi?id=" << namedCookie << "\">" << endl;
	cout << "<meta http-equiv=\"refresh\" content=\"0; helpers-help.me/view/isarmien/userprofile.cgi\">" << endl;
//	cout << "<meta http-equiv=\"refresh\" content=\"0; helpers-help.me/view/jtoledo/userprofile.cgi?id=" << namedCookie << "\">" << endl;
	}
	break;
   }
   }*/
}

/*
bool evaluate(Cgicc& cgi)
{
	const CgiEnvironment& env = cgi.CgiEnvironment();
	const_cookie_iterator iter;

   for(iter= env.getCookieList().begin(); iter!= env.getCookierList().end(); ++iter){
   
   if(iter->getName()=="Authenticated"){
	string namedCookie = iter->getName();
	
	if(iter->getValue().find("true")){
	return true;
	}
    break;
    }
    }

    return false;

}*/

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
	 int uID =-10;
	 string id;
         Controller control;
	 vector<string> eventinfo;
	 vector<string> eventpos;
	 vector<vector<string>> eventcreate;
	 const_form_iterator eventname = cgi.getElement("ename");
         if(eventname!= (*cgi).end() && ! eventname ->isEmpty())
             eventinfo.push_back((*eventname).getStrippedValue());
         const_form_iterator eventdesc = cgi.getElement("edescrition");
         if(eventdesc!= (*cgi).end() && ! eventdesc ->isEmpty())
            eventinfo.push_back((*eventdesc).getStrippedValue());
         const_form_iterator eventloc = cgi.getElement("elocation");
         if(eventloc!= (*cgi).end() && ! eventloc ->isEmpty())
            eventinfo.push_back((*eventloc).getStrippedValue());
         const_form_iterator eventst = cgi.getElement("estart");
         if(eventst!= (*cgi).end() && ! eventst ->isEmpty())
            eventinfo.push_back((*eventst).getStrippedValue());
         const_form_iterator eventfin = cgi.getElement("efinish");
         if(eventfin!= (*cgi).end() && ! eventfin ->isEmpty())
            eventinfo.push_back((*eventfin).getStrippedValue());
         const_form_iterator eventposi1 = cgi.getElement("epos1");
         if(eventposi1!= (*cgi).end() && ! eventposi1 ->isEmpty())
            eventpos.push_back((*eventposi1).getStrippedValue());
         const_form_iterator eventposi2 = cgi.getElement("epos2");
         if(eventposi2!= (*cgi).end() && ! eventposi2->isEmpty())
            eventpos.push_back((*eventposi2).getStrippedValue());
         const_form_iterator eventposi3 = cgi.getElement("epos3");
         if(eventposi3!= (*cgi).end() && ! eventposi3->isEmpty())
            eventpos.push_back((*eventposi3).getStrippedValue());
         const_form_iterator eventposi1n = cgi.getElement("epos1num");
         if(eventposi1n!= (*cgi).end() && ! eventposi1n->isEmpty())
            eventpos.push_back((*eventposi1).getStrippedValue());
         const_form_iterator eventposi2n = cgi.getElement("epos2num");
         if(eventposi2n!= (*cgi).end() && ! eventposi2n->isEmpty())
            eventpos.push_back((*eventposi2n).getStrippedValue());
         const_form_iterator eventposi3n = cgi.getElement("epos3num");
         if(eventposi3n!= (*cgi).end() && ! eventposi3n->isEmpty())
            eventpos.push_back((*eventposi3n).getStrippedValue());

	 const CgiEnvironment& env = cgi.getEnvironment();
	 const_cookie_iterator iter;

	 for(iter= env.getCookieList().begin(); iter!= env.getCookieList().end(); ++iter){
	  if(iter->getName()=="Authenticated"){
	  string namedCookie = iter->getName();
	 if(iter->getValue().find("true")){
	 size_t found = iter->getValue().find(";");
	 id = iter->getValue().substr(0,found);
	 uID = stoi(id);
	 }
	 break;
	 }
	 }

	 control.sendEvent(eventcreate,uID);

//         cout << "<form action = \"/view/isarmien/home.cgi\" method = \"post\">"<< endl;


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

