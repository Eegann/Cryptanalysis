//
// Created by Alexandre Heintzmann on 11/02/2018.
//
// This code can encrypt and decipher a text, knowing the key and the algorithm.

#include <stdio.h>
#include <stdlib.h>
#include "includes/algorithms.h"
void main(){
    char *text, *key, action, choice;

    //Allocation memory for the variables text and key.
    text=(char*)malloc(sizeof(char)*1000);
    key=(char*)malloc(sizeof(char)*20);


    //Asking for the text and the key.
    printf("Insert the text (1000 char max)\n:");
    fgets(text, 1000, stdin);

    printf("Insert the key (20 char max, must be an integer if using Caesar algorithm)\n:");
    fgets(key, 20, stdin);

    //Asking for which algorithm to use.
    printf("Chose an algorithm: Caesar c, Vigenere v, Self-encryption s\n");
    fflush(stdin);
    scanf("%c", &choice);

    //Asking for an action.
    printf("Chose an action: encrypt e, decipher d\n");
    fflush(stdin);
    scanf("%c", &action);


    //Selecting the right algorithm depending on the previous choices.
    switch(action){
        case 'e':
            switch(choice){
                case 'v':
                    printf("%s", cipher_vigenere(text,key));
                    break;
                case 'c':
                    printf("%s", cipher_caesar(text, atoi(key)));
                    break;
                case 's':
                    printf("%s", cipher_self_encryption(text, key));
                    break;
                default:
                    printf("Algorithm doesn't exists\n");
            }
            break;

        case 'd':
            switch(choice){
                case 'v':
                    printf("%s", decipher_vigenere(text, key));
                    break;
                case 'c':
                    printf("%s", decipher_caesar(text, atoi(key)));
                    break;
                case 's':
                    printf("%s", cipher_self_encryption(text, key));
                    break;
                default:
                    printf("Algorithm doesn't exists\n");
            }
            break;

        default:
            printf("Action doesn't exist\n");
    }
    //Free the allocated memory.
    free(text);
    free(key);
}