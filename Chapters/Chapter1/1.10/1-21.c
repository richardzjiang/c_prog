/* Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank will suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define TABLEN 8

main()
{
	int c;
	int n;		/* how many chars read in line*/
	int pos;	/* it is the length of the line read so far, it is distinct from n because tabs can have a length of more than one char */
	int nsp;	/* number of spaces */

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			n = 0;
			pos = 0;
			nsp = 0;
			putchar(c);
			continue;
		}
		if (c == '\t') {
			++n;
			if ((TABLEN - (pos % TABLEN)) == 0)
				pos += TABLEN;
			else
				pos += (TABLEN - (pos % TABLEN));
			putchar(c);
			continue;
		}
		if (c == ' ')
			++nsp;	/* no need for putchar(c) here (the putchar(c) at the end of the loop will do it) */
		if (((pos + nsp) % TABLEN) == 0) {	/* putting a tab will result in pos being moved to a tab column */
			putchar('\t');
			pos += nsp;
			continue;
		}
		putchar(c);
	}
}
