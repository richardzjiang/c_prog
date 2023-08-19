/* Write a program to copy its input to its output, replacing each string of one or more blanks with a single blank. */

#include <stdio.h>

/* a modified version of V2_input2output.c in 1.5.1 */
main()
{
	int c, last, blank;	/* last is the character before the current one, while blank is the blank before the current character (if it exists) */

	while ((c = getchar()) != EOF) {
		if (last == '\n' || last == '\t' || last == ' ')
			blank = last;
		if (c != blank)
		       putchar(c);	
		last = c;
		blank = 0;	/* any value that isn't ascii code */
	}
}
