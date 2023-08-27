/* Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.) */

#include <stdio.h>

int any(char *s1, char *s2);

main()
{
	char string1[100] = "POTATOES";	/* the second element of the array, string1[1], is the first char that matches any char in string2. the function should return 1 */
	char string2[100] = "CROCK POT";

	printf("any(string1, string2) = %d\nThe correct answer is 1\n", any(string1, string2));
}

int any(char *s1, char *s2)
{
	int i, j, n;

	for (n = 0; s2[n] != '\0'; n++)
		for (i = j = 0; s1[i] != '\0'; i++)
			if (s1[i] == s2[n])
				return i;
	return -1;
}
