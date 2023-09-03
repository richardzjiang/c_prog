#include <stdio.h>

main()
{
	int v[100];
	int i;
	int x = 6;

	for (i = 0; i < 100; ++i)
		v[i] = i;

	printf("binsearch = %d\nThe correct answer is %d\n", binsearch(x, v, 100), x);
}
