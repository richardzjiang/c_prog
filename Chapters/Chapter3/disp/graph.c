#include <stdio.h>
#define MAXLEN 50	/* maximum length of equation */
#define MAXDIGITS 20	/* maximum number of digits in a number */
#define TRUE 1
#define FALSE 0


void disp(int hbound, int vbound, char input[]/*, int pixelsize*/);
int eval(int a, int b, char operator);
int power(int x, int p);

main()
{
	int xmin, xmax, ymin, ymax;
	int c;
	int equation[MAXLEN];
	int i;
	char variable = 0;
	int nummode = FALSE;
	int number[MAXDIGITS];
	int n;
	int tmp;

	printf("X minimum: ");
	scanf("%d", &xmin);
	printf("X maximum: ");
	scanf("%d", &xmax);
	printf("Y minimum: ");
	scanf("%d", &ymin);
	printf("Y maximum: ");
	scanf("%d", &ymax);
	putchar('\n');
	
	printf("Use reverse Polish notation\nOmit the \"y =\" so that an equation like \"y = x + 1\" would be written as \"x 1 +\"\nUse only numbers, operators, spaces, and a single variable or the program will return an error\nEnter the equation to graph: ");

	for (i = 0; (c = getchar()) != EOF; ++i) {
		if (i == MAXLEN) {
			printf("Error: equation is too large\n");
			return 0;
		}
		if (variable != 0) {
			if ((c >= 'a' && c <= 'z') || (c <= 'A' && c <= 'z'))
				if (c != variable) {
					printf("Error: too many variables\n");
					return 0;
				}
		}

		if (nummode == FALSE)
			if (c >= '0' && c <= '9') {
				nummode = TRUE;
				n = 0;
				continue;
			}
		if (nummode == TRUE) {
			if (n == MAXDIGITS) {
				printf("Error: too many digits\n");
				return 0;
			}
			if (c >= '0' && c <= '9')
				number[n++] = c;
			else {
				for (equation[i] = 0, tmp = 0; tmp < n; ++tmp)
					equation[i] = equation[i] * 10 + number[tmp];
				nummode = FALSE;
				printf("DEBUG: %d\n", equation[i]);
				++i;
			}
			continue;
		}
		if ((c >= 'a' && c <= 'z') || (c <= 'A' && c <= 'z')) {
			equation[i++] = c;
			variable = c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			equation[i++] = c;
		else if (c != ' ') {	/* spaces are allowed, but will be ignored */
			printf("Error: invalid characters\n");
			return 0;
		}
	
	}


	
	







}

/* disp: print a 2 dimensional output using the input */
void disp(int hbound, int vbound, char input[]/*, int pixelsize*/)
{
	int x, y;

	for (y = 0; y < vbound; ++y) {
		for (x = 0; x < hbound; ++x)
			printf("%c", input[x,y]);
		putchar('\n');
	}
}

/* eval: evaluate an expression that includes a, b, and an operator. the operator is of type char so that it can take input directly from the array (equation[]) */
int eval(int a, int b, char operator)
{
	switch (operator) {
		case ('+'): return (a + b);
		case ('-'): return (a - b);
		case ('*'): return (a * b);
		case ('/'): return (a / b);
		case ('^'): return (power(a, b));
		default: return -1;
	}
}

int power(int x, int p)
{
	while (p-- > 0)
		x *= x;
}
