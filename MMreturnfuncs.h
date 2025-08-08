#include <stdio.h>
// #include

#define NUMBERSIZE 4

//VISUAL
#define cRED     "\e[0;31m"
#define cBLU     "\e[0;34m"   
#define cYLW     "\e[0;33m"
#define cPRP     "\e[0;35m"
#define cGRN     "\e[0;32m"
#define cRST     "\033[0m"
//


#ifndef _INC_MMRETURNF // include guard for 3rd party interop
#define _INC_MMRETURNF

void guessFormat(char *guessReturnSTR, int guess, int minusReturn, int plusReturn){
    
    sprintf(guessReturnSTR, "%d -> +%d, -%d", guess, plusReturn, minusReturn);
    // printf("%s\n", guessReturnSTR);

}


void addToList(char arr[], char input[], int from, int length){

    arr[from] = ' ';

    
    for(int i = 0; i < length-3; i++){
        arr[from+i+1] = input[i];
    }


    arr[from+length-2] = ' ';
    arr[from+length-1] = '/';
}

//prints guess return and formats guess
void printGuessReturn(int Snumber, int guess, char guessStr[]){

    int arrSNumber[NUMBERSIZE];
    int arrGuess[NUMBERSIZE];

    numberToArr(Snumber, arrSNumber, NUMBERSIZE);
    numberToArr(guess, arrGuess, NUMBERSIZE);

    
    int minusReturn = minusComparison(arrSNumber, arrGuess, NUMBERSIZE);
    int plusReturn = plusComparison(arrSNumber, arrGuess, NUMBERSIZE);

    printf("+%d", plusReturn);
    printf("-%d", minusReturn);
    printf("\n");


    guessFormat(guessStr, guess, minusReturn, plusReturn);

}

#endif