#include <stdio.h>

main()	/* count digits, white space, others */
{
	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			ndigit[c-'0']++;
			break;	/* the break statement causes an immediate exit from switch. After the code for one case is done, execution falls through to the next unless you take explicit action to escape */
		case ' ':
		case '\n':
		case '\t':
			nwhite++;
			break;
		default:
			nother++;
			break;	/* put a break after the last case even though it's logically unnecessary. some day when another case gets added at the end, this will save you */
		}
	}
	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n",
			nwhite, nother);
	return 0;
}
