/* How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

/* In order to test the program, I would have to input various sentences of words and check if the program will give the correct output. Some inputs that most likely will uncover bugs are inputs that are empty and contain no characters, or inputs that contain special characters, or inputs that are very long */

#include <stdio.h>

#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

/* count lines, words, and characters in input */
main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;	/* all three variables set to zero */
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')	/* the operator || means OR */
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
