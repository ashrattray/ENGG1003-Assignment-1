#include <stdio.h>
#include <string.h>

/* This function defines how a single inputted word from the user will be converted to its QWERTY substitutional cipher word*/

char Sencrypt(char *word){
    
    unsigned char i = 0;
    char ciphertext[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int k = 0; 
        
        while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; 
               printf("%c", word[i]);
           }
    /* This else if statement states that if the letter is a captital letter (as all letetrs are converted to)
    that its ACSII code will be taken and have 65 removed from it in order to make the letter its related number in the 
    ordered alphabet (i.e. A = 1, B = 2) however as strings start at 0, A becomes 0 and B becomes 1 etc. This number is then 
    assignment to the char, k, and the k numbered letter of the string 'ciphertext' is then assigned to the letter in 
    the word string. this replaces the letter with its corresponding QWERTY substitution, and the function then moves on to 
    the next letter to do the same until the word is finished. */
           else if(word[i] > 64 ) { 
               k = (word[i] - 65); 
               word[i] = ciphertext[k]; // letter number 'i' in string 'word' becomes letter number 'k' from string 'ciphertext'
               i++;
           } 
        
    } 

    
    return *word; /* This returns the new cipherword to the original main.c case to be printed */
    
}