/******************\
| A WEEK OF SCHOOL |
| by Richard Jiang |
|   10/31/2023     |
\******************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

main()
{
    int cheat;
    int difficulty;
    char c;
    double englishgrade, historygrade, socialgrade, mathgrade, potterygrade;
    int day = 1;

    srand(time(NULL));

    printf("You're a student at school and report cards are in one week.\n");
    printf("Select a difficulty (1 - 5)\n");
    printf(": ");
    scanf("%d", &difficulty);
    if (difficulty >= 1 && difficulty <= 5) {
        englishgrade = rand() % (100 + 1 - 70) + 70;
        historygrade = rand() % (100 + 1 - 70) + 70;
        socialgrade = rand() % (100 + 1 - 70) + 70;
        mathgrade = rand() % (100 + 1 - 70) + 70;
        potterygrade = rand() % (100 + 1 - 70) + 70;
        //rand() % (100 - (difficulty - 1) * 5 + 1 - (70 - (difficulty - 1) * 5)) + 70;
    } else {
        printf("You are probably bad at multiple choice tests.\n");
        goto end;
    }
    printf("Take out your cheats? (Y/N)\n");
    printf(": ");
    scanf(" %c", &c);   /* the space before %c is intentional */
    if (c == 'N' || c == 'n') {
        cheat = FALSE;
        goto startofday;
    }
    else if (c == 'Y' || c == 'y')
        cheat == TRUE;
    else {
        printf("You are probably bad at multiple choice tests.\n");
        goto end;
    }
    
    if (cheat == TRUE) {
        printf("What are your current grades?\n");
        printf("English grade: ");
        scanf("%d", &englishgrade);
        if (englishgrade <= 0) {
            printf("Your grade was so low that you managed to break the laws of physics.\n");
            goto expelled;
        }
        if (englishgrade <= 60)
            printf("Good luck with your report card...\n");
        

        printf("History grade: ");
        scanf("%d", &historygrade);
        if (historygrade <= 0) {
            printf("Your grade was so low that you managed to break the laws of physics.\n");
            goto expelled;
        }
        if (historygrade <= 60)
            printf("Good luck with your report card...\n");
        

        printf("Social studies grade: ");
        scanf("%d", &socialgrade);
        if (socialgrade <= 0) {
            printf("Your grade was so low that you managed to break the laws of physics.\n");
            goto expelled;
        }
        if (socialgrade <= 60)
        printf("Good luck with your report card...\n");
        
        
        printf("Math grade: ");
        scanf("%d", &mathgrade);
        if (mathgrade <= 0) {
            printf("Your grade was so low that you managed to break the laws of physics.\n");
            goto expelled;
        }
        if (mathgrade <= 60)
            printf("Good luck with your report card...\n");
        
        /* add custom teacher names setting */
        /* add custom hat settings and stuff*/
        /* personality trait settings */
        /* add secret game mode */
        /* pottery class instead of history class during low difficulty */
        /* separate grades for each class */
        /* name settings */
        /* lower difficulties have nicer people */
        /* bug: difficulty level doesn't seem to be changed the range of possible random grade values */
        /* re-add grade ranges */
    }

    startofday:
    printf("DAY %d\n", day++);
    printf("ENGLISH GRADE: %.2g\n", englishgrade);
    printf("SOCIAL STUDIES GRADE: %.2g\n", socialgrade);
    printf("MATH GRADE: %.2g\n", mathgrade);
    if (difficulty >= 3)
        printf("HISTORY GRADE: %.2g\n", historygrade);
    else
        printf("POTTERY GRADE: %.2g\n", potterygrade);

    printf("DEBUG %d\n", cheat);

    expelled: printf("You got expelled.\n");
    end: printf("GAME OVER\n");
}