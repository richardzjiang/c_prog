/* Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. */

#include <stdio.h>

void squeeze(char *s1, char *s2);

main()
{
	char string1[100] = "I LOVE POTATOES!";
	char string2[100] = "E O";

	squeeze(string1, string2);

	printf("%s\n", string1);
}





/* delete each character in s1 that matches any character in s2 */
void squeeze(char *s1, char *s2)
{
	int i, j, n;

	for (n = 0; s2[n] != '\0'; n++) {
		for (i = j = 0; s1[i] != '\0'; i++)
			if (s1[i] != s2[n])
				s1[j++] = s1[i];
		s1[j] = '\0';
	}
}

