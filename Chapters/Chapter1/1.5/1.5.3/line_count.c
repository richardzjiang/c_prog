#include <stdio.h>

/* count lines in input */
main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')	/* a character written between quotes represents an integer value equal to the numerical value of the character in the machine's character set */
			++nl;
	printf("%d\n", nl);
}
