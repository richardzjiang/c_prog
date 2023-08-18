/* Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (getchar() != EOF)
			putchar('1');	/* if condition getchar() != EOF is true, then it will be 1 and character '1' will be printed. Else, if the condition is not true, the character'0' will be printed */
		else
			putchar('0');
	}
}
