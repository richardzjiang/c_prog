#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
	int c;

	while ((c = getchar()) != EOF)	/* the precedence of != is higher than that of =, which necessitates parentheses */
		putchar(c);
}
