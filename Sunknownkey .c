#include <stdio.h>
#include <string.h>

char Sunknownkey(char *word, char *alphabet, char *unknownkey) {
    int length; // variable to hold the length of each word. 
    int i = 0; //counter for the location of the program within the string 'word'
    int k; // position marker of corresponding letter within string 'unknown key' when compared to the order of the common alphabet 
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
        
        
        
  //  } //end of while loop
    
   return *unknownkey;  
} //end of function do not delete 