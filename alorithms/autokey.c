//
// Created by Alexandre Heintzmann on 01/03/2018.
//
//Autokey cipher : https://en.wikipedia.org/wiki/Autokey_cipher

#include <stdio.h>
#include <string.h>
#include "../includes/variables.h"

char* cipher_autokey(char* text, char* key){
    int keysize, textsize, i, j, newposition;

    //-1 because the last char is \0
    keysize=strlen(key)-1;
    textsize=strlen(text)-1;
    int differences[keysize];

    //We put in differences the shift for each character of the key.
    for(i=0;i<keysize;i++){
        for(j=0;j<26;j++){
            if(key[i]==letters[j]){
                differences[i]=j;
                break;
            }
        }
    }

    //We change the text with the shifts. The shift is done on the right when ciphering.
    for(int i=0;i<textsize;i++){
        for(j=0;j<26;j++){
            if(text[i]==letters[j]){
                //i%keysize because differences is as long a key, and the key is shorter than the text.
                //%26 because there are 26 letters in the alphabet.
                newposition=(j+differences[i%keysize])%26;
                text[i]=letters[newposition];
                //We update the shift we will use next time. The shift is equal to the position of the plain text letter we just shifted.
                differences[i%keysize]=j;
                break;
            }
        }
    }

    return text;
}

char* decipher_autokey(char* text, char* key){
    int keysize, textsize, i, j, newposition;

    //-1 because the last char is \0
    keysize=strlen(key)-1;
    textsize=strlen(text)-1;
    int differences[keysize];

    //We put in differences the shift for each character of the key.
    for(i=0;i<keysize;i++){
        for(j=0;j<26;j++){
            if(key[i]==letters[j]){
                differences[i]=j;
                break;
            }
        }
    }

    //We change the text with the shifts. The shift is done on the left when deciphering.
    for(int i=0;i<textsize;i++){
        for(j=0;j<26;j++){
            if(text[i]==letters[j]){
                //i%keysize because differences is as long a key, and the key is shorter than the text.
                //%26 because there are 26 letters in the alphabet.
                newposition=(j-differences[i%keysize])%26;
                text[i]=letters[newposition];
                //We update the shift we will use next time. The shift is equal to the position of the plain text letter we just shifted.
                differences[i%keysize]=j;
                break;
            }
        }
    }

    return text;
}