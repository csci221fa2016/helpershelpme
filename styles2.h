#ifndef _STYLES_H_
#define _STYLES_H_ 1
#include <string>

const std::string styles =
"#header.alt {\
    background: #fff;\
    color: #000;\
	padding: 1em 2.5em;\
	position: fixed;\
}\
#header.alt nav {\
    right: 2.5em;\
    top: 0.5em;\
	pisition: fixed;\
}\
h1 a, h2 a, h3 a, h4 a, h5 a, h6 a {\
    color: 00;\
    text-decoration: none;\
    border: 0;\
}\
.button {border: 0;outline: none;border-radius: 0;padding:0;font-size: 2rem;font-weight: 600;text-transform: uppercase;letter-spacing: .1em;background: #83d3c9;color: #ffffff;-webkit-transition: all 0.5s ease;transition: all 0.5s ease;-webkit-appearance: none;}\
.button:hover, .button:focus {background: #179b77;}\
.button-block {display: block;width: 100%;}"
;
#endif
