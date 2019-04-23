#include <stdio.h>
#include <string.h>

/* The following function defines how the program will decrypt a given encrypted word when not given the key for the number of rotations. 
This is done by initialising the key value k to one, and increasing this at the end of every loop until the user indicates that the decryption 
is correct with a particular key value. This function takes the inputed text in the string 'word' passed from the main.c function, and the value of n 
, being the number of characters in the encryption to be used as the condition within the while loops for flow control,  as well 
as the initialised k as 1 to begin testing different keys in decryption. It also uses the unsigned char i to be used as a position pointer within
reading the string 'word' to consecutively decrypt the string once the correct key is found and indicated to be correct by the user. This function worls 
the same as the rkdecrypt function for decryption of a rotational cipher when given the key. This program is best used to decrypt a single word from a passage 
to find the key, as it will have a little number of characters, and then this found key can be used in either the function for decrypting a rotational cipher with the 
key, or in the decryption of text read from a file when the key is known. This function does not have any return values, as the decrypted text is printed within it in 
order to allow for the use of the switch statement to define whether the decryption is correct or not, and allow the new values of k to be used 
within the same decryption while loop. If the string 'word' was returned to main.c each time to be printed and ask the user if it is correct, the code would be 
incredibly more complicated and likely contain more bugs. This function has only one data type restriction, which is that the character inputted into the switch statement 
must be an integer, as described by the initialisation as int for r. */

char Rdecrypt(char *word, int n){
    unsigned char i = 0; /*again, this is a counter in order to only decrypt each letter of the word once before moving on to the next consecutive letter */
    int k = 1;  /* this is again acting as the key given which will be used to decrypt the given encryption, initialised to one so that each consecutive 
                key value in the decryption loop can be tested*/
    int r = 0; /* This variable will be used to determine whether the user wishes to decrypt again with the new key or to exit 
    the program if given the right word*/

    /* The below code is very similar to the code used for dencryption with a rotational cipher. 
    However, this time the key number is initialised as one, and the use will be asked after the decryption of key 1
    if the word is correct.If they input no, th e key will increase by one and the process will be repeated with the 
    next consecutive key until it is indicated that the word is correct. */
       
       while (i<=n) {
           
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(i<n && word[i] < 64){
               printf("%c", word[i]);
               i++; //increments the pointer value of i to consecutively decrypt each letter in the string 'word'
           }
    /* this else if statement defines that the ASCII code of each letter is taken and has the inputted
    key minused from it in order to achieve the initial ACSII code (before encryption) and 
    printing the corresponding initial letter to the screen*/
            else if (i<n && (word[i] - k )>= 65) {
                word[i] = (word[i] - k);  
                printf("%c", word[i]);
              i++; //increments the pointer value of i to consecutively decrypt each letter in the string 'word'
            }
    /* this final else if statement defines that if the ACSII code goes below those associated to capital letters (being A), 
    it will rotate the ACSII code back to that associated with Z in order for the original letter to still be found. The plus 
    26 within thise statement accounts for this and keeps the ACSII code within the order and bounds of the alphabet*/
            else if (i<n && (word[i] - k)<66) {
                word[i] = ((word[i] - k) +26);
                printf("%c", word[i]);
                i++; //increments the pointer value of i to consecutively decrypt each letter in the string 'word'
            }
    /* This final else if statement states that if the deryption is complete, the user is printed a statement 
    to ask them whether the correct word has been deciphered. If it has not, the user inputs "1" to activate 
    the case 1 switch statement, which will reset the word and attempt to decipher with the next consecitive key 
    value. This can be repeated as many times as needed in order to find the correct key to decipher the correct word*/
            else if(i==n) {
                printf("\n");
                printf("Key = %d \n", k); /*This line prints the key used to decipher the text */
                printf("\nInsert 1 to decrypt again and 2 to exit: ");
                scanf("%d", &r); //reads the choice of whether the user wishes to continue (1) or quit (2) to store in r to be used to determine which switch statement the program directs to. 
                 
    /* The following swtich statement takes the user's inputed value of r and determines which step the program needs to 
    take next. if the user inputs the value 1 into r, it indicates the decrypted word is incorrect, and the program will 
    run the case 1 definition. This which will reset the found decrypted word back to the initial word, and increase the 
    value of the "key" (k) to be used in the initial decryption loop. This can be done as many times as needed to find the 
    correct word and key. If the user inputs the value "2", meaning the deciphered word found by the program is correct.
    it will indicate to the program that it needs to run the switch case 2 statement, which tells it tp exit*/    
                
             switch(r){
                 
    /* The case 1 within the switch statement takes the inputed value of r inputed as 1 and indicates to the program
    that the decryption needs to be repeated, and handles the process needed for the next encryption to occur. */
                  
                  case 1:
                        i=0; /* This line resets the counter value of i to zero in order to return the initial
                            input word needed to be decrypted. The following while loop handles this */
                        
    /* This while statement sets the first decrypted word back to the original cipher word in order to test     
    the original input with the decryption using the nect consecutive key value when the user inserts "1" 
    to indicate the previous decryption word was incorrect*/
                            while (i<n) {
                                         
    /* the first if statement in this while loop defines that if a character of punctuation is entered, 
    i.e. an apostrophe, than it will remain unchanged*/
                                if(word[i] < 64){
                                    i++; 
                                }
                                
                                else {
                                    word[i] = word[i] + k;
                                    i++;
                                }
                            }
                        i=0; /* This setting of i to zero again resets the counter of each letter in the word to zero in order 
                                for the initial while loop for this decryption to again be able to decrypt each letter of the 
                                word with the new value of k defined in the following line */
                        k++; /* This increases the value of the key "k" to the next consecutive number to test the next 
                                consecutive key*/ 
                    break;
                    
    /* Case 2 within the switch statement indicates to the program that when the user inputs "2" into r, that it has deciphered
    the correct word and tells it to exit. This ends the program and decryption process*/                     
                    
                    case 2:
                    
                        return 0;
                 }
            }
        }
         printf("\n");
     
    return 0; 
}