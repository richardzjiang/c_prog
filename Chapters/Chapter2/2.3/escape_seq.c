/* '\ooo' where ooo is one to three octal digits (0...7) */
/* '\xhh' where hh is one or more hexadecimal digits (0...9, a...f, A...f) */

#define VTAB '\013'	/* ASCII vertical tab */
#define BELL '\007'	/* ASCII bell character */

/*
hexadecimal alternative:
#define VTAB '\xb'
#define BELL '\x7'
*/

/*
The complete set of escape sequences:
\a	alert (bell) character
\b	backspace
\f	formfeed
\n	newline
\r	carriage return
\t	horizontal tab
\v	vertical tab
\\	backslash
\?	question mark
\'	single quote
\"	double quote
\ooo	octal number
\xhh	hexadecimal number
*/

/*
string constant:
"I am a string"
empty string:
""
*/
