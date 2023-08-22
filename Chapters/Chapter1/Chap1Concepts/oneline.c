/* this funky program will receive a c program file as input. It will then remove all unnecessary tabs, spaces, and newlines from the program. The result should still be a functioning c program, albeit unreadable for humans */
/* to use, input into the terminal: cat input_file.c | ./oneline > output_file.c */

#include <stdio.h>

main()
{
	int c;	/* setting c as char will result in an abomination of an output */
	int last;
	int insidequotes = 0;	/* is the program inside of quotes? */
	int insidecomment = 0;
	//int specialcomment = 0;
	int specialmode = 0;	/* is the program reading #include or #define (which are special cases where newlines are required)? */

	while ((c = getchar()) != EOF) {
		if (last == '/' && c == '*' && insidequotes == 0)
			insidecomment = 1;
		if (last == '*' && c == '/' && insidequotes == 0)
			insidecomment = 0;

		if (!insidequotes && !insidecomment) {
			if (c == '"')
				insidequotes = 1;
		} else if (insidequotes && !insidecomment){
			if (c == '"')
				insidequotes = 0;
		}

		/*if (last == '/' && c != '*')
			putchar(last);*/

		if (insidequotes == 0 && insidecomment == 0 && c == '#')	/* it's not possible to enter specialmode while inside quotes or comments */
			specialmode = 1;

		if (insidecomment == 1) {
			last = c;
			break;
		}
		else if (insidequotes == 1)
			if (c != '\n')
				putchar(c);
		else if (specialmode == 1) {
			if (c != '\n')
				putchar(c);
			else if (c == '\n') {
				putchar(c);
				specialmode == 0;
			}
		} else
			if (c != '\t' && c != '\n') /* comments slash thing */
				putchar(c);

		/* remove spaces if they are consecutive */

		last = c;
	}
	printf("quote: %d comment: %d, special: %d", insidequotes, insidecomment, specialmode);

}
