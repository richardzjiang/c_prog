/* Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int get_line(char line[], int maxline);	/* the name here has been changed to 'get_line' instead of 'getline' in the book, because 'getline' apparently isn't an allowed name */
int reverse(char s[]);


/* print longest input line */
main()
{
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line);
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

/* reverse: reverses the character string */
int reverse(char s[])
{
	int c, i, tmp;

	for (c = 0; s[c] != '\0'; ++c)
		;
	--c;	/* without this, s[c] is '\0', which will cause lots of problems */
	--c;	/* without this, s[c] is '\n', which will result in a strange looking output (which makes sense if you think about it */
	for (i = 0; c > i; --c, ++i) {
		tmp = s[i];
		s[i] = s[c];
		s[c] = tmp;
	}
	return c;
}
