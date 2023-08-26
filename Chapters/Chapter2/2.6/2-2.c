/* Write a loop equivalent to the for loop above without using && or ||. */

/*************************\
|  I LIKE EATING POTATOES |
| DO YOU LIKE EATING THEM?|
\*************************/

for (i = 0; (c = getchar()) != EOF; ++i) {
	if (i < lim - 1)
		if (c != '\n')
			s[i] = c;
}
