/* Write a function rightrot(x,n) that returns the value of integer x rotated to the right by n bit positions */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

main()
{
	printf("%d\n", rightrot(67, 4));
}

#define UNSIGNEDINT (8 * sizeof(unsigned int))	/* 32 bits */

/* please not that 'unsigned x' has the same meaning as 'unsigned int x' */
/* unsigned ints are 32 bits long */
unsigned rightrot(unsigned x, int n)
{
	unsigned y;

	y = x;
	y = y << (UNSIGNEDINT - n);
	x = x >> n;
	return (x | y);
}
