#include <stdio.h>

#define WORDSIZE 5
#define TRUE 1
#define FALSE 0

main()
{
    int c, i, tmp;
    int iswriting = TRUE;
    int word[WORDSIZE+2];

    word[WORDSIZE+1] = '\0';

    for (i = 0; (c = getchar()) != EOF;) {
        if (c == '\n') {
            if (iswriting == TRUE) {
                for (tmp = 0; tmp < WORDSIZE; ++tmp)
                    printf("%c", word[tmp]);
                putchar('\n');
            }
            for (tmp = 0; tmp < WORDSIZE; ++tmp)
                    word[tmp] = '\0';
            iswriting = TRUE;
            i = 0;
            continue;
        }
        if (i > WORDSIZE) {
            iswriting = FALSE;
            /*
            if (word[WORDSIZE] != '\n') {
                //while ((c = getchar()) != '\n');
                //i = 0;
                continue;
            } else if (word[WORDSIZE] == '\n') {
                printf("%s", word);
                i = 0;
                continue;
            } */
        }
        if (iswriting == TRUE)
            word[i++] = c;
    }
}