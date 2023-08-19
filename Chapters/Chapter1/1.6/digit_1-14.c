/* Write a program to print a histogram of the length of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

void histo(int *p, char *lp, int arraylen, int space, int width, char symbol);

/* currently only reads integer digits. a heavily modified version of digithistogram.c */
main()
{
	int c, i, tmp, nwhite, nother;
	int ndigit[10];
	char label[10];	/* yep, the array is a char array and the labels are stored as chars */

	nwhite = nother = 0;
	for (i = 0; i <= 9; ++i) {
		ndigit[i] = 0;	/* makes every element of the array have a value of 0 */
		label[i] = i + '0';	/* makes label[0] have char 0, label[1] have char 1, etc. */
	}

	while ((c = getchar())!= EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	
	histo(ndigit, label, 10, 2, 4, '%');	/* it's very easy to modify the settings of the histogram */
	/* histo(heigh data, label data, array length, space between column, column width, column symbol) */
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
