/* the first version of the oneline program */

#include <stdio.h>

main()
{
	int c;	/* setting c as char will result in an abomination of an output */
	while ((c = getchar()) != EOF) {
		if (c != '\n' && c != '\t')
			putchar(c);
	}
}

