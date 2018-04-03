//
// Created by Alexandre Heintzmann on 03/04/2018.
//
// Transposition cipher: https://en.wikipedia.org/wiki/Transposition_cipher

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cipher_transposition(char* text, char* key){
    int textsize, keysize, i, j, difference, column, keyvalue;
    keysize=strlen(key)-1;
    textsize=strlen(text)-1;
    difference=textsize%keysize;
    keyvalue=atoi(key);
    //Add '*' at the end of the text so the text fits a matrix.
    for(i=0;i<difference;i++){
        text[textsize+i]='*';
    }
    //Fill the matrix with the text.
    char matrix[keysize][textsize/keysize];
    for(i=0;i<textsize/keysize;i++){
        for (j=0;j<keysize;j++){
            matrix[j][i]=text[j+i*keysize];
        }
    }

    //Change the order of the letters, adding letters from the top to the bottom of the matrix
    for(i=0;i<keysize;i++){
        //Value of the key for this column.
        column=keyvalue%10;
        for(j=0;j<textsize/keysize;j++){
            text[(column-1)*textsize/keysize+j]=matrix[keysize-i-1][j];
        }
        keyvalue/=10;
    }
    return text;

}

char* decipher_transposition(char* text, char* key){
    int textsize, keysize, i, j, column, keyvalue;
    textsize=strlen(text)-1;
    keysize=strlen(key)-1;
    keyvalue=atoi(key);

    //Fill the matrix with the text.
    char matrix[keysize][textsize/keysize];
    for(i=0;i<textsize/keysize;i++){
        for (j=0;j<keysize;j++){
            matrix[j][i]=text[i+j*textsize/keysize];
        }
    }

    //Change the order of the letters, adding letters from the left to the right of the matrix.
    for(i=0;i<keysize;i++){
        //Value of the key for this column.
        column=keyvalue%10;
        for(j=0;j<textsize/keysize;j++){
            text[column-1+j*keysize]=matrix[keysize-1-i][j];
        }
        keyvalue/=10;
    }

    return text;
}