#include <stdio.h>
// #include

#define NUMBERSIZE 4

void guessFormat(char *guessReturnSTR, int guess, int minusReturn, int plusReturn){
    
    sprintf(guessReturnSTR, "%d -> +%d, -%d", guess, plusReturn, minusReturn);
    // printf("%s\n", guessReturnSTR);

}


void addToList(char arr[], char input[], int from, int length){

    // arr[from] = ' ';
    // arr[from+1] = '|';
    // arr[from+2] = ' ';

    for(int i = 0; i < length; i++){
        arr[from+i] = input[i];
    }
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