#include <stdio.h>

/* The following function does the same as the rkdecrypt function, decrypting rotational ciphertext when given
the key, however it reads the input from a file one single character at a time and passes it to this function 
to be decrypted one at a time until the main.c reaches the end of the file. This function takes the string 'word' 
containing only a single character from the file 'input.txt', as well as the integer stored within k to indicate the key 
which was inputted by the user within main.c. This function contains no while loops as only a single character located at 
the initial position 0, indicated by the initialisation of the counter i to 0 which remains unchanged or incremented, is read 
and decrypted according to which if statement it applies to. All other if statements are ignored, and the function 
returns the string 'word', containing only a single decrypted character, back to the main.c in order to be printed and 
the next character to be read and passed to this function, until the end of the file is reaches. Data restrictions are that 
they inserted key within the main.c must be an integer. */

char Rtkdecrypt(char *word, int k) {
    
    int i = 0; 
/* The below code is very similar to the code used for encryption with a rotational cipher. 
    However, this time the key number will be removed from the current letters in order to see from 
    which position they were moved from, and therefore print the original word*/
           
    /* the first if statement defines that if a character of punctuation is entered, i.e. an apostrophe, 
    than it will be left unchanged within this function*/
           if(word[i] < 64){ 
           }
    /* this else if statement defines that the ASCII code of each letter is taken and has the value of 
    the key minused from it in order to achieve the initial ACSII code (before encryption) and 
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
     
    return *word; // passes the encrypted character back to main.c in order to be printed. 
}