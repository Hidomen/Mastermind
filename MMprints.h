#include <stdio.h>



#include "MMfuncs.h"




#define NUMBERSIZE 4

#ifndef _INC_MMPRINTS // include guard for 3rd party interop
#define _INC_MMPRINTS



void introScreen(){
    printf("Welcome to the Mastermind Tournament.\n");
    printf("to start sign the paper with your name.\n");
    //tur limitiyle zorlaştırıp turnuvaya çevirme
}


void printRules(){
    printf(":RULES:\n");
    printf("* Your goal is find the secret number that is %d digit and valid (not repeating) number.\n", NUMBERSIZE);
    printf("Each round is getting harder because guess limit decreasing. After winning all enemies, you shall be the master of mastermind!!\n");
    printf("Your name will be written to history with golden letters.\n");
    printf("Anyways, after being the champion you decide a number to put it on to 'BOOK OF MASTER NUMBERS'.\n");
    printf("And you can see how many people tried to find your number and how many attempt taken for each player.\n");
}

// void numberToArr(int number, int *arr, int numberSize){
    

//     for(int i = numberSize-1; i > -1; i--){
//         arr[i] = number % 10;
//         number /= 10;
//     }
    
// }




void printstr (char* str){

    int size = 0;
    for(size = 0; str[size] != 0; size++);


    for(int i = 0; i < size; i++){

        printf("%c", str[i]);
    }
}

void printstrl (char *str, int size){
    for(int i = 0; i < size; i++){
        printf("%c", str[i]);
    }
}

#endif