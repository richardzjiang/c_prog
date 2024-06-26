/* C program by Richard Jiang. Given a set of parameters from Wordle, this program will spit out all 5-letter words that match these parameters */
/* Written on 10/5/2023 */
/* note: does not work yet */

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define BLACK 0
#define WHITE 1
#define YELLOW 2
#define GREEN 3

void reset();
void setletter(char c, int status);
int checkstatus(char c, int status);

int alphabet[26];
int green[5];

main()
{
	int c, nextchar, i, pos, tmp, tmp2;
	char word[6];
	extern int green[5];
	int isvalid;

	word[5] = '\0';
	isvalid = TRUE;
	reset();

	printf("Enter all letters that are black.\nCapitalization is ignored.\nEnter the number zero to stop.\n");
	while (1) {
		printf("Enter letter: ");
		scanf("%d", &c);
		if (c == 0)
			break;
		setletter(c, BLACK);
	}

	printf("Enter all letters that are yellow.\nCapitalization is ignored.\nEnter the number zero to stop.\n");
	while (1) {
		printf("Enter letter: ");
		scanf("%d", &c);
		if (c == 0)
			break;
		setletter(c, YELLOW);
	}

	printf("Enter all letters that are GREEN. Also enter the position. \nCapitalization is ignored.\nEnter the number zero for the letter to stop.\n");
	while (1) {
		printf("Enter letter: ");
		scanf("%d", &c);
		if (c == 0)
			break;
		printf("Enter position (a number from 1 to 5): ");
		scanf("%d", &pos);
		green[pos] = TRUE;
		setletter(c, GREEN);
	}

	i = 0;
	c = 0;
	while ((nextchar = getchar()) != EOF) {
		if (c == '\n') {
			i = 0;
			continue;
		}
		if (i == 5 && nextchar == '\n') {
			for (tmp = 0; tmp < 5; ++tmp) {
				if (green[tmp] == TRUE) {
					if (!checkstatus(word[tmp], GREEN))
						isvalid = FALSE;
					else
						word[tmp] = 0;
				} else
					continue;
			}
			for (tmp = 0; tmp < 26; ++tmp) {
				if (checkstatus(tmp + 'A', YELLOW)) {
					if (!(word[0] == (tmp + 'A') || word[1] == (tmp + 'A') || word[2] == (tmp + 'A') || word[3] == (tmp + 'A') || word[4] == (tmp + 'A') || word[0] == (tmp + 'a') || word[1] == (tmp + 'a') || word[2] == (tmp + 'a') || word[3] == (tmp + 'a') || word[4] == (tmp + 'a')))
						isvalid = FALSE;
					else {
						if (word[0] == (tmp + 'A'))
							word[0] == 0;
						if (word[1] == (tmp + 'A'))
							word[1] == 0;
						if (word[2] == (tmp + 'A'))
							word[2] == 0;
						if (word[3] == (tmp + 'A'))
							word[3] == 0;
						if (word[4] == (tmp + 'A'))
							word[4] == 0;
						if (word[0] == (tmp + 'a'))
							word[0] == 0;
						if (word[1] == (tmp + 'a'))
							word[1] == 0;
						if (word[2] == (tmp + 'a'))
							word[2] == 0;
						if (word[3] == (tmp + 'a'))
							word[3] == 0;
						if (word[4] == (tmp + 'a'))
							word[4] == 0;
					}
				}
			}
			for (tmp = 0; tmp < 26; ++tmp) {
				if (checkstatus(tmp + 'A', BLACK)) {
					if (word[0] == (tmp + 'A') || word[1] == (tmp + 'A') || word[2] == (tmp + 'A') || word[3] == (tmp + 'A') || word[4] == (tmp + 'A') || word[0] == (tmp + 'a') || word[1] == (tmp + 'a') || word[2] == (tmp + 'a') || word[3] == (tmp + 'a') || word[4] == (tmp + 'a'))
						isvalid = FALSE;
				}
			}
			if (isvalid) {
				printf("%s\n", word);
			} else {
				i = 0;
				isvalid = TRUE;
			}
		} else {
			while ((nextchar = getchar()) != '\n')
				;
			c = nextchar;
			continue;
		}
		if (isalpha(c))
			word[i++] = c;
		else {
			printf("Error: character is not a letter\n");
		}
		c = nextchar;
	}
}

void reset()
{
	int i;
	extern int alphabet[26];
	extern int green[5];

	i = 0;
	while (i < 26)
		alphabet[i++] = WHITE;

	i = 0;
	while (i < 5)
		green[i++] = FALSE;
}

void setletter(char c, int status)
{
	extern int alphabet[26];

	if (islower(c))
		alphabet[c - 'a'] = status;
	else if (isupper(c))
		alphabet[c - 'A'] = status;
}

int checkstatus(char c, int status)
{
	extern int alphabet[26];
	
	if (islower(c)) {
		if (alphabet[c - 'a'] == status)
			return TRUE;
		else
			return FALSE;
	}
	else if (isupper(c)) {
		if (alphabet[c - 'A'] == status)
			return TRUE;
		else
			return FALSE;
	}

	else
		return FALSE;
}