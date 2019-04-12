#include <stdio.h>
#include <string.h>

/* This function defines how a single inputted word from the user will be converted to its QWERTY substitutional cipher word. It's only 
argument is the word inputted by the user in the main.c case 6 function, and it only returns the new encrypted word to be 
printed in the main.c case 6 switch statement. */

char Sencrypt(char *word){
    
    unsigned char i = 0; /* Position counter for the word being encrypted, used to change each letter consecutively*/
    char ciphertext[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; //hardcoded QWERTY substitution ciphertext
    int k = 0; /* Position counter for the ciphertext used to determine which substitution letter the original letter will be replaced with*/
    int c = 0; /* integer to hold the value of 1 or 2 depending on which substituion ciper the user wishes to use in order to allow the use of a switch statement*/
    
    /* The following menu allows for the user to choose which substitution cipher text they wish to use. The inputted letter 
    will promt the program to go to the respective switch case function which corresponds to what the user wishes to do. */
    printf("Choose substitution cipher:\n");
    printf("Input (1) to use the QWERTY substitution cipher\n");
    printf("Input (2) to input alphabet substitution ciphertext\n");
    scanf("%d", &c);
    
    /* The following switch statement allows for the user to choose whether they would like to use the supplied QWERTY substitution
    ciphertext, or if they wish to use an inputted string of ciphertext. 
    Case 1: indicates to the program that the switch statement should break and the string 'ciphertext' will remain unchanged 
    and therefore the QWERTY substitution ciphertext will be used. 
    Case 2: indicates to the program the user wishes to input their own ciphertext, and will then prompt the user to do so 
    below the corresponding letters of the alphabet in which the ciphertext replaces. The inputted ciphertext 
    will then replace the hardcoded QWERTY ciphertext and the switch statement will break and the new ciphertext string will be used 
    in the following encryption. */
    switch(c) {
        
        case 1:
            break;
        
        case 2:
            printf("Insert substitutional alphabet below their designated letters in which they're replacing (do not input spaces)\n");
            printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
            scanf("%s", ciphertext); // reads the new ciphertext from the user. 
        break;
        
    } 
    
    /* This following while statement will work to encrypt the word passed from main.c with the substitution cipher 
    chosen (or inputted) in the above switch statement. This is done by minusing 65 from the ACSII code to determine what letter in the 
    alphabet the word is (with A starting and zero and Z (the last letter) being 25), and then this letter 
    is designated the corresponding letter associated with that location in the substitution cipher chosen. */
        while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; 
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
               i++;
           } 
        
    } 
    
    return *word; /* This returns the new cipherword to the original main.c case to be printed */
    
}