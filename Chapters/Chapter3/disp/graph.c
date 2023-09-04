#include <stdio.h>
#define MAXLEN 50	/* maximum length of equation */
#define MAXDIGITS 20	/* maximum number of digits in a number */
#define TRUE 1
#define FALSE 0
#define HBOUND 50
#define VBOUND 30

int expression[MAXLEN];

void disp(int hbound, int vbound, char input[]/*, int pixelsize*/);
int eval(int a, int b, char operator);
int power(int x, int p);
int reversepolish(int input[]);

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
	int initialized = FALSE;	/* when using scanf, you have to press the enter key in order for scanf to read your input. Unfortunately, getchar() also reads this as a newline, which causes problems */
	int variables[MAXLEN];	/* stores the elements in equation[] that contain variables */
	int v = 0;
	char graph[HBOUND, VBOUND];

	printf("X minimum: ");
	scanf("%d", &xmin);
	printf("X maximum: ");
	scanf("%d", &xmax);
	printf("Y minimum: ");
	scanf("%d", &ymin);
	printf("Y maximum: ");
	scanf("%d", &ymax);

	if ((xmin >= xmax) || (ymin >= ymax)) {
		printf("Error: Invalid boundary\n");
		return 0;
	}
	if (((xmax - xmin) > HBOUND) || ((ymax - ymin) > VBOUND)) {
		printf("Error: Boundary too large\n");
		return 0;
	}
	
	printf("\nUse reverse Polish notation\nOmit the \"y =\" so that an equation like \"y = x + 1\" would be written as \"x 1 +\"\nUse only numbers, operators, spaces, and a single variable or the program will return an error\nEnter the equation to graph: ");

	for (i = 0; (c = getchar()) != EOF; ++i) {
		//printf("DEBUG: started loop\n");
		if (i == MAXLEN) {
			printf("Error: equation is too large\n");
			return 0;
		}
		if (variable != 0) {
			//printf("variable != 0\n");
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
				if (c != variable) {
					//printf("DEBUG: c = %c\n", c);
					//printf("DEBUG: variable = %c\n", variable);
					printf("Error: too many variables\n");
					return 0;
				}
		}

		if (nummode == FALSE)
			if (c >= '0' && c <= '9') {
				nummode = TRUE;
				n = 0;
				initialized = TRUE;
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
				//printf("DEBUG: %d\n", equation[i]);
				++i;
				n = 0;	/* redundant and can be deleted. Already written elsewhere */
			}
			continue;
		}
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			variables[v++] = i;
			equation[i++] = 0;
			//printf("DEBUG: assigned %c to variable\n", c);
			variable = c;
			initialized = TRUE;
			continue;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			equation[i++] = c;
			initialized = TRUE;
		}
		else if (c != ' ' && c != '\n') {	/* spaces are allowed, but will be ignored */	/* entering a newline means that you have finished entering your equation */
			printf("Error: invalid characters\n");
			//printf("DEBUG: c = %d", c);
			return 0;
		}
		if (initialized == TRUE && c == '\n')
			break;	/* entering a newline means that you have finished entering your equation */
	
	}
	equation[i] = '\0';
	//printf("LEFT THE FOR LOOP\n");
	//for (tmp = 0; equation[tmp] < i; ++tmp)
	//	printf("equation[%d] = %d\n", tmp, equation[tmp]);

	
	
	for (i = xmin; i < xmax; ++i) {
		for (tmp = 0; tmp < v; ++tmp)
			equation[variables[tmp]] = xmin;
		copy(equation);
		graph[i-xmin, reversepolish(equation)-ymin] = '%';	/* any char */	/* additional testing needed to confirm that the -xmin and -ymin are correct */
	}
	disp(xmax-xmin, ymax-ymin, graph);
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

int reversepolish(int input[])
{
	int tmp1, tmp2, tmp3;
	int i;

	for (i = strlen(input); i > 0; i -= 2) { 
		tmp1 = pop();
		tmp2 = pop();
		tmp3 = pop();
	
		push(eval(tmp1, tmp2, tmp3));
	}
}

int pop()
int push()

void copy(int input[])
{
	int i;
	extern int expression[MAXLEN];

	for (i = 0; input[i] != '\0'; ++i)
		expression[i] = input[i];
}
