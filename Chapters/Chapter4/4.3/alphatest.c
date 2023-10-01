/* test the isalpha(), isupper(), and islower() functions in ctype.h */

#include <stdio.h>
#include <ctype.h>

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			continue;	/* because I don't want the program to read newline */
		if (!isalpha(c)) {
			printf("%c is not alpha\n", c);
			continue;
		}
		if (isalpha(c))
			printf("%c is alpha\n", c);
		if (isupper(c))
			printf("%c is uppercase\n", c);
		if (islower(c))
			printf("%c is lowercase\n", c);
	}
}
