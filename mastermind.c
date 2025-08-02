#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


#include "MMprints.h"
#include "MMfuncs.h"
#include "MMreturnfuncs.h"


//VISUAL
#define cRED     "\e[0;31m"
#define cBLU     "\e[0;34m"   
#define cYLW     "\e[0;33m"
#define cPRP     "\e[0;35m"
#define cGRN     "\e[0;32m"
#define cRST     "\033[0m"
//


//TECHNICAL
#define NUMBERSIZE 4
#define RETURN_LENGTH 15

bool isOver = false;


char returnList[100];
char guessStr[RETURN_LENGTH];
//************************************/


bool roundPlay(int turnLimit){

    int guess;

    int Snumber = numberGenerator();

    int arrSnumber[NUMBERSIZE];
    int arrGuess[NUMBERSIZE];
    

    // //for test
    // printf(cRED "%d", Snumber);
    // printf(cRST);
    // //
    
    //TURNS
    for(int turnIndex = 0; turnIndex < turnLimit; turnIndex++){

        //fixed this part
        if(turnIndex != 0){
            printf("Previous Guesses: ");
                        
            printstrl(returnList, RETURN_LENGTH*turnIndex);
        }

        //taking guess
        printf(cYLW);
        printf("\n Guess #%d > ", turnIndex+1);
        printf(cRST);
        int guess = takeGuess();
        //

        char guessStr[15];
        //RETURN STUFF
        printGuessReturn(Snumber, guess, guessStr);

    
        addToList(returnList, guessStr, RETURN_LENGTH*turnIndex, RETURN_LENGTH);

        
    }
    return(Snumber == guess);
}


int main(){
    srand(time(NULL));
    bool isWin;

    // printf(cRST "RED\n");
    

    while(!isOver){
        char name[25];

        
        //INTRO
        introScreen();
        scanf("%24[^\n]", name);
        
        
        printstr(name);
        printf("\n");
        
        //GAME
        int limit[] = {3, 4, 7, 8, 11, 15, 19};
        
        int indexLimitCount = sizeof(limit)/sizeof(limit[0]);


        for(; indexLimitCount > 0; indexLimitCount--){
            int roundNumber = -1*indexLimitCount + sizeof(limit)/sizeof(limit[0]) + 1;


            printf("Round: %d\n", roundNumber);


            int limitNumber = limit[indexLimitCount - 1];
            
            printf("Limit Number : %d\n\n", limitNumber);
            
            isWin = roundPlay(limitNumber);



            if(isWin){
                //WIN SCREEN
            }else {
                //LOSE SCREEN
                break;
            }
        }
    }

    return 0;
}