#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  
#include <cgicc/HTTPRedirectHeader.h>
#include <cgicc/HTTPCookie.h>

#include "controller.h"

using namespace std;
using namespace cgicc;

int main () {
    Cgicc cgi;
    HTTPCookie c1;
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
 //   cout << HTTPRedirectHeader("/home.cgi") <<endl;
 //   cout << HTTPRedirectHeader("/view/lulu/home.cgi") <<endl;
//    cout << HTTPRedirectHeader("/view/isarmien/home.cgi") <<endl;
//    cout << HTTPRedirectHeader("/view/jtoledo/home.cgi") <<endl;
    cout << html() << head() << endl;
    cout << "<title>Redirecting</title>\n";
    cout << head() << body() << endl;
    //<==================================================================CGI DATA PROCESS======================================>    
    //retrieves form information and sends it to controller
/*    vector<string> loginfo;
    Controller control;
    const_form_iterator phoneNum = cgi.getElement("user_phone_number");
    if(phoneNum != (*cgi).end() && !phoneNum->isEmpty())
        loginfo.push_back((*phoneNum).getStrippedValue());
    const_form_iterator pw = cgi.getElement("user_password");
    if(pw != (*cgi).end() && !pw->isEmpty())
       loginfo.push_back((*pw).getStrippedValue());
    vector<string> success = control.signIn(loginfo);
    cout << success[0] << success[1] << "I showed up!" << endl;
    if(success[0] == "true") {
       string val;
       val.append(success[0]).append(";").append(success[1]);
//       c.setValue(val);
        cout << HTTPRedirectHeader("/view/lulu/home.cgi") <<endl;
        //cout << HTTPRedirectHeader("/view/isarmien/home.cgi") <<endl;
        //cout << HTTPRedirectHeader("/home.cgi") <<endl;
    } else {
        cout << "<p> Username or Password Invalid </p>" << endl;
        cout << head() << "<meta http-equiv=\"refresh\" content=\"0; /view/lulu/login.cgi\" />" << head() << endl;
    }*/

        Controller control;
        vector<string> user;
//        string id;
//        int uID;
         const_form_iterator pnum = cgi.getElement("user_phone_number");
         if(pnum!= (*cgi).end() && ! pnum->isEmpty())
            user.push_back((*pnum).getStrippedValue());
         const_form_iterator passw = cgi.getElement("user_password");
         if(passw!= (*cgi).end() && ! passw->isEmpty())
            user.push_back((*passw).getStrippedValue());

	    vector<string> success = control.signIn(user);
        cout << success[0] << success[1] << endl;



    //===========================================================Log in==============================================>
 /*   form_iterator it = cgi.getElement("user_phone_number");  
    if( !it->isEmpty() && it != (*cgi).end()) {  
        cout <<"<h2>Phone Number:: " << **it<<" </h2>" << endl;
        login.push_back(**it);      
    }else{
        cout <<"<h2>No text entered for first name</h2>" << endl;  
    }
    it = cgi.getElement("user_password"); 
    if( !it->isEmpty() &&it != (*cgi).end()) {  
        cout << "<h2>Last name: " << **it<<" </h2>"<< endl;
        login.push_back(**it);
        }else{
        cout << "<h2>No text entered for last name,</h2>" << endl;  
    }
    cout<<"<p> Your phone number is /"<<login[0]<<"/ and yourt password is /"<<login[1]<<"/</p>"<<endl;
//    c=:*/
    cout << "</body>\n";
    cout << "</html>\n";
    
    return 0;
}
