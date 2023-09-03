#include <stdio.h>

int binsearch(int x, int v[], int n);

main()
{
	int v[100];
	int i;
	int x = 6;

	for (i = 0; i < 100; ++i)
		v[i] = i;

	printf("binsearch = %d\nThe correct answer is %d\n", binsearch(x, v, 100), x);
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)	/* n is the number of elements in the array */
{					/* 'binsearch' means 'binary search' */
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;	/* mid is exactly in the middle between low and high */
		if (x < v[mid])		/* with every iteration of the while loop, the range of elements that x could be in is cut in half */
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1;	/* no match */
}
