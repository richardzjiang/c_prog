/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount. */

/* the expression x &= (x-1) is equivalent to x = x & (x-1). (x-1) can only modify the rightmost digits of x. If the rightmost two digits were 10, then they become 01. 01 becomes 00, and 11 becomes 10. */
/* if it is 01, then it becomes 00. 00 & 01 is equal to 00, which means that the 1 bit is deleted. If it is 11, it becomes 10, and 11 & 10 is 10, the the 1 bit gets deleted also. */
/* if the rightmost digits of x consists of a 1 followed by an arbitrary number of zeros, then (x-1) has a 0 followed by the same amount of ones. And the result of x & (x-1) in this case is that it seems like the 1 has been replaced by a zero, when comparing the result to x */

#include <stdio.h>

int bitcount(unsigned x);
int bitcount2(unsigned x);

main()
{
	int n;

	scanf("%d", &n);
	printf("bitcount version 1 = %d\n", bitcount(n));
	printf("bitcount version 2 = %d\n", bitcount2(n));
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

/* bitcount: version 2. count 1 bits in x while using x &= (x-1) */
int bitcount2(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= (x-1))
		b++;
	return b;
}
