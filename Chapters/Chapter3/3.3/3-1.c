#include <stdio.h>

int binsearch(int x, int v[], int n);

main()
{
	int v[100];
	int i;
	int x;

	for (i = 0; i < 100; ++i)
		v[i] = i;

	for (i = 0; i < 100; ++i) {
		x = binsearch(i, v, 100);
		if (x == i)
			printf("\nCORRECT: This is the second version of binsearch: binsearch = %d.\n\n", x);
		else
			printf("\nWRONG: This is the second version of binsearch: binsearch = %d != expected %d.\n\n", x, i);
	}
}
/* Our binary search makes two tests inside of the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside of the loop and measure the difference in run-time. */

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low+high) / 2;
	while (x != v[mid]) {	/* to be honest, i'm not sure why changing '<=' to '<' works, but it does */
		if (x < v[mid])
			high = mid - 1;
		else	/* x >= v[mid] */
			low = mid + 1;	/* low cannot equal mid + 1, because now there is the possibility that x = v[mid] */
		mid = (low+high) / 2;
		printf("DEBUG: low=%d\thigh=%d\tmid=%d\n", low, high, mid);
	}
	if (mid == x)
		return mid;
	else
		return -1;
}
