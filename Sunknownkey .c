#include <stdio.h>
#include <string.h>

char Sunknownkey(char *word, char *alphabet, char *unknownkey) {
    int length; // variable to hold the length of each word. 
    int i = 0; //counter for the location of the program within the string 'word'
    int k; // position marker of corresponding letter within string 'unknown key' when compared to the order of the common alphabet 
    printf("%s\n", word); 
    length = strlen(word); //calcluates the length of the word passed to this function.
    printf("%s\n", unknownkey); 
    printf("%d\n", length);
        
        if (length == 1) {
            unknownkey[0] = word[0]; // the place of A in the alphabet is now the single letter read. 
            printf("%s\n", unknownkey);
            return *unknownkey; 
        } 
        
        else if (length == 3 && word[0] == unknownkey[0]) {
            unknownkey[13] = word[1];  // the place of N in the alphabet substitution is now the second leter read following the determining A. 
            unknownkey[3] = word[2]; //the place of D in the alphabet substituton is now equal to the third letter read in the word. 
            printf("%s\n", unknownkey);
            return *unknownkey;
        }
        
        else if (length == 3 && (word[0] != unknownkey[0])) {
            unknownkey[19] = word[0];
            unknownkey[7] = word[1];
            unknownkey[4] = word[2]; 
            printf("%s\n", unknownkey); 
            return *unknownkey; 
        }
        
        //if (length == )
        
        
        
  //  } //end of while loop
    
   return *unknownkey;  
} //end of function do not delete 