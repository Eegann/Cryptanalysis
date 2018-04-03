//
// Created by Alexandre Heintzmann on 13/02/2018.
//
//Vigenere cipher: https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher

#include <stdio.h>
#include <string.h>
#include "../includes/variables.h"


char* decipher_vigenere(char* text, char* key){
    int keysize, textsize, i, j, newposition;

    //-1 because the last char is \0
    keysize=strlen(key)-1;
    textsize=strlen(text)-1;
    int differences[keysize];

    //We put in differences the shift for each character of the key.
    for(i=0;i<keysize;i++){
        for(j=0;j<26;j++){
            if(letters[j]==key[i]){
                differences[i]=j;
                break;
            }
        }
    }

    //We change the text with the shifts. The shift is done on the left when deciphering.
    for(i=0;i<textsize;i++){
        for(j=0;j<26;j++){
            if(text[i]==letters[j]){
                //i%keysize because differences is as long a key, and the key is shorter than the text.
                //%26 because there are 26 letters in the alphabet.
                newposition=(j-differences[i%keysize])%26;
                text[i]=letters[newposition];
                break;
            }
        }
    }
    return text;
}

char* cipher_vigenere(char* text, char* key){
    int keysize, textsize, i, j, newposition;

    //-1 because the last char is \0
    keysize=strlen(key)-1;
    textsize=strlen(text)-1;
    int differences[keysize];

    //We put in differences the shift for each character of the key.
    for(i=0;i<keysize;i++){
        for(j=0;j<26;j++){
            if(letters[j]==key[i]){
                differences[i]=j;
                break;
            }
        }
    }

    //We change the text with the shifts. The shift is done on the right when ciphering.
    for(i=0;i<textsize;i++){
        for(j=0;j<26;j++){
            if(text[i]==letters[j]){
                //i%keysize because differences is as long a key, and the key is shorter than the text.
                //%26 because there are 26 letters in the alphabet.
                newposition=(j+differences[i%keysize])%26;
                text[i]=letters[newposition];
                break;
            }
        }
    }
    return text;
}