/* Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers. */

#include <stdio.h>
#include <stdlib.h>	/* for atof() */

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define TRUE 1
#define FALSE 0

int getop(char []);
void push(double);
double pop(void);
void resetvar(void);
void invar(int index, double value);
double outvar(int index);

int lastvar;
/*
		tmp = outvar(c-'a');
		if (tmp < 0)
			return -1;
		n = 0;
		i = 0;
		while (((int) (tmp / pow(10, n+1))) > 0)
			++n;
		printf("DEBUG: tmp = %g\nDEBUG: n = %d\n", tmp, n);
		while (tmp > 0) {
			s[++i] = (int) (tmp / pow(10, n) + '0');
			tmp -= ((int) tmp / pow(10, n)) * pow(10, n);
			--n;
		}


			tmp = getch();
			if(tmp != ' ' && tmp != '\n') {
				ungetch(tmp);
				return c;
			} else
				invar(c-'a', atof(s));
*/
/* reverse Polish calculator */
main()
{
	int type;
	double op1;
	double op2;
	char s[MAXOP];
	int hasvar = FALSE;
	int pos = 2;	/* is the program currently on the first operator or the second operator of an expression? */
	int lastvarpos;

	resetvar();

	while ((type = getop(s)) != EOF) {
		if (pos == 1)
			pos = 2;
		else if (pos == 2)
			pos = 1;

		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			if (hasvar == TRUE) {
				if (lastvarpos == 1) {
					op2 = pop();
					op1 = outvar(lastvar);
					if (op1 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op1);
					push(op2);
				} else {
					op2 = outvar(lastvar);
					if (op2 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op2);
				}
				hasvar = FALSE;
			}
			push(pop() + pop());
			break;
		case '*':
			if (hasvar == TRUE) {
				if (lastvarpos == 1) {
					op2 = pop();
					op1 = outvar(lastvar);
					if (op1 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op1);
					push(op2);
				} else {
					op2 = outvar(lastvar);
					if (op2 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op2);
				}
				hasvar = FALSE;
			}
			push(pop() * pop());
			break;
		case '-':
			if (hasvar == TRUE) {
				if (lastvarpos == 1) {
					op2 = pop();
					op1 = outvar(lastvar);
					if (op1 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op1);
					push(op2);
				} else {
					op2 = outvar(lastvar);
					if (op2 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op2);
				}
				hasvar = FALSE;
			}
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			if (hasvar == TRUE) {
				if (lastvarpos == 1) {
					op2 = pop();
					op1 = outvar(lastvar);
					if (op1 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op1);
					push(op2);
				} else {
					op2 = outvar(lastvar);
					if (op2 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op2);
				}
				hasvar = FALSE;
			}
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			if (hasvar == TRUE) {
				if (lastvarpos == 1) {
					op2 = pop();
					op1 = outvar(lastvar);
					if (op1 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op1);
					push(op2);
				} else {
					op2 = outvar(lastvar);
					if (op2 == 0) {
						printf("error: no value assigned\n");
						break;
					}
					push(op2);
				}
				hasvar = FALSE;
			}
			op2 = pop();
			op1 = pop();
			if (op1 < 0 || op2 < 0) {
				printf("error: negative number\n");
				break;
			}
			push((int) op1 % (int) op2);
			break;
		//case '&':
		case '=':
			invar(lastvar, pop());
			push(0);
			break;
			break;
		case -2:	/* a variable appears */
			hasvar = TRUE;
			lastvarpos = pos;
			break;
		case '\n':
			pos = 2;
			hasvar = FALSE;
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
	int i, c, n;
	double tmp;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && !islower(c) && c != '.')
		return c;	/* not a number or letter(variable) */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (islower(c)) {
		lastvar = c - 'a';
		return -2;
	}

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

double var[26];

/* erase all stored variable values. must do this at beginning of program too */
void resetvar(void)
{
	int i;

	for (i = 0; i < 26; ++i)
		var[i] = 0;
}

/* invar() and outvar() are used for single-letter variables. created to solve the problem of "how do I know if a variable already has a value stored in it?" */
/* extra explanation: all elements of var[] start as 0. invar stores the values in a way so that none will be stored as 0. therefore, if the element is 0, we know that nothing is stored in it */
void invar(int index, double value)
{
	var[index] = ((value <= 0) ? (value - 1) : (value + 1));
}

/* invar() and outvar() are used for single-letter variables. created to solve the problem of "how do I know if a variable already has a value stored in it?" */
double outvar(int index)
{
	if (var[index] == 0)
		return 0;
	return (var[index] < 0) ? (var[index] + 1) : (var[index] - 1);
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
