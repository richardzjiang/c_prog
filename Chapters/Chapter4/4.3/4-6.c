#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <ctype.h>	/* for isalpha() */

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define VARIABLE '1'	/* signal that a variable was found */
#define VAR_DEFAULT ':'
#define VAR_NO_VALUE '$'	/* popvar(), variable has no value to be popped */

int getop(char []);
void push(double);
double pop(void);
double popvar(char name);
void pushvar(char name, double value);

char varname;	/* when the getop function discovers a letter, it assumes it's a variable. it returns VARIABLE to signal that a variable has been found, and stores the letter into varname */
char varstatus = VAR_NO_VALUE;	/* based on what char is stored in here, can see what the status of the variable. */

/* bugs:
 * in popvar(), i starts at 0, and varindex starts at 0 also. therefore, the while loop won't execute because i won't be less than varindex.
 * (fixed) varstatus has no value when the program starts. therefore, in case VARIABLE, the program will go to the else and try to extract a value from the variable even though it has no value.
 * after assigning a value to a variable that previously had no value, the value of the variable will actually be its name
 * case '=' requires the variables name so that it can be used in pushvar. this means that I pushed the variable's name into the stack. (continued)
 * but this also means that the stack treats this name as a value, and such gives its name as its value
 */

/* reverse Polish calculator */
main()
{
	int type;
	double tmp;
	double op2;
	char s[MAXOP];	/* used in getop(). stores a single operator. operators such as "1.2034" are stored as string form here. */

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));	/* stands for ASCII to floating point */
			break;
		case VARIABLE:
			if (varstatus == VAR_NO_VALUE) {	/* from popvar() */
				printf("error: no value stored in variable\n");
				push(varname);	/* refer to the vartest.c program for confirmation that this works */
			} else {
				tmp = popvar(varname);	/* bug: why does it pop the variable's name */
				printf("DEBUG: popvar(varname) = %f\n", tmp);
				push(tmp);	/* push into the stack the value of the variable */
			}
			break;
		case '=':
			op2 = pop();	/* the number that is gonna be assigned to the variable */
			tmp = pop();	/* although is be a double, should be treated as a char. this char is the name of the variable */
			printf("DEBUG: variable name: %f\n", tmp);
			pushvar((char) tmp, op2);	/* refer to the vartest.c program for confirmation that this works */
			push(op2);
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

	while ((s[0] = c = getch()) == ' ' || c == '\t')	/* skips white spaces. when this loop is done, c is a non-white-space char */
		;
	s[1] = '\0';
	if (!isdigit(c) && !isalpha(c) && c != '.')
		return c;	/* not a number */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (isalpha(c)) {
		varname = c;
		return VARIABLE;
	}
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

char varnames[52];	/* 26 lowercase letters plus 26 uppercase letters is 52 letters */
double varval[52];
int varindex = 0;

double popvar(char name)
{
	int i;

	varstatus = VAR_DEFAULT;

	//if (!isalpha(name))
	//	return 0.0;
	// it's impossible for a name to not be a letter
	for (i = 0; i < varindex; ++i) {
		if (varnames[i] == name)
			return varval[i];
	}
	printf("DEBUG: popvar: i = %d\n", i);
	varstatus = VAR_NO_VALUE;
	return 0.0;
}

void pushvar(char name, double value)
{
	int i;

	printf("DEBUG: pushvar: name = %c\n", name);
	if (!isalpha(name))
		return;
	for (i = 0; i < varindex; ++i) {
		if (varnames[i] == name) {
			varval[i] == value;
			return;
		}
	}
	varnames[varindex] = name;
	varval[varindex] = value;
	++varindex;
}
