/* Write the function strrindex(s,t), which returns the position of the rightmost occurence of t in s, or -1 if there is none. */
int strrindex(char s[], char t)
{
	int i;
	int output = -1;

	i = 0;
	while (s[i] != '\0') {
		if (s[i] == t)
			output = i;
		++i;
	}

	return output;
}
