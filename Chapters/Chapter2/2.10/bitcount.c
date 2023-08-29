/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)	/* while it may look like there is only 1 zero before the 1 digit, there are actually 31 zeros, because an unsigned int is 32 bits */
			b++;
	return b;
}
