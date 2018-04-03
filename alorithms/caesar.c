//
// Created by Alexandre Heintzmann on 13/02/2018.
//
// Caesar cipher: https://en.wikipedia.org/wiki/Caesar_cipher

#include <stdio.h>
#include <string.h>
#include "../includes/variables.h"

char* cipher_caesar(char* text, int key){
    int textsize, i, j;
    textsize=strlen(text);
    //key=0 or key=26*x is the same thing as there are only 26 letters in the alphabet.
    key=key%26;

    //We change each letter with the value of the key. The shift is done on the right when ciphering.
    for(i=0;i<textsize;i++){
        for(j=0;j<26;j++){
            if(letters[j]==text[i]){
                text[i]=letters[(j+key)%26];
                break;
            }
        }
    }
    return text;
}
char* decipher_caesar(char* text, int key){
    int textsize, i, j;
    textsize=strlen(text);

    //We change each letter with the value of the key. The shift is done on the left when deciphering.
    for(i=0;i<textsize;i++){
        for(j=0;j<26;j++){
            if(letters[j]==text[i]){
                text[i]=letters[(j-key)%26];
                break;
            }
        }
    }
    return text;
}

