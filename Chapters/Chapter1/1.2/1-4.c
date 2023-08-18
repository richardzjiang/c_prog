/* Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

/* print Celsius-Fahrenheit table
	for fahr = 0, 20, ..., 300; floating-point version with heading above the table */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	
	printf("\nCelsius to Fahrenheit conversion table!\n---------------------------------------\n");		/* prints a heading above the table */

	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
