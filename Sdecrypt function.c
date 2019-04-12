#include <stdio.h>
#include <string.h>

char Sdecrypt(char *word) {
    
    unsigned char i = 0; /*Counter used to keep track of which letter (position) of the string 'word'
                        in which the program is decrypting in order to not decrypt the same letter twice. */
    char ciphertext[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; /* Default cipher text for decrypting a qwerty substitution cipherword*/
    int k = 0; /*Counter for the ciphertext string used to rotate through each value until the program reaches 
                the one matching the 'word' i located letter, and the value of k can then be used to determine the original letter 
                of the alphabet. */
    int c = 0; /* Used to store the users decision for the substitution ciphertext to be used for the switch statement to analyse. */

    /* The following prompt allows the user to choose whether they would like to use the already supplied QWERTY substitution text, 
    or if they wish to input their own ciphertext to be used for decryption*/
    printf("Choose substitution cipher used for encryption:\n");
    printf("Insert (1) if the QWERTY substitution cipher was used for encryption\n");
    printf("Insert (2) to input the substitution cipher used for encryption\n");
    scanf("%d", &c);
    
    /* The following switch statement determines which ciphertext will be used for the decryption of the inputted cipherword. 
    Case 1: will break the switch statament and use the QWERTY substitution cipher hardcoded at the beginning of the function. 
    Case 2: will prompt the user to input their own substitution ciphertext to decrypt the inputted cipherword, and their 
    inputted ciphertext will replace the hardcoded QWERTY substitution in the 'ciphertext' string. */
    switch(c){
        
        case 1:
            break; // indicates to the program to continue to the following while statement and use the supplied QWERTY ciphertext for decryption. 
        
        case 2:
            printf("Insert substitution cipher used in encryption below their designated letters (do not input spaces)\n");
            printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
            scanf("%s", ciphertext); /* Whatever cipher text is inputted by the user here beneath their corresponding letters 
                                        will replace the current QWERTY substitution within the ciphertext string, and the program 
                                        will then break and use this new substitution ciphertext to decrypt the inputted word. */
            
            break; 
            
    }
    
        while (word[i] != 0) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be left unchanged within this function*/
           if(word[i] < 64){
               word[i] = word[i]; 
               i++; 
           }
    /* This else if statement states that if the ACSII code of the letter located at i in the string 'word' matches 
    that of the ACSII code located at k in the string 'ciphertext', that it must be changed to the corresponding 
    initial letter of the alphabet by taking the location of k ( which corresponds to location of the original letter 
    - the k location of the original alphabet - and add 65 to it to determine the original letter. 65 is the distance between the 
    ACSII numbers 0-25 and the corresponding letters of the alphabet. i.e. if location k = 0, the location of A is also zero and therefore
    the k located letter is A, and the ACSII code of A is 65, then the addition of 65 will print this. This is true for all 
    letters and locations in this program. */
           else if (word[i] == ciphertext[k]) {
               word[i] = (k + 65);
               i++; /* this increases the counter, and therefore location, of the string 'word' when the correct corresponding 
                        letter in the string 'countertext' is found as the while statement can then move forward to 
                        decrypting the next letter in the string 'word'. */
               k=0; /* This sets the counter k back to zero so that each consecutive letter in the string 'ciphertext' can be tested against 
                    the next letter in the string 'word'. */
           }
    /* This else if statement states that if the ACSII code of the letter located at i in the string
    'word' does not match the ACSII code at k location of the string 'ciphertext', then the location counter 
    k will increase by 1 until the matching code (and therefore letter) is found. */
           
           else if (word[i] != ciphertext[k]) {
               k++; // this increases the value of the counter k to move to the next consecutive location and letter of the string 'ciphertext'. 
           }
        }
    return *word; 
} 