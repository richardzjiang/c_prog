/* this is a correct power function. incorrect power functions may be the root of bugs that I cannot find */
int power(int x, int p)
{
	int tmp;
	if (p == 0) {
		return 1;
	}
	//--p;
	for (tmp = x; p > 1; --p)
		x *= tmp;
	return x;
}
