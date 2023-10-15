/* C program by Richard Jiang. Given a set of parameters from Wordle, this program will spit out all 5-letter words that match these parameters */
/* original file written on 10/5/2023 */
/* revised file written on 10/14/2023 */
/* note: does not work yet */

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define DEFAULT 1
#define YELLOW 2
#define GREEN 3
#define BLACK 4

void reset();
void setblack(char c);
void setyellow(char c, int pos);
void setgreen(char c, int pos);
int checkstatus(char c, int status, int pos);
char upper(char c);

char black[26];
int blackindex;
int inputstatus[5];
char inputword[5];

main()
{
	int i, pos, tmp;
	char c;
	char word[5];
	int isvalid;
	extern int inputstatus[5];
	extern char inputword[5];

	reset();

	setgreen('L', 1);
	setgreen('K', 5);
	setgreen('Y', 5);
	setyellow('A', 1);
	setblack('B');
	setblack('O');
	setblack('U');
	setblack('T');
	setblack('C');

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			isvalid = TRUE;
			for (tmp = 0; tmp < 5; ++tmp) {
				if (checkstatus(word[tmp], BLACK, 0) == TRUE)
					isvalid = FALSE;
				if (inputstatus[tmp] == GREEN) {
					if (word[tmp] != inputword[tmp])
						isvalid = FALSE;
				}
				if (inputstatus[tmp] == YELLOW) {
					if (word[tmp] == inputword[tmp])
						isvalid = FALSE;
				}
			}
			if (isvalid == TRUE)
				printf("%s\n", word);
			isvalid = TRUE;
			i = 0;
			continue;
		}
		word[i++] = c;
	}
}

void reset()
{
	int i;
	extern int blackindex;
	extern int inputstatus[5];
	extern char inputword[5];

	blackindex = 0;

	for (i = 0; i < 5; ++i) {
		inputstatus[i] = DEFAULT;
		inputword[i] = '\0';
	}
}

void setblack(char c)
{
	extern char black[26];
	extern int blackindex;
	int tmp;

	c = upper(c);

	for (tmp = 0; tmp < blackindex; ++tmp) {
		if (black[tmp] == c)
			break;	/* c does not need to be entered into black[] because it's already there */
	}
	black[blackindex++] = c;
}

void setyellow(char c, int pos)
{
	extern int inputstatus[5];
	extern char inputword[5];

	c = upper(c);

	inputstatus[pos-1] = YELLOW;
	inputword[pos-1] = c;
}

void setgreen(char c, int pos)
{
	extern int inputstatus[5];
	extern char inputword[5];

	c = upper(c);

	inputstatus[pos-1] = GREEN;
	inputword[pos-1] = c;
}

/* the pos is irrelevant if status is BLACK */
int checkstatus(char c, int status, int pos)
{
	extern char black[26];
	extern int inputstatus[5];
	extern char inputword[5];
	int i;

	c = upper(c);

	if (status == BLACK) {
		for (i = 0; i < 26; ++i) {
			if (black[i] == c)
				return TRUE;
		}
		return FALSE;
	} else if (status == YELLOW) {
		if ((inputstatus[pos-1] == YELLOW) && (inputword[pos-1] == c))
			return TRUE;
		return FALSE;
	} else if (status == GREEN) {
		if ((inputstatus[pos-1] == GREEN) && (inputword[pos-1] == c))
			return TRUE;
		return FALSE;
	}
}

/* if the letter is lowercase, return the uppercase version. otherwise, return the unaltered letter */
char upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c += ('A' - 'a');
	return c;
}
