/*
 * Page where user sees what volunteer positions
 * they've held, hold, or are waiting to hold.
 *
 * Author: Luisa M
 * Date: 11/20/2016
 */

#include <string>
#include <iostream>

#include "cgicc/Cgicc.h"

using namespace std;
using namespace cgicc;

//function to retrieve volunteer positions tied to userid
//function to display retrieved info, most likely something 
//      similar to an info dump

void printForm(const Cgicc& cgi) {
    cout << "<form method=\"post\" action=\""
        << cgi.getEnvironment().getScriptName() << "\>" << endl;

    cout << "<tr><td class =\"Positions\">Positions Held</td>"
        << "<td class=\"form\">"
}
