






void printForm(const Cgicc& cgi) {

   cout << "<table>\n"
          << "<tr><th>User E-Mail</th>\n"
          << "<td>anon@ymous.global</td></tr>\n"
          << "<tr><th>Phone Number</th>\n"
          << "<td>1-800-888-888</td></tr>\n"
          << "<tr><th>Hours Volunteered</th>\n"
          << "<td>0</td></tr>\n"
          << "</table>\n"

   cout   << "<hr>\n"
          << "<form action="helpers-help.me/createEvent.cgi">\n"
          << "<input type="submit" value="Create Event"/>
          << " </form>
           
          << "<!--<form name="delete event">
          << "<input type="submit" value="Delete Event"/>
          << "</form>-->
          << "<!-- Will recieve events/positions related to user one at a time, in vector of strings
          << "i.e. a vector with event/position title, desc., etc as string val in vector-->
          << " <p><h3>Events 'User' created</h3></p>
          << " <dl>
          << "<dt>Event1</dt>
          << "<dd>Event1 desc, date, times, loc</dd>
          << "<dt>Event2</dt>
          << "<dd>Event2 desc, date, times, loc</dd>
          << "</dl>
          << "<p><h3>Previous Positions</h3></p>
          << "<dl>
          << "<dt>Position1</dt>
          << "<dd>Event date, time worked, loc</dd>
          << "</dl>" << endl;
}
