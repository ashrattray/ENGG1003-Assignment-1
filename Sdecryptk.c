#include <stdio.h>
#include <string.h>

char Sdecryptk(char *word, char *unknownkey) {
    unsigned char i = 0; /*Counter used to keep track of which letter (position) of the string 'word'
                        in which the program is decrypting in order to not decrypt the same letter twice. */
    int k = 0; /*Counter for the ciphertext string used to rotate through each value until the program reaches 
                the one matching the 'word' i located letter, and the value of k can then be used to determine the original letter 
                of the alphabet. */

    
    while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; 
           }
    /* This else if statement states that if the ACSII code of the letter located at i in the string 'word' matches 
    that of the ACSII code located at k in the string 'ciphertext', that it must be changed to the corresponding 
    initial letter of the alphabet by taking the location of k ( which corresponds to location of the original letter 
    - the k location of the original alphabet - and add 65 to it to determine the original letter. 65 is the distance between the 
    ACSII numbers 0-25 and the corresponding letters of the alphabet. i.e. if location k = 0, the location of A is also zero and therefore
    the k located letter is A, and the ACSII code of A is 65, then the addition of 65 will print this. This is true for all 
    letters and locations in this program. */
           else if (word[i] == unknownkey[k]) {
               word[i] = (k + 65);
               i++; /* this increases the counter, and therefore location, of the string 'word' when the correct corresponding 
                        letter in the string 'countertext' is found as the while statement can then move forward to 
                        decrypting the next letter in the string 'word'. */
               k=0; /* This sets the counter k back to zero so that each consecutive letter in the string 'ciphertext' can be tested against 
                    the next letter in the string 'word'. */
           }
    /* This else if statement states that if the ACSII code of the letter located at i in the string
    'word' does not match the ACSII code at k location of the string 'ciphertext', then the location counter 
    k will increase by 1 until the matching code (and therefore letter) is found. */
           
           else if (word[i] != unknownkey[k]) {
               k++; // this increases the value of the counter k to move to the next consecutive location and letter of the string 'ciphertext'. 
           }
        }
    
   return *word;  
    
} //end of function don't delete 