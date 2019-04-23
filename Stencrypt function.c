#include <stdio.h>
#include <string.h>

/* The following function has the same process as the sencrypt function, however it reads the inputted text to be 
encrypted from the input.txt file as is defined within the main.c. This function takes the string 'word' passed from main.c 
containing only a single character from the file and the string 'ciphertext' inserted within the main.c to be used, and uses 
the int counters of k and i in order to indicate the correct positions of i and k within the strings 'word' and *ciphertext' respectively in order 
to encrypt the letter with the correct ciphertext. Each if statement found below has a line responsible for returning the string  'word'
at the end after the correct if statement as been applied. Data restrictions are that both the strings must have chars (letters) inputted into them*/

char Stencrypt(char *word, char *ciphertext) {
    
    int k = 0; /* Position counter for the ciphertext used to determine which substitution letter the original letter will be replaced with*/
    int i = 0; // sets the function to read only the first value within the string 'word'
    
    /* This following while statement will work to encrypt the word passed from main.c with the substitution cipher 
    chosen (or inputted) in the above switch statement. This is done by minusing 65 from the ACSII code to determine what letter in the 
    alphabet the word is (with A starting and zero and Z (the last letter) being 25), and then this letter 
    is designated the corresponding letter associated with that location in the substitution cipher chosen. */
        while (i <26) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               return *word;  //returns the encryped letter back to main.c to be printed. 
           }
    /* This else if statement states that if the letter is a captital letter (as all letetrs are converted to)
    that its ACSII code will be taken and have 65 removed from it in order to make the letter its related number in the 
    ordered alphabet (i.e. A = 1, B = 2) however as strings start at 0, A becomes 0 and B becomes 1 etc. This number is then 
    assignment to the char, k, and the k numbered letter of the string 'ciphertext' is then assigned to the letter in 
    the word string. this replaces the letter with its corresponding QWERTY substitution, and the function then moves on to 
    the next letter to do the same until the word is finished. */
           else if(word[i] > 64 ) { 
               k = (word[i] - 65); 
               word[i] = ciphertext[k]; // letter number 'i' in string 'word' becomes letter number 'k' from string 'ciphertext'
               return *word; //returns encrypted letter 
           } 
        
    } 
    
    return 0;
    
} // end of function DO NOT DELETE 