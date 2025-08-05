#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


#define NUMBERSIZE 4
// #define FORMAT_LENGTH 15 //length of the return string including , 


#ifndef _INC_MMFUNCSS
#define _INC_MMFUNCSS

bool checkNotRepeating(int *list, int number, int size){
    
    for(int i = 0; i < size; i++){
        if(number == list[i]){
            return false;
        }
    }
    
    
    return true;
}


void numberToArr(int number, int *arr, int numberSize){
    

    for(int i = numberSize-1; i > -1; i--){
        arr[i] = number % 10;
        number /= 10;
    }
    
}


bool isNumberValid(int number){
    int numberArr[NUMBERSIZE];

    numberToArr(number, numberArr, NUMBERSIZE);

    for(int i = 0; i < NUMBERSIZE-1; i++){
        for(int j = i+1; j < NUMBERSIZE; j++){
            
            if(numberArr[i] == numberArr[j]){
                return false;
            }
        }
    }

    return true;
}

int plusComparison(int arr1[], int arr2[], int size){
    int total = 0;

    for(int i = 0; i < size; i++){
        if(arr1[i] == arr2[i]){
            total++;
        }
    }

    return total;
}

int minusComparison(int arr1[], int arr2[], int size){
    int total = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr1[i] == arr2[j] && arr1[i] != arr2[i]){
                total++;
            }
        }
    }

    return total;
}


int digitCount(int number){
    if(number == 0){
        return 1;
    }
    return (int)log10(number)+1;

}

int numberGenerator(){
    srand(time(NULL));
    

    int lnum[4];

    int fdigit = (rand() % 9) + 1;

    int number = fdigit;

    lnum[0] = fdigit;

    for(int i = 1; i < NUMBERSIZE; i++){
        number *= 10;

        int newdigit = rand() % 10;
        for(;!checkNotRepeating(lnum, newdigit, i); newdigit = rand() % 10);

        lnum[i] = newdigit;

        number += newdigit;
    }


    return number;
}

bool inList(int number, int list[]){
    for(int i = 0; list[i] != 0; i++){
        if(number == list[i]){
            return true;
        }
    }
    return false;
}

void fillIntArr(int arr[], int fillNumber, int size){
    for(int i = 0; i < size; i++){
        arr[i] = fillNumber;
    }

}


int takeGuess(int guessList[]){
    int guess;

    while(!isNumberValid(guess) || digitCount(guess) != NUMBERSIZE || inList(guess, guessList)){
        scanf("%d", &guess);
        
        //warning messages

        //its not 4 digit
        if(digitCount(guess) != NUMBERSIZE){
            printf("Your number must be %d digit\n", NUMBERSIZE);
            continue;
        }
        
        //its not repeating
        if(!isNumberValid(guess)){
            printf("Your number mustn't repeating, must be valid number\n");
            continue;
        }

        //its already guessed
        if(inList(guess, guessList)){
            printf("You already guessed same number\n");
            continue;
        }

    }

        //valid guess
    return guess;
}

#endif

