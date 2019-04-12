#include <stdio.h>
#include <string.h>

char Sdecrypt(char *word) {
    
    unsigned char i = 0;
    char ciphertext[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int k = 0; 
    
        while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; 
           }
           
           else if (word[i] == ciphertext[k]) {
               word[i] = (k + 65);
               i++;
               k=0;
           }
           
           else if (word[i] != ciphertext[k]) {
               k++; 
           }
        }
    return *word; 
} //this is the end of the function so DONT FUCKEN DELETE IT