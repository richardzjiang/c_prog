/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged. */

#include <stdio.h>

//unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
	printf("%d\n", setbits(67, 2, 4, 43));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	x = x | (((1 << n) - 1) << p);
	return (x & (~(~(y | (~0 << n)) << p)));
}

/*
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
*/
