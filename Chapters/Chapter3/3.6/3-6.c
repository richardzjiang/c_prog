/* Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough. */

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int m)
{
	int i, sign;
	int length = 0;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {		/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
		++length;
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0) {
		s[i++] = '-';
		++length;
	}
	while (length < m) {
		s[i++] = ' ';
		++length;
	}
	s[i] = '\0';
	reverse(s);
}
