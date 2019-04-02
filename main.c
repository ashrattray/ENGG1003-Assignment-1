#include<stdio.h>

// the code below currently is acting as a quick 'base' code of a function designed to encrypt the single word "HELLO"
// this code has not yet been set with the maths needed to actually encrypt the word yet.... 

char encrypt(char *word); // this is the prototype for the function that will handle encrypting the word

int main() 
{ 
    char word[] = "HELLO"; // the string defining the hardcoded word to be encoded via. the function

        encrypt(word); // the line of code indicating the string 'word' will be used in the encrypt function. 
    
    return 0; 
}

//hello world

// the following function will define how the word is encrypted using a rotation cipher
char encrypt(char *word) {
    char i; // a counter to only encrypt the number of letters within the string word[]
    int k = 4; // this is the 'key', being the number of 'shifts' the letter will move - this will rotate 3 letters 

        for(i=0; i<5; i++){
            word[i] = word[i] + k; // this applies the 3 step rotation
            printf("%c", word[i]); 
        }    
    return 0;
}
