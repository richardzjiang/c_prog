/* Write a program to copy its input to its output, replacing each tab with \t, each backspace with \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. */

#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c != '\t' && c != '\b' && c != '\\')
			putchar(c);
		else if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
	}
}
