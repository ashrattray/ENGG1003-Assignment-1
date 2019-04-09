#include <stdio.h>
#include <string.h>

/* the following function will define how the word is encrypted using a rotation cipher*/
char Rencrypt(char *word) {
    unsigned char i = 0; // a counter to consecutively encrypt the letters within the inserted word 
    int k = 0; // this is the 'key', being the number of 'shifts' the letter will move - this will rotate k letters 

        printf("Insert key for rotation:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
        scanf("%d", &k);
        
    /* the below code takes each character from the string and moves its value to an ACSII character k steps down in the alphabet
    and prints each value as it is determined before increasing the value of the i counter to determine the next character in the string (next letter)
    If the ACSII characters go beyond Z with this rotation, they are rotated back to A etc as per how rotation ciphers work*/
     
       while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; 
           }
    /* This following else if defines how the letters are rotated by the key, being that the ACSII code 
    of each will have k added to it to make that letter the letter designated to the new ACSII code (going from A-Z)*/
           else if ((word[i] + k) < 91 && (word[i]) >64) {
                word[i] = (word[i] + k); 
              i++;
            }
    /* This last else if within the loop defines that if a letter is to rotate past Z, that the ACSII code will loop
    back around to A rather than to the following symbols who's codes are consecutively after Z
    The minus 26 ensures the ACSII code stays within the bounds of the capital alphabet, while maintaining
    the correct ciphering method and key*/
            else if ((word[i] + k)>90) {
                word[i] = ((word[i] -26) + k);
                i++;
            }
        }
     
    return *word;
}
