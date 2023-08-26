/* Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F. */

#include <stdio.h>
#define MAXINPUT 16

int htoi(char *s);

main()
{
	int c, i;
	char input[MAXINPUT];

	while (c = getchar()) {
		if (c == '\n') {
			printf("%d\n", htoi(input));
			i = 0;
		}
		else if (c == EOF) {
			printf("%d\n", htoi(input));
			break;
		}
		else
			input[i++] = c;
	}
}

int htoi(char *s)
{
	int i;
	int output = 0;

	if (i == 0)
		return 0;

	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			output = output * 10 + (s[i] - '0');
		if (s[i] >= 'a' && s[i] <= 'f')
			output = output * 10 + (s[i] - 'a' + 10);
		if (s[i] >= 'A' && s[i] <= 'F')
			output = output * 10 + (s[i] - 'A' + 10);
	}
	return output;
}
