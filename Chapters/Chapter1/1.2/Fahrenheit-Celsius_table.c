#include <stdio.h>

/* print Fahrenheit-Celsius table
 	for fahr = 0, 20, ..., 300 */
main()
{
	int fahr, celsius;	/* declaration of variables */
	int lower, upper, step;	/* these variables listed are integers */

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;	/* the variables are integers. integer division truncates: any fractional part is discarded. therefore, multiply by 5 and then divide by 9 instead of multiplying by 5/9 */
		printf("%d\t%d\n", fahr, celsius);	/* the extra tabs before the statements in the while loop are ignored by the c compiler */
		fahr = fahr + step;			/* but proper indentation and spacing are critical in making programs easy for people to read */
	}
}
