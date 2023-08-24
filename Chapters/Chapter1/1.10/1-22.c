/* Write a program to "fold" long input lines into two or more shorter liners after the last non-blank character that occurs before the n-th column of input. Make sure your program does osmething intellligent with very long lines, and if there are no blanks or tabs before the specified column. */

#include <stdio.h>
#define FOLDLEN 80

main()
{
	int c;
	int nonblank;	/* last non-blank character read */
	int n = 0;	/* number of chars in a line */
	int blank[FOLDLEN];
	int i = 0;
	int tmp;

	while ((c = getchar()) != EOF) {
		//printf("n = %d\n", n);
		if (c == '\n') {
			putchar(c);
			n = 0;
			i = 0;
			continue;
		}
		++n;
		if (n == FOLDLEN) {
			putchar('\n');
			n = 0;
		}
		if (c != ' ' && c != '\t') {
			nonblank = c;
			for (tmp = 0; tmp < i; ++tmp)
				putchar(blank[tmp]);
			i = 0;
			putchar(c);
			continue;
		}

		blank[i++] = c;	/* i should never exceed FOLDLEN, or there will be problems */
		//printf("DEBUG: i=%d\n", i);
		//printf("blank = %ls\n", blank);
	}
}
