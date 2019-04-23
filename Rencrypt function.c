#include <stdio.h>
#include <string.h>

/* the following function will define how the word is encrypted using a rotation cipher. This function takes the input 
string 'word' passed from the main.c file, and further prompts for the input of an integer k to be used as the rotational 
key for the encryption process. It also initialises a char i to be used as a position indicator within the string 'word', 
used as a counter to consecutively encrypt letters within the string. The function takes the ACSII code of each letter within 
the string 'word' and adds the rotational key to it, making it therefore become the letter k ACSII codes up from it, which is k
letters down the alphabet from the original. After completing the encryption of the entire string 'word', it will pass this string 
holding the encryption back to the main.c function to be printed. The data type restrictions include that the key must be an integer, 
and the counter i must be a char in order to be used within the char string initialisation. Other than this, the string 'word' is intially 
given a much larger than needed memory designation for any phrases which may be inputted. */
char Rencrypt(char *word) {
    unsigned char i = 0; // a counter to consecutively encrypt the letters within the inserted word 
    int k = 0; // this is the 'key', being the number of 'shifts' the letter will move - this will rotate k letters 

        printf("Insert key for rotation:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
        scanf("%d", &k); /* Scans the key from the user and stores it within k to be used as a key.*/
        
    /* the below code takes each character from the string and moves its value to an ACSII character k steps down in the alphabet
    and prints each value as it is determined before increasing the value of the i counter to determine the next character in the string (next letter)
    If the ACSII characters go beyond Z with this rotation, they are rotated back to A etc as per how rotation ciphers work. The condition for the while loop
    states that if the word is not at the end of the string (which is when the the word[i] input is 0, as 0 indicates the end of a string) then it will undergo 
    the process within the while loop, however if it does reach the ending 0 value, the while loop will exit and initiate the passing back of the string 'word' 
    to the main.c function. */
     
       while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character is entered that lies below the bounds of the capital alphabet then it indicates 
    that it is a character of punctiation that has been entered i.e. the ACSII code is below 64 and is therefore punctuation such as an apostrophe or space, then it
    will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; //increments i to encrypt the next letter stored within the string 'word'
           }
    /* This following else if defines how the letters are rotated by the key, being that the ACSII code 
    of each will have k added to it to make that letter the letter designated to the new ACSII code (going from A-Z)*/
           else if ((word[i] + k) < 91 && (word[i]) >64) {
                word[i] = (word[i] + k); 
              i++; //increments i to encrypt the next letter stored within the string 'word'
            }
    /* This last else if within the loop defines that if a letter is to rotate past Z, that the ACSII code will loop
    back around to A rather than to the following symbols who's codes are consecutively after Z
    The minus 26 ensures the ACSII code stays within the bounds of the capital alphabet, while maintaining
    the correct ciphering method and key*/
            else if ((word[i] + k)>90) {
                word[i] = ((word[i] -26) + k);
                i++; //increments i to encrypt the next letter stored within the string 'word'
            }
        }
     
    return *word; //passes the string 'word' containing the new encrypted ciphertext back to main.c to be printed. 
}
