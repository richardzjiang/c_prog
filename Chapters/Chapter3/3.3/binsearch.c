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
