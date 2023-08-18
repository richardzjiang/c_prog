/*
 * 	read a character
 * 	while (character is not end-of-file indicator)
 * 		output the character just read
 * 		read a character
*/

#include <stdio.h>

/* copy input to output; 1st version */
main()
{
	int c;

	c = getchar();
	while (c != EOF) {	/* the relation operator != means "not equal to" */
		putchar(c);
		c = getchar();
	}
}
