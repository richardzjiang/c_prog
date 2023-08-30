/* The conditional expression, written with the ternary operator "?:", provides an alternate way to write if-else and similar constructions */

#include <stdio.h>

main()
{
	int a, b;

	printf("Enter a number: ");
	scanf("%d", &a);

	printf("Enter another number: ");
	scanf("%d", &b);

	printf("%d is larger\n", (a > b) ? a : b);	/* printf("%d is larger\n", max(a, b)); */
}
