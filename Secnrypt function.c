#include <stdio.h>
#include <string.h>

char Sencrypt(char *word){
    
    unsigned char i = 0;
    char ciphertext[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int k = 0; 


        printf("%s\n", word);
        
        while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; 
               printf("%c", word[i]);
           }
           
           else if(word[i] > 64 ) { 
               k = (word[i] - 65); 
               word[i] = ciphertext[k]; //iuehrgiuher
               i++;
           } 
        
    } /* end of while statement so dont delete */

    
    return *word; 
    
}