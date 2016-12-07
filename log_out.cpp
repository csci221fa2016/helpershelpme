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

	Cgicc cgi;
	cout << HTTPHTMLHeader().setCookie(HTTPCookie("user_id","6767","","",-1,"/view/jtoledo",true)).setCookie(HTTPCookie("logged_in","true","","",-1,"/view/jtoledo",true))<<endl;
	cout<< html()<<endl;
	cout<<head()<<title("Redirecting")<<endl;
	cout<<"<META HTTP-EQUIV=\"refresh\" CONTENT=\"5;URL=home.cgi\">"<<endl;
	cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>" << endl;
	cout <<"<link rel=\"stylesheet\" href=\"css/main2.css\" />"<<endl;


	cout << style() << comment() << endl;
	cout << styles;
	cout << comment() << style() <<endl;
	cout << head() << endl;
	cout << "<body class =\"index\">" << endl;
	cout<<"<div id=\"page-wrapper\">"<<endl;
	cout<<"<section id=\"banner\">"<<endl;
	cout<<"<p> Logout successfull, you will be redirected now! If your browser doesn't redirect please click <a href=\"home.cgi\">HERE</a></p>"<<endl;
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
	cout<<body()<<endl;
	cout<<html()<<endl;

}

