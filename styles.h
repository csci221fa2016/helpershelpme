#ifndef _STYLES_H_
#define _STYLES_H_ 1
#include <string>

const std::string styles =
//TOPNAVIGATION
"#topnav{padding:20px 0; color:#C0BAB6; background-color:#232323; clear:both;}\
#topnav ul{margin:0; padding:0; list-style:none; text-transform:uppercase; font-size:12px;}\
#topnav ul ul{z-index:9999; position:absolute; width:160px; text-transform:none;}\
#topnav ul ul ul, #topnav ul ul ul ul{left:160px; top:0;}\
#topnav ul li:last-child ul, #topnav ul li.last-child ul{right:0;}\
#topnav ul.negative{left:-160px;}\
#topnav li{position:relative; display:block; float:left; margin:0 0 0 30px; padding:0; background-color:red;}\
#topnav li:first-child, #topnav li.first{margin-left:0;}\
#topnav li li{width:100%; margin:0;}\
#topnav li a{display:block; padding:0;}\
#topnav li li a{display:block; margin:0; padding:10px 15px;}\
#topnav ul ul{display:none;}\
#topnav ul li:hover > ul{display:block;}\
#topnav a{color:#C0BAB6; background-color:#232323; font-weight:bold;}\
#topnav li li a, #topnav li.active li a{color:#FFFFFF; background:#000000; font-weight:normal;}\
#topnav li.active a, #topnav a:hover{color:#FF9900; background-color:#232323;}\
#topnav ul li li:hover > a{color:#FFFFFF; background-color:#FF9900;}\
#topnav li a.drop, #topnav li.active a.drop{padding-left:15px; background-position:5px center; background-repeat:no-repeat;}\n"
//NAVIGATION FOR SMALLER RESOLUTIONS
"#topnav form{display:block; height:30px; margin:0 auto; padding:0;}\
#topnav form select{display:block; width:100%; padding:8px; color:#FFFFFF; background-color:#232323; border:1px solid #494949; cursor:pointer; outline:none;}\
#topnav form select option{display:block; margin:10px; padding:0; cursor:pointer; outline:none; border:none;}\n"
//LAYOUT
"html{overflow-y:scroll;}\
body{margin:0; padding:0; font-size:100%; font-family:Georgia, \"Times New Roman\", Times, serif; color:#919191; background-color:#232323;}\
.justify{text-align:justify;}\
.bold{font-weight:bold;}\
.center{text-align:center;}\
.right{text-align:right;}\
.nostart{margin:0; padding:0; list-style:none;}\
.hidden{display:none;}\
.clear{display:block; clear:both;}\
.clear:after{display:block; visibility:hidden; height:0; clear:both; font-size:0; content:"";}\
a{outline:none; text-decoration:none;}\
.fl_left{float:left;}\
.fl_right{float:right;}\
img{width:auto; max-width:100%; height:auto; margin:0; padding:0; border:none; line-height:normal; vertical-align:middle;}\
.imgholder, .imgl, .imgr{padding:4px; border:1px solid #D6D6D6; text-align:center;}\
.imgl{float:left; margin:0 15px 15px 0; clear:left;}\
.imgr{float:right; margin:0 0 15px 15px; clear:right;}\n"

