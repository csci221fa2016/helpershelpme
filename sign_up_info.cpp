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
<<<<<<< HEAD
=======

>>>>>>> c7ee0443e6e94f26305582b804965911f948818a
#include "controller.h"

using namespace std;
using namespace cgicc;

int main () {
	Cgicc cgi;
	cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
	//cout << HTTPRedirectHeader("/view/lulu/home.cgi") <<endl;
	cout << html() << head();
	cout << "<title>Redirecting</title>\n";
	cout << head() << body() << endl;
	//<==================================================================CGI DATA PROCESS======================================>	
	vector<string> signup;
	string full_name;
	//<=========================================Sign Up=========================================>
<<<<<<< HEAD
	form_iterator it = cgi.getElement("user_first_name");  
	if( !it->isEmpty() && it != (*cgi).end()) {  
		cout <<"<h2>First name: " << **it<<" </h2>" << endl;
		full_name=**it;	  
=======
    string values;

	const_form_iterator it = cgi.getElement("user_first_name");  
	if(!it->isEmpty() && it != (*cgi).end()) {  
        values = (*it).getStrippedValue();
/*		cout <<"<h2>First name: " << **it<<" </h2>" << endl;
		full_name=**it;	  
>>>>>>> c7ee0443e6e94f26305582b804965911f948818a
	}else{
		cout <<"<h2>No text entered for first name</h2>" << endl;  
	}
	it = cgi.getElement("user_last_name"); 
	if( !it->isEmpty() && it != (*cgi).end()) {  
        values.append(";").append((*it).getStrippedValue());
        signup.push_back(values);
/*		cout << "<h2>Last name: " << **it<<" </h2>"<< endl;
		full_name=full_name+";"+**it; 
		signup.push_back(full_name); */
	}else{
		cout << "<h2>No text entered for last name,</h2>" << endl;  
	}
	it = cgi.getElement("user_phone_number_s"); 
	if( !it->isEmpty() &&it != (*cgi).end()) {  
        values = (*it).getStrippedValue();
        signup.push_back(values);
/*		cout << "<h2>Phone Number: " << **it<<" </h2>"<< endl;  
		signup.push_back(**it);*/
	}else{
		cout << "<h2>No phone number,</h2>" << endl;  
	}
	it = cgi.getElement("user_password_s"); 
	if( !it->isEmpty() &&it != (*cgi).end()) { 
        values = (*it).getStrippedValue();
        signup.push_back(values);
/* 		cout << "<h2> Password: " << **it<<" </h2>"<< endl;  
		signup.push_back(**it);*/
		}else{
		cout << "<h2>No text entered for password</h2>" << endl;  
	}
<<<<<<< HEAD
	cout<<"<p> You full name is/"<<signup[0]<<"/ and phone number/"<<signup[1]<<"/and pass/"<<signup[2]<<"/"<<endl;
*/
        Controller control;
        vector<string> newuser;
        string id;
        int uID;
         const_form_iterator firstname = cgi.getElement("user_first_name");
         if(firstname!= (*cgi).end() && ! firstname->isEmpty())
            newuser.push_back((*firstname).getStrippedValue());

         const_form_iterator pnum = cgi.getElement("user_phone_number_s");
         if(pnum!= (*cgi).end() && ! pnum->isEmpty())
            newuser.push_back((*pnum).getStrippedValue());
         const_form_iterator passw = cgi.getElement("user_password_s");
         if(passw!= (*cgi).end() && ! passw->isEmpty())
            newuser.push_back((*passw).getStrippedValue());

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

        if(uID>=0){
        cout << "Not Possible" << endl;
        } else{
        control.sendUser(newuser,-1);
        }

=======
//	cout<<"<p> You full name is/"<<signup[0]<<"/ and phone number/"<<signup[1]<<"/and pass/"<<signup[2]<<"/"<<endl;

    //-1 if there is no user creating a user. userid if otherwise. sendUser returns
    //the new userid
    Controller c;
    int id = c.sendUser(signup, -1);
    cout << p() << id << p() << endl;
>>>>>>> c7ee0443e6e94f26305582b804965911f948818a

	cout << body() << html() << endl;;

	return 0;
}
