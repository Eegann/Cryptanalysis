//
// Created by Alexandre Heintzmann on 13/02/2018.
//
//Vigenere algorithm:
//Each letters of the key correspond to a shift to the right. a=0, b=1, c=2...
//You change each letter in the text by the letter at their position+the shift, in the alphabet.
//text=exemple, key=abc
//e+0=e, x+1=y, e+2=g, m+0=m, p+1=q, l+2=n, e+0=e
//=> eygmqne

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/variables.h"


char* decipher_vigenere(char* text, char* key){
    int keysize, textsize, i, j, newposition;
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