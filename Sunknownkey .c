#include <stdio.h>
#include <string.h>

char Sunknownkey(char *word, char *alphabet, char *unknownkey) {
    int length; // variable to hold the length of each word. 
    
    length = strlen(word); //calcluates the length of the word passed to this function
        
    /* The following if statement states that if the word is one letter long (length = 1) then it is most likely to be A, the 
    first element (0) of the alphabet string passed to this function */
        if (length == 1) {
            unknownkey[0] = word[0]; // the place of A in the unknown key string is now the single letter read. 
            return *unknownkey; //the modified substitution key is passed back to the main.c to have the next word scanned and passed to this function. 
        } 
        
    /* The following if statement states that if the first letter of a word of length 3 is the same letter read previously to be A, then 
    the word is most likely 'AND' and the following letters in the word string will be N and D, and the values of these letters read from the word 
    are placed within their respective positions in the unknown key */
        if (length == 3 && word[0] == unknownkey[0]) {
            unknownkey[13] = word[1];  // the place of N in the alphabet substitution is now the second leter read following the determining A. 
            unknownkey[3] = word[2]; //the place of D in the alphabet substituton is now equal to the third letter read in the word. 
            return *unknownkey; //modfidied substitution key is passed back to main.c in order for the next word to be scanned and passed to the function. 
        }

    /* The following if statement states that if the word is three letters long, and the first letter is not that which is determined to be A, 
    then the word is most likely the word 'THE', and the respective letters read from the word string are passed to their respective places 
    within the unknown key string */        
        if (length == 3 && (word[0] != unknownkey[0])) {
            unknownkey[19] = word[0]; // The first letter of the word determined to be T is placed within the T position of the alphabetic unknown key. 
            unknownkey[7] = word[1]; // the second letter of the word determined to be H is placed within the H position of the alphabetic unknown key. 
            unknownkey[4] = word[2];  // the third letter of the word determiend to be E is placed within the E position of the alphabetic unknown key. 
            return *unknownkey; // the modified substitution key is passed back to main.c in order for the next word to be scanned and passed to this function for analysis. 
        }
      
    /* The following if statement defines that if the word is two letters long, and the first letter is the letter determined previously to most likely 
    be T, then this word is most likely 'TO', and the second letter read from the word, being O, is passed to the its respective position within
    the unkown key string. */
        if (length == 2 && (word[0] == unknownkey[19])) {
            unknownkey[14] = word [1]; // the second letter of the word determined to be O is placed within the O position of the alphabetic unknown key,
            return *unknownkey; // the modified substitution key is passed back to main.c in order for the next word to be scanned and passed to this function. 
        }
    
    /* The following if statement defines that if the word is two letters long, the the first letter is the letter previously determined to be O, then the word 
    is most likely to be 'OF', and the second letter read from the word is determined to be F and is placed within the F position of the alphabetic unknown key
    string . */
        if (length == 2 && (word[0] == unknownkey[14])) {
            unknownkey[5] = word[1]; // the second letter of the word determined to be F is placed within the F position of the alphabetic unknown key. 
            return *unknownkey; // the modified substitution key is passed back to main.c in order for the next word to be scanned and passed to this function for analysis. 
        }
        
    /* The following if statement states that if the word is two letters long and the second letter is determined to be that which corresponds with the previously determined letter 
    to be E, then the word is most likely BE and the first letter of the word is determined to be B, and placed within the B position of the alphabetic unkown key string.  */
        if (length == 2 && (word[1] == unknownkey[4])) {
            unknownkey[1] = word[0]; // the first letter of the word is determined to be B and is placed within the B position of the alphabetic unknown key. 
            return *unknownkey; // the modified substitution key is passed back to main.c in order for the next word to be scanned and passed to this function to be analysed
        }
        
    /* the following if statement states that if the word is one letter long, and the letter is not the letter previously determined to be A, then the letter is most likely I, and the 
    letter read from the word is assigned to the I position within the alphabetic unknown substitution key string. */
        if (length == 1 && (word[0] != unknownkey[0])) {
            unknownkey[8] = word[0]; // the first letter of the word is determined to be I and is placed within the I position of the alphabetic unkown key. 
            return *unknownkey; //the modified substitution key is passed back to main.c in order for the nect word to be scanned and passed to this funciton to be analysed. 
        }
        
    /* the following if statement states that if the word is two letters long and the second letter is that previously determined to be N, then the word is most likely 
    IN and the first letter in the word is determined to be I, and is assigned to the I position within the alphabetic unknown substitution key string. */
        if (length == 2 && (word[1] == unknownkey[13])) {
            unknownkey[8] = word[0]; // the first letter of the word is determined to be I and is placed within the I position of the alphabetic unknown key. 
            return *unknownkey; // the modified substitution key is passed back to the main.c in order for the nect word to be scanned and passed to this function to be analysed. 
        }
       
    /* The following if statement states that if the word is four letters long and the first and last letter are those previouslt determined to be T, and the second last letter is 
    that previously determined to be A, then the word is most likely THAT and the second letter within the word is likely to be H, and this is placed within the H position 
    of the alphabetic unknown key string */
        if (length == 4 && (word[0] == unknownkey[19]) && (word[3] == unknownkey[19]) && (word[2] == unknownkey[0])) {
            unknownkey[7] = word[1]; // the second letter of the word is determined to be H, and is placed within the H position of the alphabetic unknown key
            return *unknownkey; // the modified substitution key is passed back to the main.c in order for the nect word to be scanned and passed to this function for analysis. 
        }
        
    /* The following if statement states that if the word is four letters long and the first letter is that previously determined to be H, and the second letter is that previouslt 
    determined to be A, and the last letter is that previously determined to be E, then the word is most likely HAVE and the third letter is determined to be V, and is placed within the 
    V position of the alphabetic unknown key string. */
        if (length == 4 && (word[0] == unknownkey[7]) && (word[1] == unknownkey[0]) && (word[3] == unknownkey[4]) ) {
            unknownkey[21] == word[2]; // the 3rd letter of the word is determined to be V, and is placed within the V position of the alphabetical unknown key 
            return *unknownkey; // the modified substitution key is passed back to the main.c in order for the nect word to be scanned and passed to this function for analysis. 
        }
        
    /* The following if statement states that if the word is two letters long, and the first letter is that previously determined to be I, but the second letter is not that previouslt 
    determined to be N, then the word must be IT and the second letter is determined to be a T, and its value is passed to the T position of the alphabetic substitution cipher string. */
        if (length == 2 && (word[0] == unknownkey[8]) && (word[1] != unknownkey[13])) {
            unknownkey[19] = word[1]; //states that if the T letter of the alphabet has the letter found at word[1] assigned to it. 
            return *unknownkey; // returns the modified substitution key to the main.c function in order for the nect word to be read and analysed. 
        }
    
    /* This else statement states that if the word does not fit within any of the guidelines listed above, then it is most likely punctuation and will remain unchanged. */
        else {
            return *unknownkey; 
        }
        
        
  //  } //end of while loop
    
   return *unknownkey;  
} //end of function do not delete 