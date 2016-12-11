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
#include <cgicc/FormEntry.h>
#include "controller.h"
#include "styles.h"
using namespace std;
using namespace cgicc;

int main () {
	Controller myController;
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();
	vector<string> id;
	const_cookie_iterator iter;
	if(env.getCookieList().empty()){
		id.push_back(" NO COOKIES YET");
		id.push_back(" NO COOKIES YET");
		id.push_back(" NO COOKIES YET");
		id.push_back(" NO COOKIES YET");
	}else{
		for(iter = env.getCookieList().begin(); iter != env.getCookieList().end(); ++iter) {
			id.push_back(iter->getName());
			id.push_back(iter->getValue());
		}

	}
	//getting element from evencreationpage
	vector<FormEntry> info = cgi.getElements();
	vector<string> data_1;
	vector<string> data_2;
	//need this don't delete
	data_2.push_back("1");
	data_2.push_back("3");
	vector<vector<string> > my_event;
	vector<FormEntry>::iterator it;
	int counter =0;
	int vcounter=1;
	for(it=info.begin();it<info.end();it++)
	{
		if(counter>=5){
			if(counter==5){
				my_event.push_back(data_1);
				data_2[0]=**it;
				vcounter=2;
			}else{
				if(vcounter==1){
					data_2[0]=**it;
					vcounter =2;
				}else{
					data_2[1]=**it;
					my_event.push_back(data_2);
					vcounter=1;
				}

			}	
		}else{
			data_1.push_back(**it);	
		}
		counter++;	
	}
	//switching the order for controller
	string temp;
	temp =my_event[0][2];
	for(int i=2;i<4;i++){
		my_event[0][i]=my_event[0][i+1];
	}
	my_event[0][4]=temp;
	//CONTROLLER INTERACTION
	int userID = atoi(id[1].c_str());	
	int controller_response =0;
	//controller response doesn't work
	//controller_response = myController.sendEvent(my_event,userID);		

	//WEBPAGE
	cout << HTTPHTMLHeader();
	cout<<html()<<endl;
	cout << head()<<title("Log in") << endl;
	cout<<"<META HTTP-EQUIV=\"refresh\" CONTENT=\"7;URL=home.cgi\">"<<endl;
	cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>" << endl;
	cout <<"<link rel=\"stylesheet\" href=\"css/main2.css\" />"<<endl;
	cout << style() << comment() << endl;
	cout << styles;
	cout << comment() << style() <<endl;
	cout << head() << endl;
	cout << "<body class =\"index\">" << endl;
	cout<<"<div id=\"page-wrapper\">"<<endl;
	cout<<"<section id=\"banner\">"<<endl;
//<=======================Prnting Vlaues of the vector===========================>
	cout<<"<p>You will be redirected in 7 seconds if not please click <a href=\"home.cgi\">HERE</a></p>"<<endl;
	cout<<"<p>Number of Elements:"<<to_string(counter)<<"</br></p>"<<endl;
	vector<vector<string> >::iterator et;
	int d =0;
	for(et=my_event.begin();et<my_event.end();et++){
		if(d>0){
			cout<<"<p>"<<my_event[d][0]<<"</br></p>"<<endl;
			cout<<"<p>"<<my_event[d][1]<<"</br></p>"<<endl;
			d++;	
		}else if(d==0){
			for(int i=0; i<5;i++){
				cout<<"<p>"<<my_event[0][i]<<"</br></p>"<<endl;
			}
			d++;
		}	
	}
	cout<<"<p> user id ="<<id[1]<<"</br></p>"<<endl;
	cout<<"<p> event id="<<to_string(controller_response)<<"</br></p>"<<endl;
//<=======================FOOTER==========================>
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

