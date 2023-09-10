/* Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s. */

#include <stdio.h>

void itob(int n, char s[], int b);
int power(int x, int p);
char itoc(int n);
int reverse(char s[]);

main()
{
	int n;
	int b;
	char s[1000];
	char test[100] = "POTATO\0";

	printf("Enter number: ");
	scanf("%d", &n);
	printf("Enter base to convert to: ");
	scanf("%d", &b);

	itob(n, s, b);

	//reverse(test);
	printf("test = %s\n", test);
	printf("s = %s\n", s);
}

/* itoa: convert n to characters in s */
/* converts a number to a character string (the inverse of atoi) */
void itob(int n, char s[], int b)
{
	int i, sign;
	int islarge = 0;	/* possibly the worst solution to solving this problem */
	int digit;

	printf("started itob\n");
	printf("n = %d\n", n);
	printf("b = %d\n", b);
	if ((sign = n) < 0 )
		n = -n;		/* make n positive */
	i = 0;
	if (sign < 0)
		s[i++] = '-';
	do {
		for (digit = 0; power(b, digit) < n; ++digit) {
			printf("digit = %d\n", digit);
			printf("power(b, digit) = %d\n", power(b, digit));
		}
		s[i++] = itoc(digit);
	} while ((n -= power(b, digit)) > 0);
	s[i] = '\0';
	//if (islarge == 1)
	//	++s[0];
	//reverse(s);
}

int power(int x, int p)
{
	if (p == 0)
		return 0;
	--p;
	while (p-- > 0)
		x *= x;
	return x;
}

char itoc(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	if (n >= 10 && n <= 35)
		return ((n - 10) + 'A');
	return -1;
}

int reverse(char s[])
{
	int c, i, tmp;

	for (c = 0; s[c] != '\0'; ++c)
		;
	--c;
	//--c;
	for (i = 0; c > i; --c, ++i) {
		tmp = s[i];
		s[i] = s[c];
		s[c] = tmp;
	}
	return c;
}
