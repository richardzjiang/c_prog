#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int slot1;
    int slot2;
    int slot3;
    int slot4;
    int slot5;
    int slot6;
    int slot7;
    int slot8;
    int slot9;
    
    //crappy TicTacToe
    //coded by Richard Jiang
    //coded in https://www.onlinegdb.com/online_c_compiler
    
    //each slot has three possible values. 0, 1, 2. 0 means unoccupied. 1 means occupied by computer. 2 means occupied by player.
    
    //lines are groups of three slots. If all three slots of a line are occupied by the same entity, then that entity wins.
    
    //line1 slots: 1, 2, 3
    //line2 slots: 1, 4, 7
    //line3 slots: 3, 6, 9
    //line4 slots: 7, 8, 9
    //line5 slots: 3, 5, 7
    //line6 slots: 1, 5, 9
    //line7 slots: 4, 5, 6
    //line8 slots: 2, 5, 8
    
    int risk1; //risk of line1. increases when more of line1's slots are occupied by player
    int risk2;
    int risk3;
    int risk4;
    int risk5;
    int risk6;
    int risk7;
    int risk8;
    
    int completion1; //the computer version of risk. increases when more of the line1's slots are occupied by computer
    int completion2;
    int completion3;
    int completion4;
    int completion5;
    int completion6;
    int completion7;
    int completion8;
    
    float incentive1; //the "1" designates the slot. For example, this one is the incentive of slot1.
    float incentive2; //incentive is how beneficial it is for the slot to be occupied by the computer
    float incentive3; //incentive increases when adjacent slots are computer occupied
    float incentive4; //incentives must be float because they are decimals
    float incentive5;
    float incentive6;
    float incentive7;
    float incentive8;
    float incentive9;
    
    //other variables:
    
    char symbol;
    int input;
    int win; //if win = 0, then there is not win. if win = 1, then there is a win. if it is 2, then it is a draw
    int equalrisk; //a very specific variable. It is the number of lines that have equal risk value. It is not permanent and changes as the game goes on.
    char equalriskstring[9]; //works together with the integer variable equalrisk. this string stores the lines that have equal risk values. for unimportant reasons, equalrisk[0] will not be used.
    int highestrisk; //what is the highest risk value that exists? NOTE: this is the value of the highest existing risk, but does not include information about what line has this value.
    int linehighestrisk; //number of the line that has the highest risk value
    int computerturn; //what the computer will play next
    int random; //random value generated randomly. the rand() function used to generate this value has to have a maximum value. this maximum value will be equalrisk. random will be used to pick a random value from the string. for example, equalriskstring[random]
    int tmp; //a temporary variable
    float highestincentive; //what incentive value is the highest? this is similar to highestrisk. it tells the highest incentive value, but does not say what slot it comes from
    int equalincentive; //how many different slots have exactly the same incentive value?
    int slothighestincentive; //which slot has the highest incentive value?
    int equalincentivestring[10];
    int computerwin; //similar to the win variable, but more specific in that it only mentions if the computer win
    int playerwin; //similar to computerwin
    int highestcompletion;
    int linehighestcompletion;
    int equalcompletion;
    char equalcompletionstring[9];
    
    risk1 = 0; //risk starts at 0, because at the beginning, none of the slots are occupied by the player
    risk2 = 0;
    risk3 = 0;
    risk4 = 0;
    risk5 = 0;
    risk6 = 0;
    risk7 = 0;
    risk8 = 0;
    
    completion1 = 0;
    completion2 = 0;
    completion3 = 0;
    completion4 = 0;
    completion5 = 0;
    completion6 = 0;
    completion7 = 0;
    completion8 = 0;
    
    incentive1 = 1; //incentives start at 1 and increase. if an incentive becomes zero, then its corresponding slot will never be played (because that slot is occupied)
    incentive2 = 1;
    incentive3 = 1;
    incentive4 = 1;
    incentive5 = 1;
    incentive6 = 1;
    incentive7 = 1;
    incentive8 = 1;
    incentive9 = 1;
    
    slot1 = 0; //slots start unoccupied, so they start as zero
    slot2 = 0;
    slot3 = 0;
    slot4 = 0;
    slot5 = 0;
    slot6 = 0;
    slot7 = 0;
    slot8 = 0;
    slot9 = 0;
    
    win = 0;
    computerwin = 0;
    playerwin = 0;
    
    symbolscan:
    printf("X or O?");
    printf("\033[2;1H");
    printf("                ");
    printf("\033[2;1H");
    printf(": ");
    scanf("%s", &symbol);
    if (symbol != 'X') {
        if (symbol != 'O') {
            printf("Invalid Symbol!");
            printf("\033[1;1H");
            sleep(1);
            goto symbolscan;
        }
    }
    printf("\033[1;1H");
    
    printf("[1][2][3]\n");
    printf("[4][5][6]\n");
    printf("[7][8][9]          \n\n");
    printf("Enter your input: ");
    
    while (win == 0) {
        printf("\033[5;19H");
        printf("     ");
        printf("\033[5;19H");
        scanf("%d", &input);
        
        if (input == 1) { //this converts the player's input into display data
            slot1 = 2;
            incentive1 = 0; //an incentive of zero means that the computer will never consider playing here. this code is needed because we don't want the computer to play a slot that the player has already used
            if (symbol == 'X') {
                printf("\033[1;2H");
                printf("X");
            } else {
                printf("\033[1;2H");
                printf("O");
            }
        } else if (input == 2) {
            slot2 = 2;
            incentive2 = 0;
            if (symbol == 'X') {
                printf("\033[1;5H");
                printf("X");
            } else {
                printf("\033[1;5H");
                printf("O");
            }
        } else if (input == 3) {
            slot3 = 2;
            incentive3 = 0;
            if (symbol == 'X') {
                printf("\033[1;8H");
                printf("X");
            } else {
                printf("\033[1;8H");
                printf("O");
            }
        } else if (input == 4) {
            slot4 = 2;
            incentive4 = 0;
            if (symbol == 'X') {
                printf("\033[2;2H");
                printf("X");
            } else {
                printf("\033[2;2H");
                printf("O");
            }
        } else if (input == 5) {
            slot5 = 2;
            incentive5 = 0;
            if (symbol == 'X') {
                printf("\033[2;5H");
                printf("X");
            } else {
                printf("\033[2;5H");
                printf("O");
            }
        } else if (input == 6) {
            slot6 = 2;
            incentive6 = 0;
            if (symbol == 'X') {
                printf("\033[2;8H");
                printf("X");
            } else {
                printf("\033[2;8H");
                printf("O");
            }
        } else if (input == 7) {
            slot7 = 2;
            incentive7 = 0;
            if (symbol == 'X') {
                printf("\033[3;2H");
                printf("X");
            } else {
                printf("\033[3;2H");
                printf("O");
            }
        } else if (input == 8) {
            slot8 = 2;
            incentive8 = 0;
            if (symbol == 'X') {
                printf("\033[3;5H");
                printf("X");
            } else {
                printf("\033[3;5H");
                printf("O");
            }
        } else if (input == 9) {
            slot9 = 2;
            incentive9 = 0;
            if (symbol == 'X') {
                printf("\033[3;8H");
                printf("X");
            } else {
                printf("\033[3;8H");
                printf("O");
            }
        } else {
            //invalid input
        }
        
        //line1 slots: 1, 2, 3
        //line2 slots: 1, 4, 7
        //line3 slots: 3, 6, 9
        //line4 slots: 7, 8, 9
        //line5 slots: 3, 5, 7
        //line6 slots: 1, 5, 9
        //line7 slots: 4, 5, 6
        //line8 slots: 2, 5, 8
        
        if (input == 1) { //when the player's input is 1, the risk of all lines that contain slot1 increases by 1
            ++risk1;
            ++risk2;
            ++risk6;
        } else if (input == 2) {
            ++risk1;
            ++risk8;
        } else if (input == 3) {
            ++risk1;
            ++risk3;
            ++risk5;
        } else if (input == 4) {
            ++risk2;
            ++risk7;
        } else if (input == 5) {
            ++risk5;
            ++risk6;
            ++risk7;
            ++risk8;
        } else if (input == 6) {
            ++risk3;
            ++risk7;
        } else if (input == 7) {
            ++risk2;
            ++risk4;
            ++risk5;
        } else if (input == 8) {
            ++risk4;
            ++risk8;
        } else if (input == 9) {
            ++risk3;
            ++risk4;
            ++risk6;
        }
        
        if (risk1 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        if (risk2 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        if (risk3 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        if (risk4 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        if (risk5 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        if (risk6 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        if (risk7 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        if (risk8 == 3) {
            win = 1;
            playerwin = 1;
            goto endofloop;
        }
        
        if (slot1 != 0) {
            if (slot2 != 0) {
                if (slot3 != 0) {
                    if (slot4 != 0) {
                        if (slot5 != 0) {
                            if (slot6 != 0) {
                                if (slot7 != 0) {
                                    if (slot8 != 0) {
                                        if (slot9 != 0) {
                                            if (playerwin == 0) {
                                                win = 2;
                                                goto outofloop;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        /*
        this code has been replaced by the code below it:
        the problem with this code is that it correctly tells me the highest risk value, but it doesn't tell me the line that has this value
        equalrisk = 0; //before comparison, zero lines have equal risk value. 
        highestrisk = -1; //this -1 value means nothing
        highestrisk = fmax(highestrisk,risk1); //fmax() can only compare two variables at once. I found that this is an easy way to bypass this obstacle.
        highestrisk = fmax(highestrisk,risk2);
        highestrisk = fmax(highestrisk,risk3);
        highestrisk = fmax(highestrisk,risk4);
        highestrisk = fmax(highestrisk,risk5);
        highestrisk = fmax(highestrisk,risk6);
        highestrisk = fmax(highestrisk,risk7);
        highestrisk = fmax(highestrisk,risk8);
        */
        /*
        no longer needed debug code:
        printf("\n\n\n\n\n1: %d\n", risk1);
        printf("2: %d\n", risk2);
        printf("3: %d\n", risk3);
        printf("4: %d\n", risk4);
        printf("5: %d\n", risk5);
        printf("6: %d\n", risk6);
        printf("7: %d\n", risk7);
        printf("8: %d\n", risk8);
        */
        
        highestrisk = -1; //this -1 value means nothing
        if (highestrisk < risk1) { //replaces the unused code chunk above
            linehighestrisk = 1;
            highestrisk = risk1;
        }
        if (highestrisk < risk2) {
            linehighestrisk = 2;
            highestrisk = risk2;
        }
        if (highestrisk < risk3) {
            linehighestrisk = 3;
            highestrisk = risk3;
        }
        if (highestrisk < risk4) {
            linehighestrisk = 4;
            highestrisk = risk4;
        }
        if (highestrisk < risk5) {
            linehighestrisk = 5;
            highestrisk = risk5;
        }
        if (highestrisk < risk6) {
            linehighestrisk = 6;
            highestrisk = risk6;
        }
        if (highestrisk < risk7) {
            linehighestrisk = 7;
            highestrisk = risk7;
        }
        if (highestrisk < risk8) {
            linehighestrisk = 8;
            highestrisk = risk8;
        }
        //updated equalrisk calculator:
        equalrisk = 0; //before comparison, zero lines have equal risk value. 
        if (highestrisk == risk1) { //note: if equalrisk = 1, then no other lines are equal to highestrisk line. equalrisk = 1 because the line with highest risk is equal to itself
            ++equalrisk;
            equalriskstring[equalrisk] = 1; //equalriskstring will contain all of the equal lines
        }
        if (highestrisk == risk2) {
            ++equalrisk;
            equalriskstring[equalrisk] = 2;
        }
        if (highestrisk == risk3) {
            ++equalrisk;
            equalriskstring[equalrisk] = 3;
        }
        if (highestrisk == risk4) {
            ++equalrisk;
            equalriskstring[equalrisk] = 4;
        }
        if (highestrisk == risk5) {
            ++equalrisk;
            equalriskstring[equalrisk] = 5;
        }
        if (highestrisk == risk6) {
            ++equalrisk;
            equalriskstring[equalrisk] = 6;
        }
        if (highestrisk == risk7) {
            ++equalrisk;
            equalriskstring[equalrisk] = 7;
        }
        if (highestrisk == risk8) {
            ++equalrisk;
            equalriskstring[equalrisk] = 8;
        }
        
        if (equalrisk > 1) { //if there are more than one highest risk lines that are equal to each other, then linehighestrisk becomes meaningless
            linehighestrisk = 0;
        }
        
        //line1 slots: 1, 2, 3
        //line2 slots: 1, 4, 7
        //line3 slots: 3, 6, 9
        //line4 slots: 7, 8, 9
        //line5 slots: 3, 5, 7
        //line6 slots: 1, 5, 9
        //line7 slots: 4, 5, 6
        //line8 slots: 2, 5, 8
        
        tmp = 1;
        while (tmp < 9) {
            if (equalriskstring[tmp] == 1) { //we read equalriskstring1. for example, if it is line one, then we multiply the incentives of all of the slots in line one by 1.1.
                incentive1 = incentive1 * (2 * highestrisk);
                incentive2 = incentive2 * (2 * highestrisk);
                incentive3 = incentive3 * (2 * highestrisk);
            } else if (equalriskstring[tmp] == 2) {
                incentive1 = incentive1 * (2 * highestrisk);
                incentive4 = incentive4 * (2 * highestrisk);
                incentive7 = incentive7 * (2 * highestrisk);
            } else if (equalriskstring[tmp] == 3) {
                incentive3 = incentive3 * (2 * highestrisk);
                incentive6 = incentive6 * (2 * highestrisk);
                incentive9 = incentive9 * (2 * highestrisk);
            } else if (equalriskstring[tmp] == 4) {
                incentive7 = incentive7 * (2 * highestrisk);
                incentive8 = incentive8 * (2 * highestrisk);
                incentive9 = incentive9 * (2 * highestrisk);
            } else if (equalriskstring[tmp] == 5) {
                incentive3 = incentive3 * (2 * highestrisk);
                incentive5 = incentive5 * (2 * highestrisk);
                incentive7 = incentive7 * (2 * highestrisk);
            } else if (equalriskstring[tmp] == 6) {
                incentive1 = incentive1 * (2 * highestrisk);
                incentive5 = incentive5 * (2 * highestrisk);
                incentive9 = incentive9 * (2 * highestrisk);
            } else if (equalriskstring[tmp] == 7) {
                incentive4 = incentive4 * (2 * highestrisk);
                incentive5 = incentive5 * (2 * highestrisk);
                incentive6 = incentive6 * (2 * highestrisk);
            } else if (equalriskstring[tmp] == 8) {
                incentive2 = incentive2 * (2 * highestrisk);
                incentive5 = incentive5 * (2 * highestrisk);
                incentive8 = incentive8 * (2 * highestrisk);
            }
            ++tmp;
        }
        
        //slot1 adjacents: 2, 4, 5 + 3, 7, 9
        //slot2 adjacents: 1, 3, 5 + 8
        //slot3 adjacents: 2, 5, 6 + 1, 7, 9
        //slot4 adjacents: 1, 5, 7 + 6
        //slot5 adjacents: 1, 2, 3, 4, 6, 7, 8, 9
        //slot6 adjacents: 3, 5, 9 + 4
        //slot7 adjacents: 4, 5, 8 + 1, 3, 9
        //slot8 adjacents: 5, 7, 9 + 2
        //slot9 adjacents: 5, 6, 8 + 1, 3, 7
        /*
        //start of sketchy code
            if (computerturn == 1) { //when the computerturn is 1, the risk of all lines that contain slot1 increases by 1
            ++completion1;
            ++completion2;
            ++completion6;
        } else if (computerturn == 2) {
            ++completion1;
            ++completion8;
        } else if (computerturn == 3) {
            ++completion1;
            ++completion3;
            ++completion5;
        } else if (computerturn == 4) {
            ++completion2;
            ++completion7;
        } else if (computerturn == 5) {
            ++completion5;
            ++completion6;
            ++completion7;
            ++completion8;
        } else if (computerturn == 6) {
            ++completion3;
            ++completion7;
        } else if (computerturn == 7) {
            ++completion2;
            ++completion4;
            ++completion5;
        } else if (computerturn == 8) {
            ++completion4;
            ++completion8;
        } else if (computerturn == 9) {
            ++completion3;
            ++completion4;
            ++completion6;
        }
        
        highestcompletion = -1; //this -1 value means nothing
        if (highestcompletion < completion1) {
            linehighestcompletion = 1;
            highestcompletion = completion1;
        }
        if (highestcompletion < completion2) {
            linehighestcompletion = 2;
            highestcompletion = completion2;
        }
        if (highestcompletion < completion3) {
            linehighestcompletion = 3;
            highestcompletion = completion3;
        }
        if (highestcompletion < completion4) {
            linehighestcompletion = 4;
            highestcompletion = completion4;
        }
        if (highestcompletion < completion5) {
            linehighestcompletion = 5;
            highestcompletion = completion5;
        }
        if (highestcompletion < completion6) {
            linehighestcompletion = 6;
            highestcompletion = completion6;
        }
        if (highestcompletion < completion7) {
            linehighestcompletion = 7;
            highestcompletion = completion7;
        }
        if (highestcompletion < completion8) {
            linehighestcompletion = 8;
            highestcompletion = completion8;
        }
        //updated equalcompletion calculator:
        equalcompletion = 0; //before comparison, zero lines have equal risk value. 
        if (highestcompletion == completion1) { //note: if equalcompletion = 1, then no other lines are equal to highestcompletion line. equalcompletion = 1 because the line with highest risk is equal to itself
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 1; //equalcompletionstring will contain all of the equal lines
        }
        if (highestcompletion == completion2) {
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 2;
        }
        if (highestcompletion == completion3) {
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 3;
        }
        if (highestcompletion == completion4) {
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 4;
        }
        if (highestcompletion == completion5) {
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 5;
        }
        if (highestcompletion == completion6) {
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 6;
        }
        if (highestcompletion == completion7) {
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 7;
        }
        if (highestcompletion == completion8) {
            ++equalcompletion;
            equalcompletionstring[equalcompletion] = 8;
        }
        
        if (equalcompletion > 1) { //if there are more than one highest risk lines that are equal to each other, then linehighestcompletion becomes meaningless
            linehighestcompletion = 0;
        }
        
        //line1 slots: 1, 2, 3
        //line2 slots: 1, 4, 7
        //line3 slots: 3, 6, 9
        //line4 slots: 7, 8, 9
        //line5 slots: 3, 5, 7
        //line6 slots: 1, 5, 9
        //line7 slots: 4, 5, 6
        //line8 slots: 2, 5, 8
        
        tmp = 1;
        while (tmp < 9) {
            if (equalcompletionstring[tmp] == 1) { //we read equalcompletionstring1. for example, if it is line one, then we multiply the incentives of all of the slots in line one by 1.1.
                incentive1 = incentive1 * (1.1 * highestcompletion);
                incentive2 = incentive2 * (1.1 * highestcompletion);
                incentive3 = incentive3 * (1.1 * highestcompletion);
            } else if (equalcompletionstring[tmp] == 2) {
                incentive1 = incentive1 * (1.1 * highestcompletion);
                incentive4 = incentive4 * (1.1 * highestcompletion);
                incentive7 = incentive7 * (1.1 * highestcompletion);
            } else if (equalcompletionstring[tmp] == 3) {
                incentive3 = incentive3 * (1.1 * highestcompletion);
                incentive6 = incentive6 * (1.1 * highestcompletion);
                incentive9 = incentive9 * (1.1 * highestcompletion);
            } else if (equalcompletionstring[tmp] == 4) {
                incentive7 = incentive7 * (1.1 * highestcompletion);
                incentive8 = incentive8 * (1.1 * highestcompletion);
                incentive9 = incentive9 * (1.1 * highestcompletion);
            } else if (equalcompletionstring[tmp] == 5) {
                incentive3 = incentive3 * (1.1 * highestcompletion);
                incentive5 = incentive5 * (1.1 * highestcompletion);
                incentive7 = incentive7 * (1.1 * highestcompletion);
            } else if (equalcompletionstring[tmp] == 6) {
                incentive1 = incentive1 * (1.1 * highestcompletion);
                incentive5 = incentive5 * (1.1 * highestcompletion);
                incentive9 = incentive9 * (1.1 * highestcompletion);
            } else if (equalcompletionstring[tmp] == 7) {
                incentive4 = incentive4 * (1.1 * highestcompletion);
                incentive5 = incentive5 * (1.1 * highestcompletion);
                incentive6 = incentive6 * (1.1 * highestcompletion);
            } else if (equalcompletionstring[tmp] == 8) {
                incentive2 = incentive2 * (1.1 * highestcompletion);
                incentive5 = incentive5 * (1.1 * highestcompletion);
                incentive8 = incentive8 * (1.1 * highestcompletion);
            }
            ++tmp;
        } //end of sketchy code
        */
        //slot1 adjacents: 2, 4, 5 + 3, 7, 9
        tmp = slot2 + slot4 + slot5 + slot3 + slot7 + slot9; //calculating the incentive of slot1 based on how many adjacent slots are occupied by the player
        if (slot2 == 2) {
            tmp = tmp - 2;
        } if (slot4 == 2) {
            tmp = tmp - 2;
        } if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot3 == 2) {
            tmp = tmp - 2;
        } if (slot7 == 2) {
            tmp = tmp - 2;
        } if (slot9 == 2) {
            tmp = tmp - 2;
        }
        incentive1 = incentive1 * (1 + (0.05 * tmp)); //once again, multiplication, so that incentives that equal zero stay zero
        
        //slot2 adjacents: 1, 3, 5 + 8
        tmp = slot1 + slot3 + slot5 + slot8;
        if (slot1 == 2) {
            tmp = tmp - 2;
        } if (slot3 == 2) {
            tmp = tmp - 2;
        } if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot8 == 2) {
            tmp = tmp - 2;
        }
        incentive2 = incentive2 * (1 + (0.05 * tmp));
        
        //slot3 adjacents: 2, 5, 6 + 1, 7, 9
        tmp = slot2 + slot5 + slot6 + slot1 + slot7 + slot9;
        if (slot2 == 2) {
            tmp = tmp - 2;
        } if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot6 == 2) {
            tmp = tmp - 2;
        } if (slot1 == 2) {
            tmp = tmp - 2;
        } if (slot7 == 2) {
            tmp = tmp - 2;
        } if (slot9 == 2) {
            tmp = tmp - 2;
        }
        incentive3 = incentive3 * (1 + (0.05 * tmp));
        
        //slot4 adjacents: 1, 5, 7 + 6
        tmp = slot1 + slot5 + slot7 + slot6;
        if (slot1 == 2) {
            tmp = tmp - 2;
        } if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot7 == 2) {
            tmp = tmp - 2;
        } if (slot6 == 2) {
            tmp = tmp - 2;
        }
        incentive4 = incentive4 * (1 + (0.05 * tmp));
        
        //slot5 adjacents: 1, 2, 3, 4, 6, 7, 8, 9
        tmp = slot1 + slot2 + slot3 + slot4 + slot5 + slot6 + slot7 + slot8 + slot9;
        if (slot1 == 2) {
            tmp = tmp - 2;
        } if (slot2 == 2) {
            tmp = tmp - 2;
        } if (slot3 == 2) {
            tmp = tmp - 2;
        } if (slot4 == 2) {
            tmp = tmp - 2;
        } if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot6 == 2) {
            tmp = tmp - 2;
        } if (slot7 == 2) {
            tmp = tmp - 2;
        } if (slot8 == 2) {
            tmp = tmp - 2;
        } if (slot9 == 2) {
            tmp = tmp - 2;
        }
        incentive5 = incentive5 * (1 + (0.05 * tmp));
        
        //slot6 adjacents: 3, 5, 9 + 4
        tmp = slot3 + slot5 + slot9 + slot4;
        if (slot3 == 2) {
            tmp = tmp - 2;
        } if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot9 == 2) {
            tmp = tmp - 2;
        } if (slot4 == 2) {
            tmp = tmp - 2;
        }
        incentive6 = incentive6 * (1 + (0.05 * tmp));
        
        //slot7 adjacents: 4, 5, 8 + 1, 3, 9
        tmp = slot4 + slot5 + slot8 + slot1 + slot3 + slot9;
        if (slot4 == 2) {
            tmp = tmp - 2;
        } if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot8 == 2) {
            tmp = tmp - 2;
        } if (slot1 == 2) {
            tmp = tmp - 2;
        } if (slot3 == 2) {
            tmp = tmp - 2;
        } if (slot9 == 2) {
            tmp = tmp - 2;
        }
        incentive7 = incentive7 * (1 + (0.05 * tmp));
        
        //slot8 adjacents: 5, 7, 9 + 2
        tmp = slot5 + slot7 + slot9 + slot2;
        if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot7 == 2) {
            tmp = tmp - 2;
        } if (slot9 == 2) {
            tmp = tmp - 2;
        } if (slot2 == 2) {
            tmp = tmp - 2;
        }
        incentive8 = incentive8 * (1 + (0.05 * tmp));
        
        //slot9 adjacents: 5, 6, 8 + 1, 3, 7
        tmp = slot5 + slot6 + slot8 + slot1 + slot3 + slot7;
        if (slot5 == 2) {
            tmp = tmp - 2;
        } if (slot6 == 2) {
            tmp = tmp - 2;
        } if (slot8 == 2) {
            tmp = tmp - 2;
        } if (slot1 == 2) {
            tmp = tmp - 2;
        } if (slot3 == 2) {
            tmp = tmp - 2;
        } if (slot7 == 2) {
            tmp = tmp - 2;
        }
        incentive9 = incentive9 * (1 + (0.05 * tmp));
        
        //finds out the highest incentive value and the slot that contains this value
        highestincentive = -1; //this -1 value means nothing
        if (highestincentive < incentive1) {
            slothighestincentive = 1;
            highestincentive = incentive1;
        }
        if (highestincentive < incentive2) {
            slothighestincentive = 2;
            highestincentive = incentive2;
        }
        if (highestincentive < incentive3) {
            slothighestincentive = 3;
            highestincentive = incentive3;
        }
        if (highestincentive < incentive4) {
            slothighestincentive = 4;
            highestincentive = incentive4;
        }
        if (highestincentive < incentive5) {
            slothighestincentive = 5;
            highestincentive = incentive5;
        }
        if (highestincentive < incentive6) {
            slothighestincentive = 6;
            highestincentive = incentive6;
        }
        if (highestincentive < incentive7) {
            slothighestincentive = 7;
            highestincentive = incentive7;
        }
        if (highestincentive < incentive8) {
            slothighestincentive = 8;
            highestincentive = incentive8;
        }
        if (highestincentive < incentive9) {
            slothighestincentive = 9;
            highestincentive = incentive9;
        }
        
        equalincentive = 0;
        if (highestincentive == incentive1) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 1;
        }
        if (highestincentive == incentive2) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 2;
        }
        if (highestincentive == incentive3) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 3;
        }
        if (highestincentive == incentive4) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 4;
        }
        if (highestincentive == incentive5) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 5;
        }
        if (highestincentive == incentive6) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 6;
        }
        if (highestincentive == incentive7) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 7;
        }
        if (highestincentive == incentive8) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 8;
        }
        if (highestincentive == incentive9) {
            ++equalincentive;
            equalincentivestring[equalincentive] = 9;
        }
        
        if (equalincentive > 1) {
            slothighestincentive = 0; //if there is a tie between which slots have the highest incentive, the computer will choose one randomly
            srand(time(NULL));
            random = rand() % equalincentive + 1;
            computerturn = equalincentivestring[random];
        } else if (equalincentive == 1) { //if there is no tie and there is only one highest incentive, the the computer will play that spot
            computerturn = slothighestincentive;
        }
        
        /* //possibly a chunk of code that isn't meant to be here!
        if (input == 1) { //this converts the player's input into display data
            slot1 = 2;
            incentive1 = 0; //an incentive of zero means that the computer will never consider playing here. this code is needed because we don't want the computer to play a slot that the player has already used
            if (symbol == 'X') {
                printf("\033[1;2H");
                printf("X");
            } else {
                printf("\033[1;2H");
                printf("O");
            }
        } else if (input == 2) {
            slot2 = 2;
            incentive2 = 0;
            if (symbol == 'X') {
                printf("\033[1;5H");
                printf("X");
            } else {
                printf("\033[1;5H");
                printf("O");
            }
        } else if (input == 3) {
            slot3 = 2;
            incentive3 = 0;
            if (symbol == 'X') {
                printf("\033[1;8H");
                printf("X");
            } else {
                printf("\033[1;8H");
                printf("O");
            }
        } else if (input == 4) {
            slot4 = 2;
            incentive4 = 0;
            if (symbol == 'X') {
                printf("\033[2;2H");
                printf("X");
            } else {
                printf("\033[2;2H");
                printf("O");
            }
        } else if (input == 5) {
            slot5 = 2;
            incentive5 = 0;
            if (symbol == 'X') {
                printf("\033[2;5H");
                printf("X");
            } else {
                printf("\033[2;5H");
                printf("O");
            }
        } else if (input == 6) {
            slot6 = 2;
            incentive6 = 0;
            if (symbol == 'X') {
                printf("\033[2;8H");
                printf("X");
            } else {
                printf("\033[2;8H");
                printf("O");
            }
        } else if (input == 7) {
            slot7 = 2;
            incentive7 = 0;
            if (symbol == 'X') {
                printf("\033[3;2H");
                printf("X");
            } else {
                printf("\033[3;2H");
                printf("O");
            }
        } else if (input == 8) {
            slot8 = 2;
            incentive8 = 0;
            if (symbol == 'X') {
                printf("\033[3;5H");
                printf("X");
            } else {
                printf("\033[3;5H");
                printf("O");
            }
        } else if (input == 9) {
            slot9 = 2;
            incentive9 = 0;
            if (symbol == 'X') {
                printf("\033[3;8H");
                printf("X");
            } else {
                printf("\033[3;8H");
                printf("O");
            }
        } else {
            printf("\033[5;1H");
            printf("Invalid Input!                \n\n\n");
            //add a feature that waits a second and then goes back to let the player reenter a valid input
        } */
        
        if (computerturn == 1) {
            slot1 = 1;
            incentive1 = 0;
            if (symbol == 'X') {
                printf("\033[1;2H");
                printf("O");
            } else {
                printf("\033[1;2H");
                printf("X");
            }
        } else if (computerturn == 2) {
            slot2 = 1;
            incentive2 = 0;
            if (symbol == 'X') {
                printf("\033[1;5H");
                printf("O");
            } else {
                printf("\033[1;5H");
                printf("X");
            }
        } else if (computerturn == 3) {
            slot3 = 1;
            incentive3 = 0;
            if (symbol == 'X') {
                printf("\033[1;8H");
                printf("O");
            } else {
                printf("\033[1;8H");
                printf("X");
            }
        } else if (computerturn == 4) {
            slot4 = 1;
            incentive4 = 0;
            if (symbol == 'X') {
                printf("\033[2;2H");
                printf("O");
            } else {
                printf("\033[2;2H");
                printf("X");
            }
        } else if (computerturn == 5) {
            slot5 = 1;
            incentive5 = 0;
            if (symbol == 'X') {
                printf("\033[2;5H");
                printf("O");
            } else {
                printf("\033[2;5H");
                printf("X");
            }
        } else if (computerturn == 6) {
            slot6 = 1;
            incentive6 = 0;
            if (symbol == 'X') {
                printf("\033[2;8H");
                printf("O");
            } else {
                printf("\033[2;8H");
                printf("X");
            }
        } else if (computerturn == 7) {
            slot7 = 1;
            incentive7 = 0;
            if (symbol == 'X') {
                printf("\033[3;2H");
                printf("O");
            } else {
                printf("\033[3;2H");
                printf("X");
            }
        } else if (computerturn == 8) {
            slot8 = 1;
            incentive8 = 0;
            if (symbol == 'X') {
                printf("\033[3;5H");
                printf("O");
            } else {
                printf("\033[3;5H");
                printf("X");
            }
        } else if (computerturn == 9) {
            slot9 = 1;
            incentive9 = 0;
            if (symbol == 'X') {
                printf("\033[3;8H");
                printf("O");
            } else {
                printf("\033[3;8H");
                printf("X");
            }
        }
    /*
    printf("\033[8;1H");
    printf("computerturn: %d", computerturn);
    printf("\033[5;19H");
    printf("\nincentive1: %f", incentive1);
    printf("\nincentive2: %f", incentive2);
    printf("\nincentive3: %f", incentive3);
    printf("\nincentive4: %f", incentive4);
    printf("\nincentive5: %f", incentive5);
    printf("\nincentive6: %f", incentive6);
    printf("\nincentive7: %f", incentive7);
    printf("\nincentive8: %f", incentive8);
    printf("\nincentive9: %f", incentive9);
    printf("\ncomputerturn: %d", computerturn); */
    
    //line1 slots: 1, 2, 3
    //line2 slots: 1, 4, 7
    //line3 slots: 3, 6, 9
    //line4 slots: 7, 8, 9
    //line5 slots: 3, 5, 7
    //line6 slots: 1, 5, 9
    //line7 slots: 4, 5, 6
    //line8 slots: 2, 5, 8
    
    //computer win finder
    tmp = slot1 + slot2 + slot3; //line1
    if (slot1 == 2) {
        tmp = tmp - 2;
    }
    if (slot2 == 2) {
        tmp = tmp - 2;
    }
    if (slot3 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    tmp = slot1 + slot4 + slot7; //line2
    if (slot1 == 2) {
        tmp = tmp - 2;
    }
    if (slot4 == 2) {
        tmp = tmp - 2;
    }
    if (slot7 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    tmp = slot3 + slot6 + slot9; //line3
    if (slot3 == 2) {
        tmp = tmp - 2;
    }
    if (slot6 == 2) {
        tmp = tmp - 2;
    }
    if (slot9 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    tmp = slot7 + slot8 + slot9; //line4
    if (slot7 == 2) {
        tmp = tmp - 2;
    }
    if (slot8 == 2) {
        tmp = tmp - 2;
    }
    if (slot9 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    tmp = slot3 + slot5 + slot7; //line5
    if (slot3 == 2) {
        tmp = tmp - 2;
    }
    if (slot5 == 2) {
        tmp = tmp - 2;
    }
    if (slot7 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    tmp = slot1 + slot5 + slot9; //line6
    if (slot1 == 2) {
        tmp = tmp - 2;
    }
    if (slot5 == 2) {
        tmp = tmp - 2;
    }
    if (slot9 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    tmp = slot4 + slot5 + slot6; //line7
    if (slot4 == 2) {
        tmp = tmp - 2;
    }
    if (slot5 == 2) {
        tmp = tmp - 2;
    }
    if (slot6 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    tmp = slot2 + slot5 + slot8; //line8
    if (slot2 == 2) {
        tmp = tmp - 2;
    }
    if (slot5 == 2) {
        tmp = tmp - 2;
    }
    if (slot8 == 2) {
        tmp = tmp - 2;
    }
    if (tmp == 3) {
        win = 1;
        computerwin = 1;
    }
    /*
    printf("\033[6;1H");
    printf("\nincentive1: %f", incentive1);
    printf("\nincentive2: %f", incentive2);
    printf("\nincentive3: %f", incentive3);
    printf("\nincentive4: %f", incentive4);
    printf("\nincentive5: %f", incentive5);
    printf("\nincentive6: %f", incentive6);
    printf("\nincentive7: %f", incentive7);
    printf("\nincentive8: %f", incentive8);
    printf("\nincentive9: %f", incentive9);
    printf("\nhighestcompletion: %d", highestcompletion);
    printf("\nhighestrisk: %d", highestrisk); */
    
    endofloop:
    tmp = 0;
    } //for the while loop
    outofloop:
    if (playerwin == 1) {
        printf("\n\n\n\n\nPlayer win!");
    } else if (computerwin == 1) {
        printf("\n\n\n\n\nComputer win!");
    } else if (win == 2) {
        printf("\n\n\n\n\nIt's a draw!");
    }
    
    /*
    printf("\n\n\n\n\n\nhighestrisk: %d", highestrisk);
    printf("\nlinehighestrisk: %d", linehighestrisk);
    printf("\nequalrisk: %d", equalrisk);
    
    printf("\nequalriskstring: %d", equalriskstring[1]);
    printf("\nequalriskstring: %d", equalriskstring[2]);
    printf("\nequalriskstring: %d", equalriskstring[3]);
    printf("\nequalriskstring: %d", equalriskstring[4]);
    printf("\nequalriskstring: %d", equalriskstring[5]);
    printf("\nequalriskstring: %d", equalriskstring[6]);
    printf("\nequalriskstring: %d", equalriskstring[7]);
    printf("\nequalriskstring: %d\n", equalriskstring[8]);
    
    printf("\nincentive1: %f", incentive1);
    printf("\nincentive2: %f", incentive2);
    printf("\nincentive3: %f", incentive3);
    printf("\nincentive4: %f", incentive4);
    printf("\nincentive5: %f", incentive5);
    printf("\nincentive6: %f", incentive6);
    printf("\nincentive7: %f", incentive7);
    printf("\nincentive8: %f", incentive8);
    printf("\nincentive9: %f", incentive9);
    printf("\ntmp: %d", tmp); 
    printf("\ncomputerturn: %d", computerturn);
    */
}

//not fully developed

