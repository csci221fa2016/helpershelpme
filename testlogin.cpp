/*
 * login page for Helpers Help Me
 * Using original formatting from the cgicc examples,
 * though majority was discarded
 *
 * Author: Luisa Molina
 * Date: 11/19/2016
 */

/*! \file testlogin.cpp
 * \brief GNU %cgicc test application for login
 */

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

#if HAVE_SYS_UTSNAME_H
#  include <sys/utsname.h>
#endif

#if HAVE_SYS_TIME_H
#  include <sys/time.h>
#endif

//#include "styles.h"

using namespace std;
using namespace cgicc;

// Print the form for this CGI
void printForm(const Cgicc& cgi)
{

   cout << "<form method=\"post\".hash action=\"" 
        << cgi.getEnvironment().getScriptName() << "\">" << endl;


   cout << "<table>" << endl;

//   if( a> 0 ) cout << "Invalid Phone Number or Password\n";
//   else if (a == 4) cout << "last attempt\n";

   cout << "<tr><td class=\"title\">Phone Number</td>"
        << "<td class=\"form\">"
        << "<input type=\"text\" name=\"pnumber\" value=\"8889990000"/*needs default number*/"\" id=\"1\"/>"
        << "</td></tr>" << endl;
 
   cout << "<tr><td class=\"title\">Password</td>"
        << "<td class=\"form\">"
        << "<input type=\"password\" name=\"password\" value=\"password\" "
        /* maxlength=\"\" autocomplete="off" data-validate="{required: true}" */"/>"
//       << "<a href=\"accountresetlink\" style="margin-left">Forgot Password</a>"
        << "</td></tr>" << endl;
 
   cout << "</table>" << endl;
 
   cout << "<div class=\"center\"><p>"
        << "<input type=\"submit\" name=\"login\"  value=\"Log In\" />"
        << "</p></div></form>" << endl;
}

// Main Street, USA
int main(int /*argc*/, char ** /*argv*/)
{
//   int i = 0;
//   while(i != 5){
   try {
#if HAVE_GETTIMEOFDAY
   timeval start;
   gettimeofday(&start, NULL);
#endif

   // Create a new Cgicc object containing all the CGI data
   Cgicc cgi;

   // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
   cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
   cout << html().set("lang", "en").set("dir", "ltr") << endl;
   
   // Set up the page's header and title.
   // I will put in lfs to ease reading of the produced HTML. 
   cout << head() << endl;

   cout << title() << "Helpers Help Me Test Log In" 
      << title() << endl;

   cout << head() << endl;

   // Start the HTML body
   cout << body() << endl;

   // Get a pointer to the environment
//   const CgiEnvironment& env = cgi.getEnvironment();

   //put input into vector form entry, send to controller and if not, return 
   //invalid username/password
  
/*   // Print out the form to do it again
   cout << br() << endl;
   printForm(cgi, i);
   cout << hr().set("class", "half") << endl;*/

   vector<string> loginfo;
   const_form_iterator pw = cgi.getElement("password");
   if(pw != (*cgi).end() && !pw->isEmpty()) {
      loginfo.push_back((*pw).getStrippedValue());
   }
   const_form_iterator phoneNum = cgi.getElement("pnumber");
   if(phoneNum != (*cgi).end() && !phoneNum->isEmpty()) {
      loginfo.push_back((*phoneNum).getStrippedValue());
   }
   loginfo.push_back("1");

   // Information on cgicc
   cout << cgicc::div().set("align","center").set("class","smaller") << endl;
   cout << "GNU cgi" << span("cc").set("class","red") << " v";
   cout << cgi.getVersion() << br() << endl;
   cout << "Compiled at " << cgi.getCompileTime();
   cout << " on " << cgi.getCompileDate() << br() << endl;

   cout << "Configured for " << cgi.getHost();  

#if HAVE_GETTIMEOFDAY
    // Information on this query
    timeval end;
    gettimeofday(&end, NULL);
    long us = ((end.tv_sec - start.tv_sec) * 1000000)
      + (end.tv_usec - start.tv_usec);

    cout << br() << "Total time for request = " << us << " us";
    cout << " (" << static_cast<double>(us/1000000.0) << " s)";
#endif

    // End of document
    cout << cgicc::div() << endl;
    cout << body() << html() << endl;

    // No chance for failure in this example
    return EXIT_SUCCESS;
  }
  // Did any errors occur?
  catch(const std::exception& e) {

    // This is a dummy exception handler, as it doesn't really do
    // anything except print out information.

    // Reset all the HTML elements that might have been used to 
    // their initial state so we get valid output
    html::reset(); 	head::reset(); 		body::reset();
    title::reset(); 	h1::reset(); 		h4::reset();
    comment::reset(); 	td::reset(); 		tr::reset(); 
    table::reset();	cgicc::div::reset(); 	p::reset(); 
    a::reset();		h2::reset(); 		colgroup::reset();

   // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
   cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
   cout << html().set("lang", "en").set("dir", "ltr") << endl;
   
   // Set up the page's header and title.
   // I will put in lfs to ease reading of the produced HTML. 
   cout << head() << endl;

   cout << title() << "Helpers Help Me Test Log In" 
      << title() << endl;

   cout << head() << endl;

   // Start the HTML body
   cout << body() << endl;

   //put input into vector form entry, send to controller and if not, return 
   //invalid username/password

    cout << "Invalid login" << endl;  

    cout << body() << html() << endl;

    // No chance for failure in this example
    return EXIT_SUCCESS;

//    i ++;
  }
//  }
}
