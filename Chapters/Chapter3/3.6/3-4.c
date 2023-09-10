/* In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs. */
/* the reason that it cannot handle the largest negative number is because this number converted to the positive version exceeds the positive limit of integers */

/* itoa: convert n to characters in s */
/* converts a number to a character string (the inverse of atoi) */
void itoa(int n, char s[])
{
	int i, sign;
	int islarge = 0;	/* possibly the worst solution to solving this problem */

	if ((sign = n) < 0 ) {	/* if n is negative */
		if (n == -(power(2, sizeof(int) - 1))) {
			islarge = 1;
			++n;
			n = -n;
		}
		else
			n = -n;		/* make n positive */
	}
	i = 0;
	do {		/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	if (islarge == 1)
		++s[0];
	reverse(s);
}

int power(int x, int p)
{
	while (p-- > 0)
		x *= x
}
