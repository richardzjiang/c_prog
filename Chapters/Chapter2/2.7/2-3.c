/* Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F. */

#include <stdio.h>
#define MAXINPUT 16

int htoi(char *s);

main()
{
	int c;
	int i;
	int invalidchars;
	char input[MAXINPUT];

	i = 0;
	invalidchars = 0;
	printf("Convert hexadecimal input to decimal!\n");
	printf("_____________________________________\n");
	while (c = getchar()) {
		if (c == EOF) {
			input[i] = '\0';
			printf("%d\n", htoi(input));
			if (invalidchars)
				printf("Contains invalid chars\n");
			invalidchars = 0;
			break;
		}
		if (c == '\n') {
			input[i] = '\0';
			printf("%d\n", htoi(input));
			if (invalidchars)
				printf("Contains invalid chars\n");
			invalidchars = 0;
			i = 0;
		} else if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
			if ((i + 1) < (MAXINPUT - 1))
				input[i++] = c;
			else {
				printf("Input too long!\n");
				break;
			}
		} else
			invalidchars = 1;
	}
}

int htoi(char *s)
{
	int i;
	int output = 0;

	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			output = output * 16 + (s[i] - '0');
		if (s[i] >= 'a' && s[i] <= 'f')
			output = output * 16 + (s[i] - 'a' + 10);
		if (s[i] >= 'A' && s[i] <= 'F')
			output = output * 16 + (s[i] - 'A' + 10);
	}
	return output;
}
