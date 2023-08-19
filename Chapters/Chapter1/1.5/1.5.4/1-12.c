/* Write a program that prints its input one word per line. */

#include <stdio.h>

/* a modified version of V2_input2output.c in 1.5.1 */
main()
{
	int c;

	while ((c = getchar()) != EOF)
		if (c != ' ' && c != '\n' && c != '\t')		/* these characters signify the end of the word */
			putchar(c);
		else			/* if c is the end of the word, then instead '\n' is printed so that only one word is printed per line */
			putchar('\n');
}
