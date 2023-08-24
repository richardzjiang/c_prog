/* Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define TABLEN 8
#define TRUE 1
#define FALSE 0

int linelen();
int linenum();

/* contains some code from Exercise 1-20 */
main()
{
	char spaces = 0;	/* how many spaces have been accumulated */
	int i, c;
	int tabmode = FALSE;

	int n = 0;	/* number of chars in a line */
	int need;	/* number of spaces needed */

	while ((c = getchar()) != EOF) {
		if (c != '\t' && c != '\n')	/* normal text */
			++n;
		else if (c == '\n')	/* a new line */
			n = 0;
		if (tabmode == FALSE)
			need = TABLEN * (n / TABLEN + 1) - n;

		if (c != ' ') {
			if (tabmode == FALSE)
				putchar(c);
			else if (tabmode == TRUE) {
				for (i = 0; i < spaces; ++i)
					putchar(' ');
				putchar(c);
				spaces = 0;
				tabmode = FALSE;
			}
		}
		else if (c == ' ') {
			++spaces;
			if (spaces == need) {
				putchar('\t');
				continue;
			}
			if (tabmode == FALSE)
				tabmode = TRUE;
		}
		//printf("tabmode = %d\n", tabmode);
	}
}
