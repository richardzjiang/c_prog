/* Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets, and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) */

#include <stdio.h>
#define MAX 1000	/* maximum number of parentheses/brackets/braces that can be stored */

char corr(char c);

/* contains some code from 1-23.c and final_oneline.c */
main()
{
	int c;
	int brackets[MAX];	/* stores all parentheses/brackets/braces found in input */
	int i = 0;	/* points to the next availabe slot in brackets (and also lines) */
	int line = 1;	/* what line the cursor is currently on */
	int errors[MAX];	/* lines that have syntax errors in them */
	char errorchar[MAX];
	int n = 0;
	int tmp;

	int last;
	int insidecomment;
	int specialcomment;
	int insidequotes;
	int singlequotes;

	insidequotes = 0;
	insidecomment = 0;
	singlequotes = 0;
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

		if (singlequotes) {
			if (last == '\'' && c != '\'')
				singlequotes = 0;
			continue;
		}

		if (insidequotes) {
			if (c == '"')
				insidequotes = 0;
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
		}

		if (c == '\'')
			singlequotes = 1;

		if (c == '"')
			insidequotes = 1;

		if (c == '\n')
			++line;

		if (insidecomment || specialcomment || singlequotes || insidequotes)
			continue;

		if (c == '(' || c == '[' || c == '{') { 
			brackets[i] = c;
			++i;
		}
		if (c == ')' || c == ']' || c == '}') {
			if (brackets[i-1] == corr(c))
				--i;
			else {
				errors[n] = line;
				errorchar[n] = c;
				++n;
				--i;
			}
		}
	}

	errors[n] = '\0';
	if (n > 0) {
		printf("n = %d\n", n);
		for (tmp = 0; tmp < n; ++tmp)
			printf("%d: Unbalanced '%c'. Expected corresponding '%c'.\n", errors[tmp], errorchar[tmp], corr(errorchar[tmp]));
	}
	else
		printf("No errors detected\n");
}

/* corr: return the corresponding parentheses/bracket/brace character */
char corr(char c)
{
	if (c == '(')
		return ')';
	if (c == '[')
		return ']';
	if (c == '{')
		return '}';

	if (c == ')')
		return '(';
	if (c == ']')
		return '[';
	if (c == '}')
		return '{';

	return 0;	
}
