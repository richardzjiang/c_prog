/* Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	printf("%d\n", invert(67, 2, 4));
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned y;
	y = x;
	x = x | (((1 << n) - 1) << p);
	y = y >> p;
	return (x & (~(~(~y | (~0 << n)) << p)));
}
