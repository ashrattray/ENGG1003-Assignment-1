#include <stdio.h>


char Rtkdecrypt(char *word, int k) {
    
    int i = 0; 
/* The below code is very similar to the code used for encryption with a rotational cipher. 
    However, this time the key number will be removed from the current letters in order to see from 
    which position they were moved from, and therefore print the original word*/
           
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){ 
           }
    /* this else if statement defines that the ASCII code of each letter is taken and has the inputted
    key minused from it in order to achieve the initial ACSII code (before encryption) and 
    replaces the letter within the string with the corresponding initial letter */
            else if ((word[i] - k )>= 65) {
                word[i] = (word[i] - k);  
            }
    /* this final else if statement defines that if the ACSII code goes below those associated to capital letters (being A), 
    it will rotate the ACSII code back to that associated with Z in order for the original letter to still be found. The plus 
    26 within thise statement accounts for this and keeps the ACSII code within the order and bounds of the capital alphabet*/
            else if ((word[i] - k)<66) {
                word[i] = ((word[i] - k) +26);
            }
     
    return *word; 
}