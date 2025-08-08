#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>


#include "MMfuncs.h"
#include "MMprints.h"
#include "MMreturnfuncs.h"

#define NUMBERSIZE 4
#define RETURN_LENGTH 17


//VISUAL
#define cRED     "\e[0;31m"
#define cBLU     "\e[0;34m"   
#define cYLW     "\e[0;33m"
#define cPRP     "\e[0;35m"
#define cGRN     "\e[0;32m"
#define cRST     "\033[0m"
//

bool isExitTP = false;

#ifndef _INC_MMPTWOP // include guard for 3rd party interop
#define _INC_MMTWOP

int takeNumber(){
    int number;

    while(!isNumberValid(number) || digitCount(number) != NUMBERSIZE){
        scanf("%d", &number);
        
        //errors

        //its not 4 digit
        if(digitCount(number) != NUMBERSIZE){
            printf("Your number must be %d digit\n", NUMBERSIZE);
            continue;
        }
        
        //its repeating
        if(!isNumberValid(number)){
            printf("Your number mustn't repeating, must be valid number\n");
            continue;
        }

    }

        //valid guess
    return number;
}


void printTakeNumber(int playerTurn){
    printf("Enter your Secret Number Player %d: ", playerTurn);
}


void twoPgame(){
    // enum playerTurn {PlayerOne = 1, PlayerTwo = 2};
    // playerTurn = PlayerOne;
    int playerTurn = 1;
    int turnIndex = 0;

    int p1GuessList[250];
    int p2GuessList[250];

    int guessOne;
    int guessTwo;

    printTakeNumber(1);
    int p1Snumber = takeNumber();

    printTakeNumber(2);
    int p2Snumber = takeNumber();


    char p1returnList[250];
    char p2returnList[250];

    while(!isExitTP){
        // for(int i = 1; !isExit; playerTurn++)
        // PLAYER 1
        if(playerTurn == 1){
            printf("\e[1;1H\e[2J");

            //previous guesses
            if(turnIndex != 0){
                printf("Previous Guesses: ");
                            
                printReturn(p1returnList, RETURN_LENGTH*turnIndex);
                printf("\n");
            }

            //taking guess
            printf(cYLW);
            printf("\nP1 Guess #%d > ", turnIndex+1);
            printf(cRST);

            guessOne = takeGuess(p1GuessList);

            if(guessOne == p2Snumber){
                //P1 WON
            }
        }


        // PLAYER 2
        if(playerTurn == 2){
            printf("\e[1;1H\e[2J");

            //previous guesses
            if(turnIndex != 0){
                printf("Previous Guesses: ");
                            
                printReturn(p2returnList, RETURN_LENGTH*turnIndex);
                printf("\n");
            }


            //taking guess
            printf(cYLW);
            printf("\nP2 Guess #%d > ", turnIndex+1);
            printf(cRST);

            guessTwo = takeGuess(p2GuessList);

            if(guessTwo == p1Snumber){
                //P2 WON
            }
        }




        //TURN CHANGER
        if(playerTurn == 1){
            playerTurn = 2;
        } else {
            playerTurn = 1;
        }
        turnIndex++;
        //
    }

}

#endif