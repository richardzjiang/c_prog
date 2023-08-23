#include <stdio.h>
#define TABLEN 8
#define TRUE 1
#define FALSE 0

main()
{
	char spaces = 0;	/* how many spaces have been accumulated */
	int i, c;
	int tabmode = FALSE;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			if (tabmode == FALSE)
				putchar(c);
			else if (tabmode == TRUE) {
				for (i = 0; i < spaces; ++i)
					putchar(' ');
				putchar(c);
				spaces = 0;
			}
		}
		else if (c == ' ') {
			++spaces;
			if (spaces == TABLEN) {
				putchar('\t');
				continue;
			}
			if (tabmode == FALSE)
				tabmode = TRUE;
		}
	}
}
