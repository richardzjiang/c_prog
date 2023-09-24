#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
float dtor(float d);

/* reverse Polish calculator */
main()
{
	int type;
	double op1;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:	/* if getop reads a number, type will become equal to NUMBER */
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			op1 = pop();
			if (op1 < 0 || op2 < 0) {
				printf("error: negative number\n");
				break;
			}
			push((int) op1 % (int) op2);
			break;
		case '^':
			op2 = pop();
			op1 = pop();
			if (op1 != 0.0 && op2 != 0.0)
				push(pow(op1, op2));
			else
				printf("undefined: zero to the power of zero\n");
			break;
		case -1:
			break;	/* do absolutely nothing (don't print an error message) */
		case 0:
			push(sin(dtor((float) pop())));
			break;
		case 1:
			push(exp(pop()));
			break;
		case '\n':
			printf("DEBUG: printed result\n");
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* dtor: convert degrees to radians */
float dtor(float d)
{
	return ((d / 180) * M_PI);
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

#define MAXWORD 20

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;
	char test[MAXWORD];
	int n;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	printf("DEBUG: c = %c\n", c);
	s[1] = '\0';
	if (!isdigit(c) && !isalpha(c) &&c != '.')
		return c;	/* not a number (or letter) */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))	/* while loop runs until getch() is no longer a digit */
			;
	n = 0;	/* n actually points to the last occupied slot of test, not the next empty one */
	if (isalpha(c)) {
		test[n++] = c;	/* without this, c's value will be erased by 'c = getch()' */
		while (isalpha(test[n++] = c = getch())) {
			if ((n + 1) > MAXWORD) {
				printf("error: exceeds maximum word size\n");
				return -1;	/* returning -1 basically means to do nothing, not even print an error message */
			}
			if (test[n--] == '\n') {
				ungetch(c);	/* puts test[n] (which is the previous c) into buf[]. next time the getop function is used, c will receive this '\n' instead of a new char from the input */
				printf("DEBUG: ungetched\n");
				return -1;
			}
				
			//if (n > 2)
			//	break;
		}
		test[n] = '\0';
		//if (test[n-1] == '\n')
		//	test[--n] = '\0';
		printf("DEBUG: n = %d\n", n);
		printf("DEBUG: word = %s\n", test);
		if (n != 3) {	/* if the group of letters is not three chars long */
			for (n = 0; test[n+1] != '\0'; ++n)	/* 'test[n+1]' instead of 'test[n] because i don't want to print an error message for newline */
				printf("error: 1 unknown command %c\n", test[n]);
			return -1;
		}
		printf("DEBUG: got to here\n");
		if (test[0] == 's' && test[1] == 'i' && test[2] == 'n') {
			printf("DEBUG: returned sin\n");
			return 0;
		}
		if (test[0] == 'e' && test[1] == 'x' && test[2] == 'p') {
			printf("DEBUG: returned exp\n");
			return 1;
		}
		if (test[0] == 'p' && test[1] == 'o' && test[2] == 'w') {
			printf("DEBUG: returned pow\n");
			return '^';
		}
		for (n = 0; test[n+1] != '\0'; ++n)	/* 'test[n+1]' instead of 'test[n] because i don't want to print an error message for newline */
			printf("error: 2 unknown command %c\n", test[n]);
	}
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void)	/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
