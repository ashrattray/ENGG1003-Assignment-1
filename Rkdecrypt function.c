#include <stdio.h>
#include <string.h>

/* The following function defines how a given cipher word encrypted via. rotational cipher can be 
decrypted if given the key */
char Rkdecrypt(char *word){
    unsigned char i = 0; /*again, this is a counter in order to only decrypt each letter of the word once before moving on to the next consecutive letter */
    int k = 0;  /* this is again acting as the key given which will be used to decrypt the given encryption */
   
    
        printf("Insert given key for number of rotations: "); /*given the key for the number of rotations initially used to encrypt 
        the word allows the decrypt program to move the same key of rotations backwards to achieve the initial letters*/
        scanf("%d", &k); 

    /* The below code is very similar to the code used for encryption with a rotational cipher. 
    However, this time the key number will be removed from the current letters in order to see from 
    which position they were moved from, and therefore print the original word*/
       
       while (word[i] != 0) {
           
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               i++; 
           }
    /* this else if statement defines that the ASCII code of each letter is taken and has the inputted
    key minused from it in order to achieve the initial ACSII code (before encryption) and 
    replaces the letter within the string with the corresponding initial letter */
            else if ((word[i] - k )>= 65) {
                word[i] = (word[i] - k);  
              i++;
            }
    /* this final else if statement defines that if the ACSII code goes below those associated to capital letters (being A), 
    it will rotate the ACSII code back to that associated with Z in order for the original letter to still be found. The plus 
    26 within thise statement accounts for this and keeps the ACSII code within the order and bounds of the capital alphabet*/
            else if ((word[i] - k)<66) {
                word[i] = ((word[i] - k) +26);
                i++;
            }
        }
     
    return *word; 
}
