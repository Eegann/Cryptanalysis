#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


//Vigenere:
//Each letters of the key correspond to a shift to the right. a=0, b=1, c=2...
//You change each letter in the text by the letter at their position+the shift, in the alphabet.
//text=exemple, key=abc
//e+0=e, x+1=y, e+2=g, m+0=m, p+1=q, l+2=n, e+0=e
//=> eygmqne
char* decipher_vigenere(char* text, char* key){
    int sizekey, sizetext, i, j, newposition;
    sizekey=strlen(key)-1;
    sizetext=strlen(text)-1;
    int differences[sizekey];

    for(i=0;i<sizekey;i++){
        for(j=0;j<26;j++){
            if(letters[j]==key[i]){
                differences[i]=j;
                break;
            }
        }
    }

    for(i=0;i<sizetext;i++){
        for(j=0;j<26;j++){
            if(text[i]==letters[j]){

                //i%sizekey because the text is longer than the key.
                //%26 because there are 26 letters in the alphabet.
                newposition=(j-differences[i%sizekey])%26;
                text[i]=letters[newposition];
                break;
            }
        }
    }
    return text;
}