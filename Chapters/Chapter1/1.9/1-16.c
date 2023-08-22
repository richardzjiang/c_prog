/* Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, as as much possible of the test. */

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int get_line(char line[], int maxline);	/* the name here has been changed to 'get_line' instead of 'getline' in the book, because 'getline' apparently isn't an allowed name */
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	int i;
	int newline = 0;
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		for (i = 0; i < MAXLINE; ++i)	/* if there is no '\n' (line is too long) then i will stop at MAXLINE */
			if (line[i] == '\n') break;
		if (i == MAXLINE) {
			printf("The line was too long\n");
			newline = 1;
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)	/* there was a line */
		printf("%s", longest);
	if (newline == 1)
		putchar('\n');
	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