/*----------------------------------------------HTML 5 Overrides-------------------------------------*/
"address, article, aside, figcaption, figure, footer, header, nav, section{display:block; margin:0; padding:0;}\n"
/*----------------------------------------------Responsive Videos-------------------------------------*/
".video{display:block; position:relative; width:100%; height:0; margin:0; padding:0 0 56.25% 0; /* using a 16:9 aspect ratio, the height is 56.25% of the width (9/16=0.5625) */}\
.video iframe{display:block; position:absolute; width:100%; height:100%; margin:0; padding:0;}\n"
/* ----------------------------------------------Wrapper-------------------------------------*/
"div.wrapper{display:block; width:100%; margin:0; padding:0; text-align:left;}\
.row1, .row1 a{color:#C0BAB6; background-color:#333333;}\
.row2{color:#919191; background-color:#232323;}\
.row3{color:#979797; background-color:#FFFFFF;}\
.row3 a{color:#FF9900; background-color:#FFFFFF;}\
.row4, .row4 a{color:#919191; background-color:#232323;}\n"
/*----------------------------------------------Generalise-------------------------------------*/
"h1, h2, h3, h4, h5, h6{margin:0 0 8px 0; padding:0; font-size:1.6em; font-weight:normal; line-height:normal;}\
address{font-style:normal;}\
blockquote, q{display:block; padding:8px 10px; color:#979797; background-color:#ECECEC; font-style:italic; line-height:normal;}\
blockquote:before, q:before{content:'“ '; font-size:26px;}\
blockquote:after, q:after{content:' „'; font-size:26px; line-height:0;}\
#header, #topnav, #container, #footer, #copyright{margin:0 auto; font-size:.8em;}\n"
/*----------------------------------------------Header-------------------------------------*/
"#header{padding:20px 0;}\
#header #hgroup{display:inline-block; float:left; width:auto; clear:right;}\
#header #hgroup h1, #header #hgroup h2{margin:0; font-weight:normal; text-transform:none;}\
#header #hgroup h1{font-size:2.5em;}\
#header #hgroup h2{font-size:1em;}\n"
/*----------------------------------------------Content Area-------------------------------------*/
"#container{padding:30px 0; clear:both;}\n"
/*----------------------------------------------Footer-------------------------------------*/
"#footer{padding:20px 0;}\
#footer p{margin:0; padding:0;}\n"
//RESPONSIVE
"@-ms-viewport{width:device-width;}\n" /* http://msdn.microsoft.com/en-gb/library/ie/hh869615%28v=vs.85%29.aspx */
/* 240 + 320px */
"@media screen and (min-width:240px) and (max-width:360px) {\
	#header, #topnav, #container, #footer{max-width:95%; margin:0 auto;}\
	#topnav ul{display:none;}\
	.one_half,\
	.one_third, .two_third,\
	.one_quarter, .two_quarter, .three_quarter,\
	.one_fifth, .two_fifth, .three_fifth, .four_fifth,\
	.one_sixth, .two_sixth, .three_sixth, .four_sixth, .five_sixth{display:block; float:none; width:auto; margin:0 0 2% 0; padding:0;}\
	#header #hgroup{display:block; width:100%; float:none; margin:0 0 15px 0; padding:0;}\
	#header, #footer{text-align:center;}\
	#footer p{float:none; line-height:1.6em;}\
	#footer p:first-child{margin-bottom:8px;}\
}\n"
/* 480px */
"@media screen and (min-width:361px) and (max-width:600px) {\
	#header, #topnav, #container, #footer{max-width:95%; margin:0 auto;}\
	#topnav ul{display:none;}\
	#footer p{float:none;}\
	#footer p:first-child{margin-bottom:8px;}\
}\n"
/* 768px */
"@media screen and (min-width:601px) and (max-width:800px) {\
	#header, #topnav, #container, #footer{max-width:95%; margin:0 auto;}\
}\n"
/* 960px */
"@media screen and (min-width:960px) {\
	#header, #topnav, #container, #footer{max-width:95%; margin:0 auto;}\
}\n"
/* 1028px */
"@media screen and (min-width:1028px) {\
	#header, #topnav, #container, #footer{max-width:95%; margin:0 auto;}\
}\n"
/* 1200px */
"@media screen and (min-width:1200px) {\
	#header, #topnav, #container, #footer{max-width:1200px; margin:0 auto;}\
}\n"
/* Hide The Jquery Generated Navigation Form from 601px upwards */
"@media screen and (min-width:601px) and (max-width:1920px) {\
	#topnav form{display:none;}\
}\n"
;

#endif
