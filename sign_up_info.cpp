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
#include "controller.h"
#include "styles.h"
using namespace std;
using namespace cgicc;

int main () {
	Controller myController;
	Cgicc cgi;
	//<==================================================================CGI DATA PROCESS======================================>	
	vector<string> signup;
	string full_name;
	//<=========================================Sign Up=========================================>
	const_form_iterator it = cgi.getElement("user_first_name");  
	if(!it->isEmpty() && it != (*cgi).end()) {  
		full_name=**it;	  
	}
	it = cgi.getElement("user_last_name"); 
	if( !it->isEmpty() && it != (*cgi).end()) {  
		full_name=full_name+" "+**it; 
		signup.push_back(full_name);
	}
	it = cgi.getElement("user_phone_number_s"); 
	if( !it->isEmpty() &&it != (*cgi).end()) {  
		signup.push_back(**it);
	}
	it = cgi.getElement("user_password_s"); 
	if( !it->isEmpty() &&it != (*cgi).end()) { 
		signup.push_back(**it);
	}
	
	cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;

	cout<<html()<<endl;
	cout << head()<<title("Log in") << endl;
	int returned_id = myController.sendUser(signup,-1);

	if(returned_id!=0){
		cout<<"<META HTTP-EQUIV=\"refresh\" CONTENT=\"8;URL=login.cgi\">"<<endl;

	}
	cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>" << endl;
	cout <<"<link rel=\"stylesheet\" href=\"css/main2.css\" />"<<endl;
	cout << style() << comment() << endl;
	cout << styles;
	cout << comment() << style() <<endl;
	cout << head() << endl;
	cout << "<body class =\"index\">" << endl;
	cout<<"<div id=\"page-wrapper\">"<<endl;
	cout<<"<section id=\"banner\">"<<endl;

	cout<<"<p> Your full name is:"<<signup[0]<<"</br> Your phone number is:"<<signup[1]<<"</br> Your password is:"<<signup[2]<<"</br>"<<endl;
	//if (returned_id!=0){
		cout<<"<p>You were registered successfully and the user id is: "<<returned_id<<" You will be redirected to the login page,if not click <a href=\"login.cgi\">HERE<a></p>"<<endl;
//	}else{
//		cout<<"<p> Registration was unsuccesfull</p>"<<endl;
//	} 

	cout<<"</section>"<<endl;
	cout<<"<footer id=\"footer\">"<<endl;
	cout<<"<ul class=\"icons\">"<<endl;
	cout<<"<li><a href=\"#\" class=\"icon circle fa-twitter\"><span class=\"label\">Twitter</span></a></li>"<<endl;
	cout<<"<li><a href=\"#\" class=\"icon circle fa-facebook\"><span class=\"label\">Facebook</span></a></li>"<<endl;
	cout<<"<li><a href=\"#\" class=\"icon circle fa-google-plus\"><span class=\"label\">Google+</span></a></li>"<<endl;
	cout<<"<li><a href=\"#\" class=\"icon circle fa-github\"><span class=\"label\">Github</span></a></li>"<<endl;
	cout<<"<li><a href=\"#\" class=\"icon circle fa-dribbble\"><span class=\"label\">Dribbble</span></a></li>"<<endl;
	cout<<"</ul>"<<endl;
	cout<<"<ul class=\"copyright\">"<<endl;
	cout<<"<li>&copy; Helpers Help me</li><li>Design: <a href=\"http://html5up.net\">HTML5 UP</a></li>"<<endl;
	cout<<"</ul>"<<endl;
	cout<<"</footer>"<<endl;
	cout<<"</div>"<<endl;
	cout<<"<script src=\"js/jquery.min.js\"></script>"<<endl;
	cout<<"<script src=\"js/login.js\"></script>"<<endl;
	cout<<"<script src=\"js/jquery.dropotron.min.js\"></script>"<<endl;
	cout<<"<script src=\"js/jquery.scrolly.min.js\"></script>"<<endl;
	cout<<"<script src=\"js/jquery.scrollgress.min.js\"></script>"<<endl;
	cout<<"<script src=\"js/skel.min.js\"></script>"<<endl;
	cout<<"<script src=\"js/util.js\"></script>"<<endl;
	cout<<"<script src=\"js/main.js\"></script>"<<endl;
	cout << "</body>" <<endl;
	cout << html() <<endl; 


	return 0;


}
