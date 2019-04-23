#include <stdio.h>
#include <string.h>

/* The following function defines how a given cipher word encrypted via. rotational cipher can be decrypted if given the key. This function tales 
the char string 'word' passed from main.c, and then reads an integer k from the user to be used as the given key for the decryption. This must 
be an integer, as its data type is int. This function also used an unsigned char counter i in order to signify the location of the letter being 
used in the decryption and consecutively decrypt letters within the word 'string'. The inputted key is then used in the decryption similarly to 
the rencrypt function, however the value of k is removed from the ACSII code of the word[i} letter in order to make the letter the one k values 
before it in the alphabet, which should be the initial letter before the text was encrypted. This is done until the while loop reads the value of 
word [i] to be 0, which indicates the end of the string and then indicates to the program to return the decrypted string 'word' back to the main.c to be printed */
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
           
    /* the first if statement in this while loop defines that if a character that is NOT a capital letter with ACSII code above 64 (such as
    punctuation) is entered, i.e. an apostrophe, than it will be left unchanged within this function. this is defined by any characters 
    with ACSII codes which are below 64, as all these characters are either punctuation, spaces, numbers, lower case letters (which were previously 
    converted to uppercase and therefore shouldn't be found) or other symbols that are not letters. */
           if(word[i] < 64){
               i++; //increments i to decrypt the next letter found within the string 'word'
           }
    /* this else if statement defines that the ASCII code of each letter is found within the bounds of the capital alphabet, then it is 
    taken and has the inputted key minused from it in order to achieve the initial ACSII code (before encryption) and 
    replaces the letter within the string with the corresponding initial letter */
            else if ((word[i] - k )>= 65) {
                word[i] = (word[i] - k);  
              i++; //increments i to decrypt the next letter found within the string 'word'
            }
    /* this final else if statement defines that if the ACSII code goes below those associated to capital letters (being A), 
    it will rotate the ACSII code back to that associated with Z in order for the original letter to still be found. The plus 
    26 within thise statement accounts for this and keeps the ACSII code within the order and bounds of the capital alphabet*/
            else if ((word[i] - k)<66) {
                word[i] = ((word[i] - k) +26);
                i++; //increments i to decrypt the next letter found within the string 'word'
            }
        }
     
    return *word; //returns the decrypted string back to the main.c function to be printed. 
}
