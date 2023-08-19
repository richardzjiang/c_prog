/* Write a program to print a histogram of the frequencies of different characters in its input. */

#include <stdio.h>

void histo(int *p, char *lp, int arraylen, int space, int width, char symbol);

/* a heavily modified version of digithistogram.c */
main()
{
	int c, i, tmp, nwhite, nother;
	int ndigit[10];
	char digitlabel[10];	/* yep, the array is a char array and the labels are stored as chars */
	int nupletter[26];
	char upletterlabel[26];
	int nlowletter[26];
	char lowletterlabel[26];
	int blank[2];	/* I think that my histo function only takes a pointer to an array is input unfortunately */
	char blanklabel[2];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i) {
		ndigit[i] = 0;	/* makes every element of the array have a value of 0 */
		digitlabel[i] = i + '0';	/* makes label[0] have char 0, label[1] have char 1, etc. */
	}
	for (i = 0; i < 26; ++i) {
		nupletter[i] = 0;	/* makes every element of the array have a value of 0 */
		upletterlabel[i] = i + 'A';	/* makes label[0] have char 0, label[1] have char 1, etc. */
	}
	for (i = 0; i < 26; ++i) {
		nlowletter[i] = 0;	/* makes every element of the array have a value of 0 */
		lowletterlabel[i] = i + 'a';	/* makes label[0] have char 0, label[1] have char 1, etc. */
	}

	while ((c = getchar())!= EOF) {
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c >= 'A' && c <= 'Z')
			++nupletter[c-'A'];
		else if (c >= 'a' && c <= 'z')
			++nlowletter[c-'a'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}

	blank[0] = nwhite;
	blank[1] = nother;
	blanklabel[0] = 'w';	/* unfortunately, the histo function label code can only print a single char for each label. w stands for 'white' */
	blanklabel[1] = 'o';	/* o stands for 'other' */
	
	histo(ndigit, digitlabel, 10, 2, 4, '%');	/* it's very easy to modify the settings of the histogram */
	/* histo(heigh data, label data, array length, space between column, column width, column symbol) */

	histo(nupletter, upletterlabel, 26, 2, 4, '%');

	histo(nlowletter, lowletterlabel, 26, 2, 4, '%');

	histo(blank, blanklabel, 2, 2, 4, '%');
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
