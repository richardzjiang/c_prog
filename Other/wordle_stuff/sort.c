/* given an input consisting of words, it will output only the words that are WORDSIZE letters long */
/* please note that Windows uses a different way of doing newline. Windows txt files copied to here will have problems */

#include <stdio.h>

#define MAXWORD 50
#define WORDSIZE 5
#define TRUE 1
#define FALSE 0

main()
{
	int c;
	int word[MAXWORD];
	int length;
	
	for (length = 0; (c = getchar()) != EOF;) {
		if ((length + 2) == MAXWORD) {
			printf("Word too long!\n");
			length = 0;
			continue;
		}
		word[length++] = c;
		if (c == '\n' || c == EOF) {
			length -= 1;
			if (length == WORDSIZE) {
				word[WORDSIZE] = '\0';
				printf("%ls\n", word);
			}
			length = 0;
		}
	}
}
