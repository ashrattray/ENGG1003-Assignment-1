#include <stdio.h>
#include <string.h>

/*The following function takes a single letter input into the string 'word' from a file opened within main and encrypts it according to
the key specified by the user (which was stored in k). The function continues to read the file letter by letter and returning the 
encryption until it reaches the end of the file, which is specified in the while loop found within main () case 4. This function takes the inputs 
of the char string 'word', which contains at each call only one character found within the text file 'input.txt', and the key for the rotational 
encryption as an integer which is inputted within the main.c and also passed to this function. There is no while loop in this statement, as only one 
character is present to be ecnrypted and is located at the first point 0 in the string 'word', indicated by the initialisation of the counter i as 0 
which remains as zero. Rather than a loop, each if statement is separately tested to see which condition the single character applies to, and only that 
process of encryption is used. Therefore, this function only returns the string 'word' containing only the single encrypted letter to be printed within 
main.c. Data type restrictions are that the character must be a char, and the key must be a number. */
 
char Rtencrypt(char *word, int k) {
    
    int i = 0; 
    
    
    /* the first if statement defines that if the character
    is one of punctuation, i.e. an apostrophe or space (ACSII Codes below 64), than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i];
           }
    /* This following else if defines how the letter is rotated by the key, being that the ACSII code 
    will have k added to it to make that letter the letter designated to the new ACSII code (going from A-Z)*/
           else if ((word[i] + k) < 91 && (word[i] >64)) {
                word[i] = (word[i] + k);
            }
    /* This last else if defines that if a letter is to rotate past Z, that the ACSII code will loop
    back around to A rather than to the following symbols who's codes are consecutively after Z
    The minus 26 ensures the ACSII code stays within the bounds of the capital alphabet, while maintaining
    the correct ciphering method and key*/
            else if ((word[i] + k)>90) {
                word[i] = ((word[i] -26) + k);
            }
    
    

  return *word;  /* returns the encrypted character back to main() to be printed*/
}