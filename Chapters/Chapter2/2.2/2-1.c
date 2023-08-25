/* Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define CHAR 8
#define INT 32
#define FLOAT 32
#define DOUBLE 64
#define SHORT 16
#define LONG 64

int power(int x, int p);

main()
{
	printf("Datatype lengths in bytes:\n");
	printf("char = %ld bytes\n", sizeof(char));
	printf("int = %ld bytes\n", sizeof(int));
	printf("float = %ld bytes\n", sizeof(float));
	printf("double = %ld bytes\n", sizeof(double));
	printf("short = %ld bytes\n", sizeof(short));
	printf("long = %ld bytes\n", sizeof(long));
	printf("Datatype lengths in bits:\n");
	printf("char = %ld bits\n", 8 * sizeof(char));
	printf("int = %ld bits\n", 8 * sizeof(int));
	printf("float = %ld bits\n", 8 * sizeof(float));
	printf("double = %ld bits\n", 8 * sizeof(double));
	printf("short = %ld bits\n", 8 * sizeof(short));
	printf("long = %ld bits\n", 8 * sizeof(long));

	printf("Unsigned datatype ranges:\n");
	printf("unsigned char = %d - %d\n", 0, (int) pow(2, CHAR));
	printf("unsigned int = %d - %d\n", 0, (int) pow(2, INT));
	printf("unsigned float = %d - %d\n", 0, (int) pow(2, FLOAT));
	printf("unsigned double = %d - %d\n", 0, (int) pow(2, DOUBLE));
	printf("unsigned short = %d - %d\n", 0, (int) pow(2, SHORT));
	printf("unsigned long = %d - %d\n", 0, (int) pow(2, LONG));

	printf("Signed datatype ranges:\n");
	printf("Signed char = %d - %d\n", (int) (-(pow(2, CHAR) / 2)), (int) ((pow(2, CHAR) / 2) - 1));
	printf("Signed int = %d - %d\n", (int) (-(pow(2, INT) / 2)), (int) ((pow(2, INT) / 2) - 1));
	printf("Signed float = %d - %d\n", (int) (-(pow(2, FLOAT) / 2)), (int) ((pow(2, FLOAT) / 2) - 1));
	printf("Signed double = %d - %d\n", (int) (-(pow(2, DOUBLE) / 2)), (int) ((pow(2, DOUBLE) / 2) - 1));
	printf("Signed short = %d - %d\n", (int) (-(pow(2, SHORT) / 2)), (int) ((pow(2, SHORT) / 2) - 1));
	printf("Signed long = %d - %d\n", (int) (-(pow(2, LONG) / 2)), (int) ((pow(2, LONG) / 2) - 1));
}
