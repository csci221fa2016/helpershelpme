#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "cgicc/HTTPRedirectHeader.h"
#include "cgicc/HTTPCookie.h"

#include "styles.h"
#include "controller.h"

using namespace std;
using namespace cgicc;

string Z;

bool evaluate(const Cgicc& cgi);
string find();

void printForm(const Cgicc& cgi)
{
   if(evaluate(cgi)) {
       cout << "<form method=\"post\" action=\""
            << cgi.getEnvironment().getScriptName() << "\">" << endl;
  
       cout << "<table align=\"center\">" << endl;
  
       cout << "<tr><td class=\"title\">Phone Number</td>"
            << "<td class=\"phone\">"
            << "<input type=\"text\" name=\"pnumber\" value=\"8889990000\"/>"
            << "</td></tr>" << endl;
  
       cout << "<tr><td class=\"title\">Password</td>"
            << "<td><input type=\"password\" name=\"password\" value=\"password\""
            << " maxlength=\"\" autocomplete=\"off\" data-validate=\"{required: true}\"/>"
            << "</td></tr>" << endl;
  
       cout << "</table>" << endl;
  
       cout << "<div class=\"center\"><p>"
            << "<input type=\"submit\" name=\"login\"  value=\"Log In\" />"
            << "</p></div></form>" << endl;
   }
   else{
//         cout << HTTPRedirectHeader(string("helpers-help.me/userprofile.cgi?id=").append(a)) << endl;
         string l = find();
         cout << HTTPRedirectHeader(string("helpers-help.me/view/lulu/userprofile.cgi?id=").append(Z)) << endl;
//         cout << HTTPRedirectHeader(string("helpers-help.me/view/isarmien/userprofile.cgi?id=").append(a)) << endl;
//         cout << HTTPRedirectHeader(string("helpers-help.me/view/jaledo/userprofile.cgi?id=").append(a)) << endl;
   }
}

string find() {
   int x = Z.find(";");
   Z = Z.substr(x);
   x = Z.find(";");
   Z = Z.substr(0, x);
   return Z;
}

bool evaluate(const Cgicc& cgi) {
   const CgiEnvironment& env = cgi.getEnvironment();

   if(!env.getCookieList().empty()) {
       const_cookie_iterator it;
       for (it = env.getCookieList().begin(); it != env.getCookieList().end(); ++it) {
           if(it->getName() == "Authenticated") {
               if(it->getValue().find("true")) {
                  Z = it->getValue();
                  find();
                  return true;
               }
               break;
           }
       }
   }
   return false;
}

int main(int argc, char **argv) {
   try{
      Cgicc cgi;
      HTTPCookie c;
      c.setName("Authenticated");
      c.setValue("false");
      cout << HTTPHTMLHeader().setCookie(c) << endl;

      //retrieves form information and sends it to controller
      vector<string> loginfo;
      Controller control;
      const_form_iterator phoneNum = cgi.getElement("pnumber");
      if(phoneNum != (*cgi).end() && !phoneNum->isEmpty())
          loginfo.push_back((*phoneNum).getStrippedValue());
      const_form_iterator pw = cgi.getElement("password");
      if(pw != (*cgi).end() && !pw->isEmpty())
         loginfo.push_back((*pw).getStrippedValue());
      vector<string> success = control.signIn(loginfo);
      if(success[0] == "true") {
         string val;
         val.append(success[0]).append(";").append(success[0]);
         c.setValue(val);
         cout << p().set("align", "center") << "Sign In Successful!" << p() << endl;
//         cout << HTTPRedirectHeader(string("helpers-help.me/userprofile.cgi?id=").append(success[1])) << endl;
         cout << HTTPRedirectHeader(string("helpers-help.me/view/lulu/userprofile.cgi?id=").append(success[1])) << endl;
//         cout << HTTPRedirectHeader(string("helpers-help.me/view/isarmien/userprofile.cgi?id=").append(success[1])) << endl;
//         cout << HTTPRedirectHeader(string("helpers-help.me/view/jtoledo/userprofile.cgi?id=").append(success[1])) << endl;
      } else {
         cout << "<p> Username or Password Invalid </p>" << endl;
         printForm(cgi);
      }

      cout << html().set("lang","en").set("dir","ltr") <<endl;
      cout << html() << endl;
      cout << head() << endl;
      cout << meta().set("name", "viewport").set("content", "width=device-width, initial-scale=1.0") << endl;
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
      cout << "<li><a href=\"#\">List Events</a></li>" << endl;
      cout << "<li><a href=\"#\">List Available Positions</a></li>" << endl;
      cout << "<li><a class=\"drop\" href=\"#\">Old Events</a>" << endl;
      cout<< "<ul>" << endl;
      cout << "<li><a href=\"#\">2015</a></li>" << endl;
      cout << "<li><a href=\"#\">2016</a></li>" <<endl;
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

