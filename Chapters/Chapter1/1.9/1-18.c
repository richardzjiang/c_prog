/* Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int get_line(char line[], int maxline);	/* the name here has been changed to 'get_line' instead of 'getline' in the book, because 'getline' apparently isn't an allowed name */
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = get_line(line, MAXLINE)) > 0) {
		for (--len; line[len] == '\t' || line[len] == ' '; --len)
			;
		line[++len] = '\n';
		line[++len] = '\0';
		printf("%s", line);
	}
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
