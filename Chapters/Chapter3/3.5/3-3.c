/* Write a function expand expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally. */

#include <stdio.h>

int chartype(char c);
void escape(char s1[], char s2[]);

main()
{
	int c;
	int i = 0;
	char s1[1000];
	char s2[1000];
	int tmp;

	printf("Do Ctrl-D when you have finished inputting\n");
	while ((c = getchar()) != EOF)
		s1[i++] = c;

	s1[i] = '\0';
	escape(s1, s2);

	//for (tmp = 0; tmp < i; ++tmp)
	//	printf("s2 = %c\n", s2[tmp]);
	
	printf("%s\n", s2);
}

void escape(char s1[], char s2[])
{
	int c;
	int last;
	int lastlast;
	int i, n;

	for (last = 0, lastlast = 0, i = 0, n = 0; ((c = s1[i]) != '\0'); lastlast = last, last = c, ++i) {	/* does lastlast = last execute first or does last = c execute first? */
		if (lastlast >= 'a' && lastlast <= 'z') {
			if (last == '-') {
				if (c >= 'a' && c <= 'z') {
					if (lastlast < c)
						for (++lastlast; lastlast <= c; ++lastlast)
							s2[n++] = lastlast;
					else if (lastlast > c)
						for (++lastlast; lastlast >= c; --lastlast)
							s2[n++] = lastlast;
					continue;
				}
				else {
					putchar('*');
					//putchar(lastlast);
					//putchar(last);
					//continue;
				}
			}
			else {
				//putchar(lastlast);
				//putchar(last);
				//continue;
			}
		}
		if (lastlast >= 'A' && lastlast <= 'Z') {
			if (last == '-') {
				if (c >= 'A' && c <= 'Z') {
					if (lastlast < c)
						for (++lastlast; lastlast <= c; ++lastlast)
							s2[n++] = lastlast;
					else if (lastlast > c)
						for (++lastlast; lastlast >= c; --lastlast)
							s2[n++] = lastlast;
					continue;
				}
				else {
					putchar('*');
					/*
					putchar(lastlast);
					putchar(last);
					continue;*/
				}
			}
			else {/*
				putchar(lastlast);
				putchar(last);
				continue;
			*/}
		}
		if (lastlast >= '0' && lastlast <= '9') {
			if (last == '-') {
				if (c >= '0' && c <= '9') {
					if (lastlast < c)
						for (++lastlast; lastlast <= c; ++lastlast)
							s2[n++] = lastlast;
					else if (lastlast > c)
						for (++lastlast; lastlast >= c; --lastlast)
							s2[n++] = lastlast;
					continue;
				}
				else {
					putchar('*');
					/*
					putchar(lastlast);
					putchar(last);
					continue;
				*/}
			}
			else {/*
				putchar(lastlast);
				putchar(last);
				continue;
			*/}
		}
		//printf("DEBUG: got to end of loop\n");
		/*if (chartype(c) == 1 || chartype(c) == 2 || chartype(c) == 3) {	 if the program detects a letter/number, it won't print anything until it has confirmed that this letter/number is or isn't part of a 'a-z' type group 
			printf("c is a letter or number\n");
			continue;
		}*/
		if (c == '-')
			continue;
		s2[n++] = c;
	}
}

/* chartype: finds out if the char is a lowercase letter, uppercase letter, a number, or something else */
int chartype(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;	/* lowercase letter */
	if (c >= 'A' && c <= 'Z')
		return 2;	/* uppercase letter */
	if (c >= '0' && c <= '9')
		return 3;	/* number */
	return 0;		/* other */
}
