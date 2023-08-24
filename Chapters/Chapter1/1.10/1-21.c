/* Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank will suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define TABLEN 8

main()
{
	int c;
	int n;		/* how many chars read in line*/
	int pos;	/* position. it is the length of the line read so far, it is distinct from n because tabs can have a length of more than one char */
	int nsp;	/* number of spaces */

	while ((c = getchar()) != EOF) {
		if (c == '\n') {	/* it's a new line. everything restarts */
			n = 0;
			pos = 0;
			for (;nsp > 0; --nsp)	/* this also conveniently makes nsp = 0 */
				putchar(' ');
			putchar(c);
			continue;
		}
		if (c == '\t') {
			++n;
			pos += (TABLEN - (pos % TABLEN));
			putchar(c);
			continue;
		}
		if (c == ' ') {
			++nsp;
			if (((pos + nsp) % TABLEN) == 0) {	/* putting a tab will result in pos being moved to a tab column */
				putchar('\t');
				pos += nsp;
				nsp = 0;
			}
			//printf("DEBUG: nsp=%d\n", nsp);
			continue;
		}
		/* below this point means that c is a char other than space, tab, or newline */
		++pos;
		for (;nsp > 0; --nsp)	/* this also conveniently makes nsp = 0. if c is a normal, non-white char, then nsp is zero */
			putchar(' ');
		putchar(c);
	}
}
