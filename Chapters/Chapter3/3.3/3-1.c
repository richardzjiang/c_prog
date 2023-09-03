/* Our binary search makes two tests inside of the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside of the loop and measure the difference in run-time. */

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) {	/* to be honest, i'm not sure why changing '<=' to '<' works, but it does */
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else	/* x >= v[mid] */
			low = mid + 1;
	}
	if (mid == x)
		return mid;
	else
		return -1;
}
