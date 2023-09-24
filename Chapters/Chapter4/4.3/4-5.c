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
		case 0:
			push(sin(dtor((float) pop())));
			break;
		case 1:
			push(exp(pop()));
			break;
		case '\n':
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

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;
	char test[3]; /* sin, exp, and pow only have three letters. thus, the number here is three because only three elements are needed */
	int n;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && !isalpha(c) &&c != '.')
		return c;	/* not a number (or letter) */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))	/* while loop runs until getch() is no longer a digit */
			;
	n = 0;	/* n actually points to the last occupied slot of test, not the next empty one */
	if (isalpha(c)) {	/* identified error: the 'word' that is collected by test[] is shifted right by one char */
		test[n++] = c;	/* without this, c's value will be erased by 'c = getch()' */
		while (isalpha(test[n++] = c = getch())) {
			if (n > 2)	/* the group of letters exceeds three characters. therefore, it cannot be sin, exp or pow */
				break;
		}
		test[n] = '\0';
		if (n < 2 || n > 3) {
			for (n = 0; test[n] != '\0'; ++n)
				printf("error: n < 2 || n > 3: unknown command %c\n", test[n]);
			return c;
		}
		if (test[0] == 's' && test[1] == 'i' && test[2] == 'n') {
			return 0;
		}
		if (test[0] == 'e' && test[1] == 'x' && test[2] == 'p') {
			return 1;
		}
		if (test[0] == 'p' && test[1] == 'o' && test[2] == 'w') {
			return '^';
		}
		for (n = 0; test[n] != '\0'; ++n)
			printf("error: not sin, exp, pow: unknown command %c\n", test[n]);
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
