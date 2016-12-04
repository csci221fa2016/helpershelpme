#include <iostream>
#include <vector>
#include <string>
//#include "controller.h"
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "styles.h"
using namespace std;
using namespace cgicc;
int main(int argc, char** argv){
	try{
	Cgicc cgi;
                cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
                cout << html().set("lang", "en").set("dir", "ltr") << endl;
                cout << html() <<endl;                
          	cout << head() << endl;
                cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>" << endl;
                cout << style() << comment() << endl;
                cout << styles;
                cout << comment() << style() <<endl;
		cout << title() << "Home" << title() << endl;
                cout <<"<link rel=\"stylesheet\" href=\"css/main.css\" />"<<endl;
		cout << head() << endl; 
                cout << "<body class=\"index\">" << endl;
			cout<<"<div id=\"page-wrapper\">"<<endl;
			//HEADER
				cout<<"<header id=\"header\" class=\"alt\">"<<endl;
					cout<<"<h1 id=\"logo\"><a href=\"home.cgi\">Helpers Help Me</a></h1>"<<endl;
					cout<<"<nav id=\"nav\">"<<endl;
						cout<<"<ul>"<<endl;
							cout<<"<li class=\"current\"><a href=\"home.cgi\">Welcome</a></li>"<<endl;
							cout<<"<li class=\"submenu\">"<<endl;
								cout<<"<a href=\"#\">Menu</a>"<<endl;
								cout<<"<ul>"<<endl;
									cout<<"<li><a href=\"left-sidebar.html\">Rankings</a></li>"<<endl;
									cout<<"<li><a href=\"right-sidebar.html\">News</a></li>"<<endl;
									cout<<"<li><a href=\"no-sidebar.html\">Donate</a></li>"<<endl;
									cout<<"<li><a href=\"contact.html\">Contact</a></li>"<<endl;
									cout<<"<li class=\"submenu\">"<<endl;
										cout<<"<a href=\"#\">Events</a>"<<endl;
										cout<<"<ul>"<<endl;
											cout<<"<li><a href=\"#\">See All Events</a></li>"<<endl;
											cout<<"<li><a href=\"#\">Upcoming Events</a></li>"<<endl;
											cout<<"<li><a href=\"#\">Closed Events</a></li>"<<endl;
											cout<<"<li><a href=\"#\">New Events</a></li>"<<endl;
											cout<<"<li><a href=\"#\">Past Events</a></li>"<<endl;
										cout<<"</ul>"<<endl;
									cout<<"</li>"<<endl;
								cout<<"</ul>"<<endl;
							cout<<"</li>"<<endl;
							cout<<"<li><a href=\"#\" class=\"button special\">Login in/Sign Up</a></li>"<<endl;
						cout<<"</ul>"<<endl;
					cout<<"</nav>"<<endl;
				cout<<"</header>"<<endl;
			//<!-- Banner -->
				cout<<"<section id=\"banner\">"<<endl;	
					cout<<"<div class=\"inner\">"<<endl;
						cout<<"<header>"<<endl;
							cout<<"<h2>HELPERS HELP ME</h2>"<<endl;
						cout<<"</header>"<<endl;
						cout<<"<p>This is <strong>Twenty</strong>, a free\
						<br />\
						responsive template\
						<br />\
						by <a href=\"http://html5up.net\">HTML5 UP</a>.</p>"<<endl;
						cout<<"<footer>"<<endl;
							cout<<"<ul class=\"buttons vertical\">"<<endl;
								cout<<"<li><a href=\"#main\" class=\"button fit scrolly\">Tell Me More</a></li>"<<endl;
							cout<<"</ul>"<<endl;
						cout<<"</footer>"<<endl;
					cout<<"</div>"<<endl;
				cout<<"</section>"<<endl;
				//<!-- Main -->
				cout<<"<article id=\"main\">"<<endl;

					cout<<"<header class=\"special container\">"<<endl;
						cout<<"<span class=\"icon fa-bar-chart-o\"></span>"<<endl;
						cout<<"<h2>As this is my <strong>twentieth</strong> freebie for HTML5 UP\
						<br />\
						I decided to give it a really creative name.</h2>"<<endl;
						cout<<"<p>Turns out <strong>Twenty</strong> was the best I could come up with. Anyway, lame name aside,\
						<br />\
						it's minimally designed, fully responsive, built on HTML5/CSS3/<strong>skel</strong>,\
						and, like all my stuff,\
						<br />\
						released for free under the <a href=\"http://html5up.net/license\">Creative Commons Attribution 3.0</a> license. Have fun!</p>"<<endl;
					cout<<"</header>"<<endl;
				//<!-- One -->
						cout<<"<section class=\"wrapper style2 container special-alt\">"<<endl;
							cout<<"<div class=\"row 50%\">"<<endl;
								cout<<"<div class=\"8u 12u(narrower)\">"<<endl;
									cout<<"<header>"<<endl;
										cout<<"<h2>Behold the <strong>icons</strong> that visualize what \
											you’re all about. or just take up space. your call bro.</h2>"<<endl;
									cout<<"</header>"<<endl;
									cout<<"<p>Sed tristique purus vitae volutpat ultrices. Aliquam eu elit eget\
										 arcu comteger ut fermentum lorem. Lorem ipsum dolor sit amet. Sed\
										 tristique purus vitae volutpat ultrices. eu elit eget commodo. Sed\
										 tristique purus vitae volutpat ultrices. Aliquam eu elit eget arcu\
										 commodo.</p>"<<endl;
									cout<<"<footer>"<<endl;
										cout<<"<ul class=\"buttons\">"<<endl;
											cout<<"<li><a href=\"#\" class=\"button\">Find Out More</a></li>"<<endl;
										cout<<"</ul>"<<endl;
									cout<<"</footer>"<<endl;
								cout<<"</div>"<<endl;
								cout<<"<div class=\"4u 12u(narrower) important(narrower)\">"<<endl;
									cout<<"<ul class=\"featured-icons\">"<<endl;
										cout<<"<li><span class=\"icon fa-clock-o\"><span class=\"label\">Feature 1</span></span></li>"<<endl;
										cout<<"<li><span class=\"icon fa-volume-up\"><span class=\"label\">Feature 2</span></span></li>"<<endl;
										cout<<"<li><span class=\"icon fa-laptop\"><span class=\"label\">Feature 3</span></span></li>"<<endl;
										cout<<"<li><span class=\"icon fa-inbox\"><span class=\"label\">Feature 4</span></span></li>"<<endl;
										cout<<"<li><span class=\"icon fa-lock\"><span class=\"label\">Feature 5</span></span></li>"<<endl;
										cout<<"<li><span class=\"icon fa-cog\"><span class=\"label\">Feature 6</span></span></li>"<<endl;
									cout<<"</ul>"<<endl;
								cout<<"</div>"<<endl;
							cout<<"</div>"<<endl;
						cout<<"</section>"<<endl;
					//<!-- Two -->
						cout<<"<section class=\"wrapper style1 container special\">"<<endl;
							cout<<"<div class=\"row\">"<<endl;
								cout<<"<div class=\"4u 12u(narrower)\">"<<endl;
									cout<<"<section>"<<endl;
										cout<<"<span class=\"icon featured fa-check\"></span>"<<endl;
										cout<<"<header>"<<endl;
											cout<<"<h3>This is Something</h3>"<<endl;
										cout<<"</header>"<<endl;
										cout<<"<p>Sed tristique purus vitae volutpat ultrices. Aliquam eu elit\
											 eget arcu commodo suscipit dolor nec nibh. Proin a ullamcorper\
											 elit, et sagittis turpis. Integer ut fermentum.</p>"<<endl;
									cout<<"</section>"<<endl;
							cout<<"</div>"<<endl;
							cout<<"<div class=\"4u 12u()\">"<<endl;
								cout<<"<section>"<<endl;
									cout<<"<span class=\"icon featured fa-check\"></span>"<<endl;
									cout<<"<header>"<<endl;
										cout<<"<h3>Also Something</h3>"<<endl;
									cout<<"</header>"<<endl;
									cout<<"<p>Sed tristique purus vitae volutpat ultrices. Aliquam eu elit\
										 eget arcu commodo suscipit dolor nec nibh. Proin a ullamcorper\
										 elit, et sagittis turpis. Integer ut fermentum.</p>"<<endl;
								cout<<"</section>"<<endl;
							cout<<"</div>"<<endl;
							cout<<"<div class=\"4u 12u(narrower)\">"<<endl;
								cout<<"<section>"<<endl;
									cout<<"<span class=\"icon featured fa-check\"></span>"<<endl;
									cout<<"<header>"<<endl;
										cout<<"<h3>Probably Something</h3>"<<endl;
									cout<<"</header>"<<endl;
									cout<<"<p>Sed tristique purus vitae volutpat ultrices.\
										 Aliquam eu elit eget arcu commodo suscipit dolor \
										nec nibh. Proin a ullamcorper elit, et sagittis\
										 turpis. Integer ut fermentum.</p>"<<endl;
								cout<<"</section>"<<endl;
							cout<<"</div>"<<endl;
						cout<<"</div>"<<endl;
					cout<<"</section>"<<endl;
				//<!-- Three -->
					cout<<"<section class=\"wrapper style3 container special\">"<<endl;
						cout<<"<header class=\"major\">"<<endl;
							cout<<"<h2>Next look at this <strong>cool stuff</strong></h2>"<<endl;
						cout<<"</header>"<<endl;
						cout<<"<div class=\"row\">"<<endl;
							cout<<"<div class=\"6u 12u(narrower)\">"<<endl;
								cout<<"<section>"<<endl;
									cout<<"<a href=\"#\" class=\"image featured\"><img src=\"images/pic01.jpg\" alt=\"\" /></a>"<<endl;
									cout<<"<header>"<<endl;
										cout<<"<h3>A Really Fast Train</h3>"<<endl;
									cout<<"</header>"<<endl;
									cout<<"<p>Sed tristique purus vitae volutpat commodo suscipit amet sed nibh.\
										 Proin a ullamcorper sed blandit. Sed tristique purus vitae volutpat\
										 commodo suscipit ullamcorper sed blandit lorem ipsum dolore.</p>"<<endl;
								cout<<"</section>"<<endl;
							cout<<"</div>"<<endl;
							cout<<"<div class=\"6u 12u(narrower)\">"<<endl;
								cout<<"<section>"<<endl;
									cout<<"<a href=\"#\" class=\"image featured\"><img src=\"images/pic02.jpg\" alt=\"\" /></a>"<<endl;
									cout<<"<header>"<<endl;
										cout<<"<h3>An Airport Terminal</h3>"<<endl;
									cout<<"</header>"<<endl;
									cout<<"<p>Sed tristique purus vitae volutpat commodo suscipit amet sed nibh. Proin\
										 a ullamcorper sed blandit. Sed tristique purus vitae volutpat commodo\
										 suscipit ullamcorper sed blandit lorem ipsum dolore.</p>"<<endl;
								cout<<"</section>"<<endl;
							cout<<"</div>"<<endl;
						cout<<"</div>"<<endl;
						cout<<"<div class=\"row\">"<<endl;
							cout<<"<div class=\"6u 12u()\">"<<endl;
								cout<<"<section>"<<endl;
									cout<<"<a href=\"#\" class=\"image featured\"><img src=\"images/pic03.jpg\" alt=\"\" /></a>"<<endl;
									cout<<"<header>"<<endl;
										cout<<"<h3>Hyperspace Travel</h3>"<<endl;
									cout<<"</header>"<<endl;
									cout<<"<p>Sed tristique purus vitae volutpat commodo suscipit amet sed nibh. Proin a\
										 ullamcorper sed blandit. Sed tristique purus vitae volutpat commodo suscipit\
										 ullamcorper sed blandit lorem ipsum dolore.</p>"<<endl;
								cout<<"</section>"<<endl;
							cout<<"</div>"<<endl;
							cout<<"<div class=\"6u 12u(narrower)\">"<<endl;
								cout<<"<section>"<<endl;
									cout<<"<a href=\"#\" class=\"image featured\"><img src=\"images/pic04.jpg\" alt=\"\" /></a>"<<endl;
									cout<<"<header>"<<endl;
										cout<<"<h3>And Another Train</h3>"<<endl;
									cout<<"</header>"<<endl;
									cout<<"<p>Sed tristique purus vitae volutpat commodo suscipit amet sed nibh. Proin a\
										 ullamcorper sed blandit. Sed tristique purus vitae volutpat commodo suscipit\
										 ullamcorper sed blandit lorem ipsum dolore.</p>"<<endl;
								cout<<"</section>"<<endl;
							cout<<"</div>"<<endl;
						cout<<"</div>"<<endl;
						cout<<"<footer class=\"major\">"<<endl;
							cout<<"<ul class=\"buttons\">"<<endl;
								cout<<"<li><a href=\"#\" class=\"button\">See More</a></li>"<<endl;
							cout<<"</ul>"<<endl;
						cout<<"</footer>"<<endl;
					cout<<"</section>"<<endl;
			cout<<"</article>"<<endl;
			//<!-- CTA -->
			cout<<"<section id=\"cta\">"<<endl;
				cout<<"<header>"<<endl;
					cout<<"<h2>Ready to do <strong>something</strong>?</h2>"<<endl;
					cout<<"<p>Proin a ullamcorper elit, et sagittis turpis integer ut fermentum.</p>"<<endl;
				cout<<"</header>"<<endl;
				cout<<"<footer>"<<endl;
					cout<<"<ul class=\"buttons\">"<<endl;
						cout<<"<li><a href=\"#\" class=\"button special\">Take My Money</a></li>"<<endl;
						cout<<"<li><a href=\"#\" class=\"button\">LOL Wut</a></li>"<<endl;
					cout<<"</ul>"<<endl;
				cout<<"</footer>"<<endl;
			cout<<"</section>"<<endl;

		//<!-- Footer -->
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
	//"<!-- Scripts -->
		cout<<"<script src=\"js/jquery.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/jquery.dropotron.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/jquery.scrolly.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/jquery.scrollgress.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/skel.min.js\"></script>"<<endl;
		cout<<"<script src=\"js/util.js\"></script>"<<endl;
		cout<<"<script src=\"js/main.js\"></script>"<<endl;
		cout << body() <<endl;
                cout << html() <<endl;	
	} catch(exception& e) {
	}
}
