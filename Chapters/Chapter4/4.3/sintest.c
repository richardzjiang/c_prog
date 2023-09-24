#include <stdio.h>
#include <math.h>

float dtor(float d);

main()
{
	float n;

	printf("Enter a degree: ");
	scanf("%f", &n);
	printf("sin(%.f) = %f\n", n, sin(dtor(n)));	/* the function sin takes radians input. if i want to give degree input, i have to first convert to rad and then input the result */
}

//#include <math.h>

/* dtor: convert degrees to radians */
float dtor(float d)
{
	return ((d / 180) * M_PI);
}
