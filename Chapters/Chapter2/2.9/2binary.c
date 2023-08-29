/* octals and hexadecimals can be easily converted to binary because 8 and 16 are powers of 2 */
/* each octal digit correspondes to three digits in binary. therefore, an octal number 0177 would be equivalent to 000001111111 in binary. if I write it in a different way: 000-001-111-111, each group of three numbers if equivalent to an octal digit */
/* each hexadecimal digit correspondes to four digits in binary. therefore, a hexadecimal number 0123 would be equivalent to 00000001001000110100 in binary. 0000-0001-0010-0011-0100 */

#include <stdio.h>

int base(int input, int basein, int baseout);
int power(int x, int p);

main()
{
	int c;
	int choice;

	scanf("%d", &c);	/* not final code, only to check if the function works */
	printf("%d\n", base(c, 8, 2));	/* same as the above line */

	/*
	printf("Convert octals and hexadecimals to binary!\n");
	printf("__________________________________________\n");
	printf("1: Octal\n");
	printf("2: Hexadecimal\n");
	printf("Enter the number: \n");
	while (choice != 1 && choice != 2)
		scanf("%d", &choice);
	while ((c = getchar()) != EOF) {
		if (choice == 1)
		*/

}

#define MAXNUMLENGTH 100
/* base: convert a number of a one base to another base */
int base(int input, int basein, int baseout)
{
	int inputstring[MAXNUMLENGTH];
	int i;
	int digits = 0;	/* number of digits in input number */
	int decimal;	/* the input number converted to base 10 (decimal) */

	/* also add something that checks if the input number contains a digit that doesn't make sense for the input base */
	for (i = 0; input > 0; i++) {
		if (i < MAXNUMLENGTH) {
			inputstring[i] = (input - ((input / 10) * 10));
			input /= 10;
			++digits;
		} else
			return -1;
	}

	for (decimal = 0; digits > 0; --digits)
		decimal += inputstring[digits] * power(basein, digits);

	return decimal;	/* function unfinished, this is only to check if the first half works */
}

int power(int x, int p)
{
	for (; p > 0; --p)
		x *= x;
}
