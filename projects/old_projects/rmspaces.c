/* this program removes all spaces from the beginning of every line */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

main()
{
	int c;
	int mode = FALSE;

	while ((c = getchar()) != EOF) {
		if (mode == TRUE) {
			if (c == ' ')
				continue;
			else
				mode = FALSE;
		}
		if (c == '\n')
			mode = TRUE;
		putchar(c);
	}
}

/* this program makes it easier/faster to use programs that were originally written in VS Code. VS Code tabs are weird, so I have to remove all of them. */
