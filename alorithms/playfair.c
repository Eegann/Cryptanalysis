//
// Created by Alexandre Heintzmann on 04/03/2018.
//


#include <stdio.h>
#include <string.h>
#include "../includes/variables.h"

//This function replace all the j's by i's in the string text.
char* replace_j_i(char * text){
    int i;
    for(i=0;i<strlen(text)-1;i++){
        if(text[i]=='j'){
            text[i]='i';
        }
    }
    return text;
}

char* cipher_playfair(char* text, char* key){
    int keysize, textsize, i, j, k, x1, y1, x2, y2, exist, nbletters;
    char  keymatrix[5][5];
    nbletters=0;
    //We replace all the j's by i's so we will only have 25 letters so it will fit the matrix.
    text=replace_j_i(text);
    key=replace_j_i(key);
    keysize=strlen(key)-1;
    textsize=strlen(text)-1;

    //Add an x at the end of the text if the number of letters isn't even.
    if(textsize%2!=0){
        text[textsize]='x';
        text[textsize+1]='\0';
        textsize++;
        printf("%s", text);
    }



    //Adding the letters of the key in the matrix. A same letter cannot occur twice in the matrix.
    for(i=0;i<keysize;i++){
        exist=0;
        for(j=0;j<i;j++) {
            if (key[i] == key[j]) {
                exist = 1;
                break;
            }
        }

        if(exist==0){
            keymatrix[nbletters/5][nbletters%5]=key[i];
            nbletters++;
        }
    }

    //Adding the other letters of the alphabet (but j) to the matrix. A same letter cannot occur twice in the matrix.
    while(nbletters<25){
        for(j=0;j<26;j++){
            if(strchr(key,letters[j])==NULL&&letters[j]!='j'){
                keymatrix[nbletters/5][nbletters%5]=letters[j];
                nbletters++;
            }
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%c ", keymatrix[i][j]);
        }
        printf("\n");
    }

    //Changing the letters of the text by the corresponding letters on the matrix.
    for(i=0;i<textsize;i=i+2){
        for(j=0;j<5;j++){
            for(k=0;k<5;k++){
                if(keymatrix[j][k]==text[i]){
                    x1=j;
                    y1=k;
                    break;
                }
            }
        }
        for(j=0;j<5;j++){
            for(k=0;k<5;k++){
                if(keymatrix[j][k]==text[i+1]){
                    x2=j;
                    y2=k;
                    break;
                }
            }
        }
        if(x1==x2){
            text[i]=keymatrix[x1][(y1+1)%5];
            text[i+1]=keymatrix[x2][(y2+1)%5];
        }
        else if(y1==y2){
            text[i]=keymatrix[(x1+1)%5][y1];
            text[i+1]=keymatrix[(x2+1)%5][y2];
        }
        else{
            text[i]=keymatrix[x1][y2];
            text[i+1]=keymatrix[x2][y1];
        }
    }

    return text;
}

char* decipher_playfair(char* text, char* key){
    int keysize, textsize, i, j, k, x1, y1, x2, y2, exist, nbletters;
    char  keymatrix[5][5];
    nbletters=0;
    keysize=strlen(key)-1;
    textsize=strlen(text)-1;

    //Adding the letters of the key in the matrix. A same letter cannot occur twice in the matrix.
    for(i=0;i<keysize;i++){
        exist=0;
        for(j=0;j<i;j++) {
            if (key[i] == key[j]) {
                exist = 1;
                break;
            }
        }

        if(exist==0){
            keymatrix[nbletters/5][nbletters%5]=key[i];
            nbletters++;
        }
    }

    //Adding the other letters of the alphabet (but j) to the matrix. A same letter cannot occur twice in the matrix.
    while(nbletters<25){
        for(j=0;j<26;j++){
            if(strchr(key,letters[j])==NULL&&letters[j]!='j'){
                keymatrix[nbletters/5][nbletters%5]=letters[j];
                nbletters++;
            }
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%c ", keymatrix[i][j]);
        }
        printf("\n");
    }

    //Changing the letters of the text by the corresponding letters on the matrix.
    for(i=0;i<textsize;i=i+2){
        for(j=0;j<5;j++){
            for(k=0;k<5;k++){
                if(keymatrix[j][k]==text[i]){
                    x1=j;
                    y1=k;
                    break;
                }
            }
        }
        for(j=0;j<5;j++){
            for(k=0;k<5;k++){
                if(keymatrix[j][k]==text[i+1]){
                    x2=j;
                    y2=k;
                    break;
                }
            }
        }
        if(x1==x2){
            text[i]=keymatrix[x1][(y1+4)%5];
            text[i+1]=keymatrix[x2][(y2+4)%5];
        }
        else if(y1==y2){
            text[i]=keymatrix[(x1+4)%5][y1];
            text[i+1]=keymatrix[(x2+4)%5][y2];
        }
        else{
            text[i]=keymatrix[x1][y2];
            text[i+1]=keymatrix[x2][y1];
        }
    }
    
    return text;
}

