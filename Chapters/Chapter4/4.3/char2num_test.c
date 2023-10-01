#include <stdio.h>
#include <ctype.h>

main()
{
	int c;

	scanf("%lc", &c);

	if (isupper(c))
		printf("%d\n", c-'A');
	else if (islower(c))
		printf("%d\n", c-'a');
	else
		printf("not a letter\n");
}
