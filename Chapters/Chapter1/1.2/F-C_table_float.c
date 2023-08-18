#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version */
main()
{
	float fahr, celsius;	/* using float instead of int will make the output more accurate. For example, the output can now be -17.8 instead of -17 */
	int lower, upper, step;	/* if an arithmetic operator has one floating-point operand and one integer operand, the integer will be converted to floating-point */

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;	/* fahr is float, while lower is int. Therefore, lower will be converted to float */
	while (fahr <= upper) {		/* due to the use of float, the conversion formula in the next line can be written in a more natural way */
		celsius = (5.0/9.0) * (fahr-32.0);		/* a decimal point in a constant indicates that it is a floating point, so 5.0/9.0 is not truncated */
		printf("%3.0f %6.1f\n", fahr, celsius);		/* %6.1f says that a floating-point number (celsius) is to be printed at least six characters wide, with 1 digit after the decimal point */
		fahr = fahr + step;
	}
}

/* %6.f says that the number is to be six characters wide, %.2f specifies two characters after the decimal point; %f merely says to print the number as a floating point */



/*
 * 	%d		print as decimal integer
 * 	%6d		print as decimal integer, at least 6 characters wide
 * 	%f		print as floating point
 * 	%6f		print as floating point, at least 6 characters wide
 * 	%.2f		print as floating point, 2 characters after decimal point
 * 	%6.2f		print as floating point, at least 6 wide and 2 after decimal point
*/
