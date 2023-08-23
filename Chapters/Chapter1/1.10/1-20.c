/* Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>
#define TABLEN 8

int linelen();
int linenum();

main()
{
	int c;
	int i = 0;	/* number of chars in a line */
	int spaces;

	while ((c = getchar()) != EOF) {
		if (c != '\t' && c != '\n') {	/* normal text */
			putchar(c);
			++i;
		}
		else if (c == '\n') {	/* a new line */
			putchar(c);
			i = 0;
		}
		else {
			for (spaces = TABLEN * (i / TABLEN + 1) - i; spaces > 0; --spaces)
				putchar(' ');
			spaces = 0;
		}
	}

}
