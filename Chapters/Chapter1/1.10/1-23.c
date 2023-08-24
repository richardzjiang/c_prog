/* Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest. */

#include <stdio.h>
#define TRUE 1
#define FALSE 0


main()
{
	int c, last;
	int insidecomment;
	int specialcomment;
	int insidequotes;

	insidequotes = 0;
	insidecomment = 0;
	specialcomment = 0;
	for (;(c = getchar()) != EOF; last = c) {
		if (insidecomment) {
			if (last == '*' && c == '/') {
				insidecomment = 0;

				c = 0;
				
			}
			continue;
		}

		if (specialcomment) {
			if (c == '\n') {
				specialcomment = 0;
			}
			continue;
		}

		if (insidequotes) {
			if (c == '"')
				insidequotes = 0;
			putchar(c);
			continue;
		}

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

		putchar(c);
	}




		/*
		if (c == '\n')
			specialcomment = FALSE;

		if (c == '"' && !insidequotes)
			insidequotes = 1;
		if (c == '"' && insidequotes)
			insidequotes = 0;

		if (last == '/') {
			if (c == '*')
				insidecomment = TRUE;
			if (c == '/')
				specialcomment = TRUE;
			if (c != '*' && c != '/')
					putchar(last);
		}

		if (c == '/')
			continue;

		if (last == '*' && c == '/') {
			insidecomment = FALSE;
		}

		if (insidecomment || specialcomment
			continue;

		putchar(c);
		printf("insidecomment: %d", insidecomment);
		*/
	
}

