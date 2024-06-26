/* this sentence was written in Visual Studio Code */
/* C program by Richard Jiang. Given a set of parameters from Wordle, this program will spit out all 5-letter words that match these parameters */
/* Written on 10/5/2023 */
/* note: does not work yet */

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define DEFAULT 0
#define BLACK 1
#define YELLOW 2
#define GREEN 3

void reset();
void setletter(char c, int status);
int checkstatus(char c, int status);

int black[26];
int inputstatus[5];
int inputword[5];

main()
{
	int i, pos, tmp, tmp2;
	char c;
	char word[5];
	extern int green[5];
	int isvalid;

	word[5] = '\0';
	isvalid = TRUE;
	reset();

	setletter('A', GREEN);	
	setletter('T', GREEN);
	setletter('E', YELLOW);
	setletter('B', BLACK);	
	setletter('O', BLACK);	
	setletter('U', BLACK);	
	setletter('S', BLACK);
	green[0] = TRUE;
	green[4] = TRUE;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {


	/*
	printf("Enter all letters that are black.\nCapitalization is ignored.\nEnter the number zero to stop.\n");
	while (1) {
		scanf("%c", &c);
		//printf("DEBUG: c = %c\n", c);
		if (c == '0') {
			//printf("DEBUG: breaking\n");
			break;
		}
		if (c != '\n')
		    setletter(c, BLACK);
	}

	printf("Enter all letters that are yellow.\nCapitalization is ignored.\nEnter the number zero to stop.\n");
	while (1) {
		scanf("%c", &c);
		if (c == '0')
			break;
		if (c != '\n')
		    setletter(c, YELLOW);
	}

	printf("Enter all letters that are GREEN. After entering the letter, enter a number to represent postion.\nCapitalization is ignored.\nEnter the number zero for the letter to stop.\n");
	while (1) {
		scanf("%c", &c);
		if (c == '\n')
			continue;
		if (c == '0')
			break;
		if (c != '\n')
		    setletter(c, GREEN);
		scanf("%d", &pos);
		green[pos-1] = TRUE;
	}
	*/

	/* order of (ir)relevance
	 * contains a black letter
	 * does not contain any yellow letter
	 * green letters do not match
	 */

	/* pseudocode
	 * if c is a newline, check the data in word[]
	 * if word contains a letter that is marked black,
	 * word is not valid
	 * if the green positions do not match
	 * word is not valid
	 * if any of the yellow positions match
	 * word is not valid
	 */

	 /*
	i = 0;
	c = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
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
			i = 0;
			continue;
		} */	
		/*
		} else if (i == 5 && nextchar != '\n') {
			//printf("DEBUG: skipping to the end of word\n");
			while ((nextchar = getchar()) != '\n')
				;
			c = nextchar;
			continue;
		} */
		//printf("DEBUG: c = %c\n", c);
		//if (isalpha(c)) {
			//printf("isalpha(c)\n");
			//word[i++] = c;
		//}
		/*
		else if (c != '\n') {
			printf("Error: %c is not a letter\n", c);
		} */
		/*
		if (i == 5) {
			printf("DEBUG: word = %s\n", word);
			printf("DEBUG: nextchar = %c\n", nextchar);
		} */
		//c = nextchar;
		//++i;
	}
}

void reset()
{
	int i;
	extern int black[26];
	extern int wordstatus[5];
	extern int wordinput[5];

	i = 0;
	while (i < 26)
		black[i++] = FALSE;

	i = 0;
	while (i < 5)
		wordinput[i++] = '\0';
}

void setletter(char c, int status, int pos)
{
	extern int alphabet[26];

	if (status == BLACK) {
		if (islower(c))
			alphabet[c - 'a'] = status;
		else if (isupper(c))
			alphabet[c - 'A'] = status;
		break;
	} else {
		wordstatus[pos-1] = status;
		wordinput[pos-1] = c;
		continue;
	}
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
