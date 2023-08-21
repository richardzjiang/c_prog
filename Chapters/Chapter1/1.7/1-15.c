/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version that also uses a function */
float F_C(float fahr);

main()
{
	float fahr, celsius;	/* using float instead of int will make the output more accurate. For example, the output can now be -17.8 instead of -17 */
	int lower, upper, step;	/* if an arithmetic operator has one floating-point operand and one integer operand, the integer will be converted to floating-point */

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;	/* fahr is float, while lower is int. Therefore, lower will be converted to float */
	while (fahr <= upper) {		/* due to the use of float, the conversion formula in the next line can be written in a more natural way */
		printf("%3.0f %6.1f\n", fahr, F_C(fahr));		/* %6.1f says that a floating-point number (celsius) is to be printed at least six characters wide, with 1 digit after the decimal point */
		fahr = fahr + step;
	}
}

float F_C(float fahr)
{
	float celsius;

	celsius = (5.0/9.0) * (fahr-32.0);
	
	return celsius;
}
