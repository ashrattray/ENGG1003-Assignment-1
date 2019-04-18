#include <stdio.h>
#include <string.h>

char Stdecrypt(char *word, char *ciphertext) {
    
    int k=0; /* This initialised the counter k to zero so that each consecutive letter in the string 'ciphertext' can be tested against 
                    the letter in the string 'word'. */      
    int i=0; // initialises the function to read only the first value within the string 'word', as the text from the file is read one letter at a time 
        
    /* this if statement defines that if a character
    of punctuation is read, i.e. an apostrophe, than it will be returned unchanged within this function*/
    if(word[i] < 64){
        word[i] = word[i]; 
        
        return *word; 
    }
      
    while (k<27) {
    /* This else if statement states that if the ACSII code of the letter located at i in the string 'word' matches 
    that of the ACSII code located at k in the string 'ciphertext', that it must be changed to the corresponding 
    initial letter of the alphabet by taking the location of k ( which corresponds to location of the original letter 
    - the k location of the original alphabet - and add 65 to it to determine the original letter. 65 is the distance between the 
    ACSII numbers 0-25 and the corresponding letters of the alphabet. i.e. if location k = 0, the location of A is also zero and therefore
    the k located letter is A, and the ACSII code of A is 65, then the addition of 65 will print this. This is true for all 
    letters and locations in this program. */
        if (word[i] == ciphertext[k]) {
            word[i] = (k + 65);
            
            return *word; /* This returns the decrypted letter to be printed back within main.c */
        }
    /* This else if statement states that if the ACSII code of the letter located at i in the string
    'word' does not match the ACSII code at k location of the string 'ciphertext', then the location counter 
    k will increase by 1 until the matching code (and therefore letter) is found. */
           
        else if (word[i] != ciphertext[k]) {
            k++; // this increases the value of the counter k to move to the next consecutive location and letter of the string 'ciphertext'. 
           }
    }  
    
    return 0;

} // end of function DONT DELETE 