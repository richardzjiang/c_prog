/* Write a function escape(s,t) that converts characters like newline and tab int visible escape sequence like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters. */

#include <stdio.h>

void escape(char s[], char t[]);

main()
{
	int c;
	int i = 0;
	char t[1000] = "abc	def	ghi	jklmnop\n";
	char s[1000];

	//while ((c = getchar()) != EOF)
	//	t[i++] = c;

	escape(s,t);
	for (i = 0; s[i] != '\0'; ++i)
		printf("%d\n", s[i]);
}

/* escape: convert characters like newline and tab into visible escape sequences like \n and \t as it copies string t to s */
void escape(char s[], char t[])
{
	int i, n;

	i = 0;
	n = 0;
	while ((t[n] != '\0') && (s[i] != '\0')) {
		switch (t[n]) {
			case '\n':
				s[i++] = '\\';
				s[i++] = 'n';
				break;
			case '\t':
				s[i++] = '\\';
				s[i++] = 't';
				break;
			case '\"':
				s[i++] = '\\';
				s[i++] = '"';
				break;
			case '\'':
				s[i++] = '\\';
				s[i++] = '\'';
				break;
			case '\b':
				s[i++] = '\\';
				s[i++] = 'b';
				break;
			case '\r':
				s[i++] = '\\';
				s[i++] = 'r';
				break;
			case '\v':
				s[i++] = '\\';
				s[i++] = 'v';
				break;
			case '\a':
				s[i++] = '\\';
				s[i++] = 'a';
				break;
			default:
				s[i++] = t[n];
				++n;
				break;
		}
	}
	s[i] = '\0';
}
