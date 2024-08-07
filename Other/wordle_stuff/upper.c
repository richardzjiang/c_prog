/* test the function upper() in wordle.c */

#include <stdio.h>

char upper(char c);

main()
{
	char c;

	scanf("%c", &c);

	c = upper(c);

	printf("c = %c", c);
}

char upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c += ('A' - 'a');
	return c;
}
