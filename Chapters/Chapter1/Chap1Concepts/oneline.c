/* this funky program will receive a c program file as input. It will then remove all unnecessary tabs, spaces, and newlines from the program. The result should still be a functioning c program, albeit unreadable for humans */
/* to use, input into the terminal: cat input_file.c | ./oneline > output_file.c */

#include <stdio.h>

main()
{
	int c;	/* setting c as char will result in an abomination of an output */
	int last;
	int insidequotes;	/* is the program inside of quotes? */
	int insidecomment;
	//int specialcomment = 0;
	int specialmode;	/* is the program reading #include or #define (which are special cases where newlines are required)? */

	insidequotes=0;
	insidecomment=0;
	specialmode=0;
	for (last='\n'; (c = getchar()) != EOF; last = c) {
	//printf("DEBUG: %d comment: %d, special: %d\n", insidequotes, insidecomment, specialmode);
		if (insidecomment) {
			if (last == '*' && c == '/') {
				insidecomment = 0;
				c = 0;
			}
			continue;
		}

		if (insidequotes) {
			if (c == '"')
				insidequotes = 0;
			putchar(c);
			continue;
		}

	//printf("\nDEBUG: %c | %c\n", last, c);
		if (c == '/')
			continue;

		if (last == '/') {
			if (c == '*') {
				insidecomment = 1;
				continue;
			}
			putchar(last);
		}

		if (c == '"')
			insidequotes = 1;

		if (last == '\n' && c == '#')	/* it's not possible to enter specialmode while inside quotes or comments */
			specialmode = 1;
		else if (specialmode && c == '\n') {
			putchar('\n');
			specialmode = 0;
			continue;
		}

		if ((last == ' ' || last == '\t' || last == '\n') &&
		     c == ' ' || c == '\t' || c == '\n')
			continue;

		putchar(c);
	}

}

/* unfinished */
