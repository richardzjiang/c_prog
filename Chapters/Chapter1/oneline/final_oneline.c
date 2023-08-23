/* this funky program will receive a c program file as input. It will then remove all unnecessary tabs, spaces, and newlines from the program. The result should still be a functioning c program, albeit unreadable for humans */
/* to use, input into the terminal: cat input_file.c | ./oneline > output_file.c */
/* I spent way too much time on this program. This program is much more complicated than just simply removing tabs and newlines */
/* The program can compress itself into one line, which is pretty neat */

#include <stdio.h>

main()
{
	int c;	/* setting c as char will result in an abomination of an output */
	int last;
	int insidequotes;	/* is the program inside of quotes? */
	int insidecomment;
	int specialcomment;
	int singlequotes;
	int specialmode;	/* is the program reading #include or #define (which are special cases where newlines are required)? */
	int nonspecial = 0;		/* for how long was the program not in specialmode? This variable is literally used only one (I couldn't think of an alternative) */
	int whites = 0;	/* how many white space (space, tab, newline) chars were omitted? */
	int comments = 0;	/* how many comments were omitted? */

	insidequotes=0;
	insidecomment=0;
	specialmode=0;
	singlequotes = 0;
	specialcomment = 0;
	for (last='\n'; (c = getchar()) != EOF; last = c) {
	//printf("DEBUG: %d comment: %d, special: %d\n", insidequotes, insidecomment, specialmode);
		if (insidecomment) {
			if (last == '*' && c == '/') {
				insidecomment = 0;
				c = 0;
				++comments;
			}
			continue;
		}

		if (specialcomment) {
			if (c == '\n') {
				specialcomment = 0;
				++comments;
			}
			continue;
		}

		if (singlequotes) {
			if (last == 39 && c != 39)
				singlequotes = 0;
			if (c != '/')	/* because if c is /, then c will be printed again below */
				putchar(c);
			continue;
		}

		if (insidequotes) {
			if (c == '"')
				insidequotes = 0;
			putchar(c);
			continue;
		}

	//printf("\nDEBUG: %c | %c\n", last, c);
		if (c == '/' && last != '/')
			continue;

		if (last == '/') {
			if (c == '*') {
				insidecomment = 1;
				continue;
			}
			if (c == '/') {
				specialcomment = 1;
				continue;
			}
			putchar(last);
		}

		if (c == 39)
			singlequotes = 1;

		if (c == '"')
			insidequotes = 1;

		if (last == '\n' && c == '#') {	/* it's not possible to enter specialmode while inside quotes or comments */
			specialmode = 1;
			if (nonspecial > 1) {
				putchar(last);
				//printf("DEBUG: Last has been put");
			}
			nonspecial = 0;
		}
		else if (specialmode && c == '\n') {
			putchar('\n');
			specialmode = 0;
			continue;
		}

		if (last == ' ' || last == '\t' || last == '\n')
			if (c == last) {
				++whites;
				continue;
			}
		if (c == '\t' || c == '\n') {
			++whites;
			continue;
		}

		if (specialmode == 0)
			++nonspecial;
		putchar(c);
	}
	printf("\nRemoved %d white space chars\nRemoved %d comments\n", whites, comments);

}

/* mostly finished. additional testing for bugs required */
