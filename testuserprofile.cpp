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
#include "cgicc/"

//#include "styles.h"

void printForm(const Cgicc& cgi) {

   cout   << "<table>\n"
          << "<tr><th>User E-Mail</th>\n"
          << "<td>anon@ymous.global</td></tr>\n"
          << "<tr><th>Phone Number</th>\n"
          << "<td>1-800-888-888</td></tr>\n"
          << "<tr><th>Hours Volunteered</th>\n"
          << "<td>0</td></tr>\n"
          << "</table>\n"

   cout   << "<hr>\n"
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

int main() {


   
}
