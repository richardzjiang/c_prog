/* Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is mroe challenging. */

#include <stdio.h>

#define MAXWORD 40
#define IN 1
#define OUT 0
#define BLANK 1

void histo(int *p, char *lp, int arraylen, int space, int width, char symbol);

/* a heavily modified version of digithistogram.c */
main()
{
	int wordlen[MAXWORD];
	char wordlabel[MAXWORD];
	int actualwordlabel[MAXWORD];	/* the actual word label */
	int i, c;
	//char c;	not sure why, but the program doesn't work when c is a char
	int state = OUT;	/* is c currently inside of a word? */
	int length = 0;
	char last = BLANK;

	for (i = 0; i < MAXWORD; ++i) {
		wordlen[i] = 0;		/* set all elements to equal zero */
		wordlabel[i] = ' ';	/* my function can only print a single char for each label, so...I am just gonna not have labels and they will be blank */
	}

	while ((c = getchar()) != EOF) {
		if (last == '\n' || last == '\t' || last == ' ')
			last = BLANK;
		if (c == '\n' || c == '\t' || c == ' ')
			c = BLANK;

		if (last == BLANK && c != BLANK)
			state = IN;
		if (state == IN && last != BLANK) {
			if (c != BLANK)
				++length;
			else if (c == BLANK) {
				if (length < MAXWORD)
					++wordlen[length];
				state = OUT;
				length = 0;
			}
		}
		last = c;
	}

	histo(wordlen, wordlabel, MAXWORD, 2, 4, '%');

	for (i = 0; i < MAXWORD; ++i)
		actualwordlabel[i] = i;
	for (i = 0; i < MAXWORD; ++i) {
		printf("%6d", actualwordlabel[i]);	/* the number six comes from the sum of space and width for the histogram */
	}
}


/* histo: print a vertical histogram */
void histo(int *p, char *lp, int arraylen, int space, int width, char symbol)	/* p points to the array that contains the height data. lp (label pointer) points to the array that contains label data. */
{										/* arraylen is array length. space is number of spaces between columns. width is width of column. symbol is symbol that makes up column */
	int i, max, tmp, tmp2;
	
	max = p[0];								/* there is a char that occurs the most number of times. max is the number of time this char occurs */ 
	for (i = 0; i <= 9; ++i)
		if (max < p[i])
			max = p[i];
	
	for (i = 0; i < arraylen; ++i)						/* you see, the way the histogram thinks is in negative space */
		p[i] = max - p[i];						/* hard to explain, but now the column data is 'for how long do I not print anything until I have to start printing the column?' */
	
	putchar('\n');	/* aesthetic reasons */
	for (i = max; i > 0; --i) {	/* vertical dimension. the vertical and horizontal dimensions create a 2 dimensional output */
		for (tmp = 0; tmp < arraylen; ++tmp) {	/* horizontal dimension */
			for (tmp2 = space; tmp2 > 0; --tmp2)	/* prints the space in between columns */
				putchar(' ');
			if (p[tmp] > 0)		/* if there is still more negative space to print */
				for (tmp2 = width; tmp2 > 0; --tmp2)	/* prints spaces */
					putchar(' ');	/* prints negative space */
			else if (p[tmp] <= 0)	/* if there is no more negative space to print */
				for (tmp2 = width; tmp2 > 0; --tmp2)	/* prints column */
					putchar(symbol);	/* don't print negative space and print column instead */
			--p[tmp];
		}
		putchar('\n');
	}
	for (tmp = arraylen; tmp > 0; --tmp)
		for (tmp2 = space + width; tmp2 > 0; --tmp2)
			putchar('_');
	putchar('\n');
	for (i = 0; i < arraylen; ++i) {
		for (tmp = space; tmp > 0; --tmp)
			putchar(' ');
		putchar(lp[i]);
		for (tmp = (width - 1); tmp > 0; --tmp)
			putchar(' ');
	}
	putchar('\n');
}
