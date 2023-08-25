#include <stdio.h>

enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
/* If not all values are specified, unspecified values continue the progression. FEB is 2, MAR is 3, etc. */

main()
{
	putchar(TAB);
	printf("%d\n", JUL);
}
