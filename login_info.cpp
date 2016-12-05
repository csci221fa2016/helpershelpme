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
using namespace std;
using namespace cgicc;

int main () {
	Cgicc cgi;
	HTTPCookie c1;
	cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
	//cout << HTTPRedirectHeader("/view/jtoledo/home.cgi") <<endl;
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<title>Redirecting</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	//<==================================================================CGI DATA PROCESS======================================>	
	vector<string> login;
	//===========================================================Log in==============================================>
	form_iterator it = cgi.getElement("user_phone_number");  
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
	c=:
	cout << "</body>\n";
	cout << "</html>\n";
	
	return 0;
}
