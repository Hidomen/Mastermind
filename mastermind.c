#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


#include "MMprints.h"
#include "MMfuncs.h"
#include "MMreturnfuncs.h"
#include "MMtwoPmode.h"


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
#define RETURN_LENGTH 17
#define MAX_LIMIT 1

#define MAX_RETURN (RETURN_LENGTH*MAX_LIMIT)
//  1023 -> +0, -2 |


bool isExit = false;


char returnList[MAX_RETURN];
char guessStr[RETURN_LENGTH];


int guessList[MAX_LIMIT+1];

//************************************/

int limit[] = {3, 4, 7, 8, 11, 15, MAX_LIMIT};

void test(int Snumber){
    

    printf(cRED "%d", Snumber);
    printf(cRST);
}


bool roundPlay(int turnLimit){

    int guess;

    int Snumber = numberGenerator();

    int arrSnumber[NUMBERSIZE];
    int arrGuess[NUMBERSIZE];

    fillIntArr(guessList, 0, MAX_LIMIT+1);

    //TURNS
    for(int turnIndex = 0; turnIndex < turnLimit; turnIndex++){
        printf("\e[1;1H\e[2J");

        test(Snumber);
        
        if(turnIndex != 0){
            printf("Previous Guesses: ");
                        
            printReturn(returnList, RETURN_LENGTH*turnIndex);
            printf("\n");
        }

        printf("\nRemaining Guesses: %d\n", turnLimit-turnIndex);

        //taking guess
        printf(cYLW);
        printf("\n Guess #%d > ", turnIndex+1);
        printf(cRST);


        guess = takeGuess(guessList);

        if(guess == Snumber){
            break;
        }
        //
        guessList[turnIndex] = guess;
        


        //RETURN STUFF
        char guessStr[RETURN_LENGTH];
        printGuessReturn(Snumber, guess, guessStr);

        addToList(returnList, guessStr, RETURN_LENGTH*turnIndex, RETURN_LENGTH);

        
    }
    return(Snumber == guess);
}


void game(){
    char name[25];

    introScreen();
    scanf("%24[^\n]", name);
        
        
    printstr(name);
    printf("\n");


    bool isWin;

    int indexLimitCount = sizeof(limit)/sizeof(limit[0]);


        for(; indexLimitCount > 0; indexLimitCount--){
            int roundNumber = -1*indexLimitCount + sizeof(limit)/sizeof(limit[0]) + 1;


            printf("Round: %d\n", roundNumber);


            int limitNumber = limit[indexLimitCount - 1];
            
            printf("Limit Number : %d\n\n", limitNumber);
            
            isWin = roundPlay(limitNumber);
        }

        if(isWin){
            //WIN SCREEN
            printWinScreen();
            int goldenNumber;
            scanf("%d", &goldenNumber);

        }else {
            //LOSE SCREEN
            printLoseScreen();
            isExit = true;
        }
}


void seeClist(){

}


void cGame(){
    
}

int main(){
    srand(time(NULL));

    // printf(cRST "RED\n");
    
    while(!isExit){

        
        int option;

        printMenuScreen();
        scanf("%d", &option);

        switch (option){
        
        case 1:
        //tournament
            game();
            break;
        
        case 2:
        //multiplayer
            twoPgame();
            break;

        case 3:
        //champ list
            seeClist();
            break;
        case 4:
        //challenge mode
            cGame();
            break;
        case 5:
        //exit
            isExit = true;
            break;
        }    
    }
    return 0;
}