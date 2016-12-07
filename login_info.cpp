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
#include "styles.h"
using namespace std;
using namespace cgicc;

int main () {
	Controller myController;
	Cgicc cgi;
	vector<string> login;
	form_iterator it = cgi.getElement("user_phone_number");  
	if( !it->isEmpty() && it != (*cgi).end()) {  
		login.push_back(**it);      
	}
	it = cgi.getElement("user_password"); 
	if( !it->isEmpty() &&it != (*cgi).end()) {  
		login.push_back(**it);
	}
	//vector<string> login_answer = myController.signIn(login);

	if(login[0]=="4545"&&login[1]=="1234"){
		login.push_back("true");
	}else{
		login.push_back("false");
	}
	if(login[2]=="true") { 
		cout << HTTPHTMLHeader().setCookie(HTTPCookie("user_id","6767")).setCookie(HTTPCookie("logged_in","true"))<<endl;
		cout<< html()<<endl;
		cout<<head()<<title("Redirecting")<<endl;
		cout<<"<META HTTP-EQUIV=\"refresh\" CONTENT=\"0;URL=home.cgi\">"<<endl;
	}else{
		cout << HTTPHTMLHeader();
		cout<<html()<<endl;
		cout << head()<<title("Log in") << endl;

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
	if(login[2]=="true"){
		cout<<"<p> Login successfull, you will be redirected now! If your browser doesn't redirect please click <a href=\"home.cgi\">HERE</a></p>"<<endl;
	}else{
		cout<<"<p>Wrong username or password, click <a href=\"login.cgi\">HERE</a> to try again.</p>"<<endl;
	}
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
		cout << body() <<endl;
		cout << html() <<endl; 

	return 0;
}
