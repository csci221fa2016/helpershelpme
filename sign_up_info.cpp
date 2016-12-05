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
using namespace std;
using namespace cgicc;

int main () {
	Cgicc cgi;
	//cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
	cout << HTTPRedirectHeader("/view/jtoledo/home.cgi") <<endl;
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<title>Redirecting</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	//<==================================================================CGI DATA PROCESS======================================>	
	vector<string> signup;
	string full_name;
	//<=========================================Sign Up=========================================>
	form_iterator it = cgi.getElement("user_first_name");  
	if( !it->isEmpty() && it != (*cgi).end()) {  
		cout <<"<h2>First name: " << **it<<" </h2>" << endl;
		full_name=**it;	  
	}else{
		cout <<"<h2>No text entered for first name</h2>" << endl;  
	}
	it = cgi.getElement("user_last_name"); 
	if( !it->isEmpty() &&it != (*cgi).end()) {  
		cout << "<h2>Last name: " << **it<<" </h2>"<< endl;
		full_name=full_name+" "+**it; 
		signup.push_back(full_name); 
	}else{
		cout << "<h2>No text entered for last name,</h2>" << endl;  
	}
	it = cgi.getElement("user_phone_number_s"); 
	if( !it->isEmpty() &&it != (*cgi).end()) {  
		cout << "<h2>Phone Number: " << **it<<" </h2>"<< endl;  
		signup.push_back(**it);
	}else{
		cout << "<h2>No phone number,</h2>" << endl;  
	}
	it = cgi.getElement("user_password_s"); 
	if( !it->isEmpty() &&it != (*cgi).end()) { 
 		cout << "<h2> Password: " << **it<<" </h2>"<< endl;  
		signup.push_back(**it);
		}else{
		cout << "<h2>No text entered for password</h2>" << endl;  
	}
	cout<<"<p> You full name is/"<<signup[0]<<"/ and phone number/"<<signup[1]<<"/and pass/"<<signup[2]<<"/"<<endl;

	cout << "</body>\n";
	cout << "</html>\n";

	return 0;
}
