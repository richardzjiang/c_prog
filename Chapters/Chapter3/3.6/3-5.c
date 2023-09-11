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
	int x, p;
	char s[1000];

	printf("Enter number: ");
	scanf("%d", &n);
	printf("Enter base to convert to: ");
	scanf("%d", &b);

	itob(n, s, b);

	//printf("power(8,1) = %d\n", power(8,0));
	printf("%s\n", s);
}

/* itoa: convert n to characters in s */
/* converts a number to a character string (the inverse of atoi) */
void itob(int n, char s[], int b)
{
	int i, sign;
	int islarge = 0;	/* possibly the worst solution to solving this problem */
	int number;
	int digit;
	int tmp;

	//printf("started itob\n");
	//printf("n = %d\n", n);
	//printf("b = %d\n", b);
	if ((sign = n) < 0 )
		n = -n;		/* make n positive */
	i = 0;
	if (sign < 0)
		s[i++] = '-';
	digit = 0;
	tmp = 1;
	while (tmp*b <= n) {
		++digit;
		tmp *= b;
		//printf("power(b, digit) = %d\n", tmp);
	}
	do {
		//printf("digit = %d\npower(b, digit) = %d\nn = %d\n", digit, power(b, digit), n);
		if (power(b, digit) <= n) {
			number = 0;
			while (power(b, digit)*(number+1) <= n)
				++number;
			//printf("number = %d\n", number);
			s[i++] = itoc(number);
			//putchar(itoc(number));
			//printf("putchar number\n");
			n -= power(b, digit) * number;
		} else {
			s[i++] = '0';
			//putchar('0');
		}
		--digit;
	} while (digit >= 0);
	s[i] = '\0';
	//if (islarge == 1)
	//	++s[0];
	//reverse(s);
}

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
