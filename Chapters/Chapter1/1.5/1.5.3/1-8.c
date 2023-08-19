/* Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

/* counts blanks (spaces), tabs, and newlines */
main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++nl;
		else if (c == ' ')
			++nl;
	}
	printf("%d\n", nl);
}
