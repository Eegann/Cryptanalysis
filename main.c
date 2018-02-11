//
// Created by Alexandre Heintzmann on 11/02/2018.
//
// This code can decipher a text, knowing the key and the algorithm.

#include <stdio.h>
#include <stdlib.h>
#include "includes/algorithms.h"
void main(){
    char *text, *key, choice;

    //Allocation memory for the variables text and key.
    text=(char*)malloc(sizeof(char)*1000);
    key=(char*)malloc(sizeof(char)*20);

    //Asking for the text and the key.
    printf("Insert the text (1000 char max)\n:");
    fgets(text, 1000, stdin);

    printf("Insert the key (20 char max)\n:");
    fgets(key, 20, stdin);

    //Asking for which algorithm to use.
    printf("Chose an algorithm: Vigenere v\n");
    fflush(stdin);
    scanf("%c", &choice);
    switch(choice){
        case 'v':
            decipher_vigenere(text,key);
            break;
        default:
            printf("Choice doesn't exist");
            exit(1);
    }
    free(text);
    free(key);
}