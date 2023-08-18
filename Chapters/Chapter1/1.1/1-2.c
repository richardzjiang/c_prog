/* above was a list of escape sequences */
/* Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above. */

#include <stdio.h>

main()
{
	printf("hello, \jworld\n");
}
