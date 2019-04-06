#include<stdio.h>
#include<string.h>

/* the following code has multiple functions. The first function reads a word from the user, and then reads a key for the rotational cipher before 
encrypting the given word with the key and printing the result to the screen.
The second function decrypts an encrypted word in a similar way, with the encrypted word 
and the key (number of rotations) needs to be known in order to decrypt it. It also prints the original 
word to the screen. 
The third function defines how an rotational cipher encrypted word can be decrypted without the key (number of rotations) being 
known. It tests consecutive values of the key k until the user inputs to the program that the deciphered word is correct. 
The fourth and third functions work the same way to encrypt and decrypt respectively, however uses 
the method of a substitution cipher rather than a rotational cipher. 
The use is prompted to input all information needeed for the program to work. 
Words can only be a single word or the program will exit, as when the string reads empty space (i.e. a space) it
recognises it as the end of the string and exits. Therefore, if a sentence is to be decrypted, each word must be input into the program
separately (one at a time).   
This code has been optimised in order to allow the input of capital and lower case letters, and allows the input of common
punctuation such as apostrophes, as well as numbers; however spaces still cause the program to 
quit and should be avoided.  
Program must be run from the terminal section */

char Rencrypt(char *word, int n); /* this is the prototype for the function that will handle encrypting the word using a rotational cipher*/ 
char Rkdecrypt(char *word, int n); /* this is the prototype for the function that will handle decrypting a rotational cipher when given the rotation key*/
char Rdecrypt(char *word, int n); /* this is the prototype for the fucntion that will handle decrypting a rotation cipher word without the rotation key*/

int main() 
{
    char word [100]; /*initialises string with a number of letters most words won't exceed */  
    int function = 0; /* f will acts as the integer which chooses out of the multiple functions of this code -
    i.e., 1 will be rotational cipher encryption, 2 will be rotational cipher decryption, 
    3 will be sucstitution cipher encryption and 4 will be rotational cipher decryption*/
    int i=0;
    int n=0; /* this is an integer for the number of letters in the word - 
                used to kill the loop when the word is done being encrypted */
    
    /* the below 5 lines act as the 'user-friendly' manuel in which the user can insert a number
    from 1-5 to determine which function within the program they would like to use*/
 
        printf("Choose function you wish to use: \n");
        printf("Insert 1 to encrypt using a rotational cipher \n");
        printf("Insert 2 to decrypt using a rotational cipher, given the key \n");
        printf("Insert 3 to decrypt using a rotational cipher, not given the key \n");
      /*  printf("Insert 3 to encrypt using a substitution cipher, \n");
        printf("Insert 4 to decrypt using a substitution cipher: "); */
        scanf("%d", &function);
        
    /* The following switch statement will take the users inputted value of 'function' in order to determine which 
    function the user wishes to use. Each inputted number relates to a different case statement corresponding to that 
    number which each call for the corresponding function definitions needed to complete the function the user chooses.*/
        switch (function) {
    /* Switch case 1, used when the user inputs 1 into 'function' indicates to the program that it must first recieve an input
    word from the user in which they wish to encrypt, convert any lower case letters within this input to capitals 
    and then input this all capital lettered word into the 'Rencrypt' function (definition found at bottom of code)
    which will define how this word will be encrypted */
            case 1:
                printf("You chose to encrypt a word using a rotational cipher! \n");
                printf("Insert word to be encrypted:"); // prompts the user to input word
                scanf("%s", word); /*scans the word wished to be encrypted and puts it in the string */ 
                printf("Insert number of characters (including punctuation) in word: "); /* this again allows the user to tell how many letters are to be 
                        encrypted before the function is to be killed, which stops the program from printing and encrypting the remaining irrelevant 
                        characters within the string*/
                scanf("%d", &n);
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                while(i<n) {
                    if (word[i] > 96) { /* this line effectively says "If the ACSII code of the letter lies within the values
                                    of lower case letters (i.e. ACSII numbers above 96), then the difference between a capital 
                                    letter and its respective lower case letter (being 32) must be subtracted from the lower case 
                                    ACSII number in order to convert the lower case letter to its respective captial. This definiton 
                                    of this while loops applies to all while loops within this code commented to also be converting
                                    lower case letters to uppercase letters (as the loops are the same with the same outcome*/
                        word[i] = (word[i] - 32);
                        i++;
                    }
                    else {
                        word[i] = word[i];
                        i++;
                    }
                }
               
               Rencrypt(word, n); /* the line of code indicating the string 'word' will be used 
                in the encrypt function. */
               
            break; /* the breaks within this switch case are used so that only one
            function will be used before the program exits (without it, the program will 
            run through ALL cases. This applies to other breaks found within this switch*/
 
    /* The switch case 2 statement defines that if the user inputs the value 2 into 'function' that they which to decrypt
    an encrypted word and have been given the key to do so. It will them prompt the user to input the encrypted word to 
    be deciphered - which is then converted to all capital letters again - before putting this all capitals word into the 
    Rkdecrypt function which defines how this input word will be decrypted*/          
            case 2:
                printf("You chose to decrypt a word using a rotational cipher (given the key)! \n");
                printf("Insert encrypted word to be decrypted: "); /*this line prompts the user to input the 
                encrypted word they wish to decrypt*/
                scanf("%s", word); /* this scanf places the input word within the string that is to be 
                used in the function, therefore meaning it is the word that will be decrypted*/
                printf("Insert number of characters (including punctuation) in encryption: "); /* this allows the user to tell how many letters are to be 
                            encrypted before the function is to be killed, which stops the program from printing and encrypting the remaining irrelevant 
                            characters within the string*/
                scanf("%d", &n);
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                while(i<n) {
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        printf("%c", word[i]);
                        i++;
                    }
                    else {
                        word[i] = word[i];
                        i++;
                    }
                }
                
                Rkdecrypt(word, n); /* this line of code indicates the string word inputted will be used in the 
                decryption function, as per the users choice*/
            break; 
            
    /* The switch case 3 statement defines that if the user inputs the value 3 into 'function' that they wish to
    decrypt a word encrypted using a rotational cipher, and that they have not been given the key. The program will 
    again prompt the user for the encrypted word to be input, will convert it to capitals and then will put this word 
    into the Rdecrypt function, which defines how it will be decrypted without the needed key*/
            case 3: 
                printf("You chose to decrypt a word using a rotational cipher (without the key)! \n");
                printf("Insert word to be decrypted: "); /*this line prompts the user to input the cipher word*/
                scanf("%s", word); /* this scanf puts the word inserted by the user into the string 'word' to be used 
                in the decryption function */
                printf("Insert number of characters (including punctuation) in encryption: ");/* this allows the user to tell how many letters are to be 
                        encrypted before the function is to be killed, which stops the program from printing and encrypting the remaining irrelevant 
                        characters within the string*/
                scanf("%d", &n);
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                while(i<n) {
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        printf("%c", word[i]);
                        i++;
                    }
                    else {
                        word[i] = word[i];
                        i++;
                    }
                } 
                
                Rdecrypt(word, n); /* This line of code indicates the string word inputted will be used in the decryption
                function*/
            break;
        }

    return 0; 
}

/* the following function will define how the word is encrypted using a rotation cipher*/
char Rencrypt(char *word, int n) {
    char i = 0; // a counter to consecutively encrypt the letters within the inserted word 
    int k = 0; // this is the 'key', being the number of 'shifts' the letter will move - this will rotate k letters 

        printf("Insert key for rotation:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
        scanf("%d", &k);
        
    /* the below code takes each character from the string and moves its value to an ACSII character k steps down in the alphabet
    and prints each value as it is determined before increasing the value of the i counter to determine the next character in the string (next letter)
    If the ACSII characters go beyond Z with this rotation, they are rotated back to A etc as per how rotation ciphers work*/
     
       while (i<n) {
        
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be printed unchanged*/
           if(word[i] < 64){
               printf("%c", word[i]);
               i++; 
           }
    /* This following else if defines how the letters are rotated by the key, being that the ACSII code 
    of each will have k added to it to make that letter the letter designated to the new ACSII code (going from A-Z)*/
           else if ((word[i] + k) < 91 && (word[i]) >64) {
                word[i] = (word[i] + k);  
                printf("%c", word[i]);
              i++;
            }
    /* This last else if within the loop defines that if a letter is to rotate past Z, that the ACSII code will loop
    back around to A rather than to the following symbols who's codes are consecutively after Z
    The minus 26 ensures the ACSII code stays within the bounds of the alphabet, while maintaining
    the correct ciphering method and key*/
            else if ((word[i] + k)>90) {
                word[i] = ((word[i] -26) + k);
                printf("%c", word[i]);
                i++;
            }
        }

         printf("\n");
     
    return 0;
}

/* The following function defines how a given cipher word encrypted via. rotational cipher can be 
decrypted if given the key */
char Rkdecrypt(char *word, int n){
    char i = 0; /*again, this is a counter in order to only decrypt each letter of the word once before moving on to the next consecutive letter */
    int k = 0;  /* this is again acting as the key given which will be used to decrypt the given encryption */
  
        printf("Insert given key for number of rotations: "); /*given the key for the number of rotations initially used to encrypt 
        the word allows the decrypt program to move the same key of rotations backwards to achieve the initial letters*/
        scanf("%d", &k); 

    /* The below code is very similar to the code used for encryption with a rotational cipher. 
    However, this time the key number will be removed from the current letters in order to see from 
    which position they were moved from, and therefore print the original word*/
       
       while (i<n) {
           
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be printed unchanged*/
           if(word[i] < 64){
               printf("%c", word[i]);
               i++; 
           }
    /* this else if statement defines that the ASCII code of each letter is taken and has the inputted
    key minused from it in order to achieve the initial ACSII code (before encryption) and 
    printing the corresponding initial letter to the screem*/
            else if ((word[i] - k )>= 65) {
                word[i] = (word[i] - k);  
                printf("%c", word[i]);
              i++;
            }
    /* this final else if statement defines that if the ACSII code goes below those associated to capital letters (being A), 
    it will rotate the ACSII code back to that associated with Z in order for the original letter to still be found. The plus 
    26 within thise statement accounts for this and keeps the ACSII code within the order and bounds of the alphabet*/
            else if ((word[i] - k)<66) {
                word[i] = ((word[i] - k) +26);
                printf("%c", word[i]);
                i++;
            }
        }
         printf("\n");
     
    return 0; 
}

/* The following function defines how the program will decrypt a given encrypted word when not given the key for the number of rotations. 
This is done by initialising the key value k to one, and increasing this at the end of every loops until the user indicates that the decryption 
is correct with a particular key value*/
char Rdecrypt(char *word, int n){
    char i = 0; /*again, this is a counter in order to only decrypt each letter of the word once before moving on to the next consecutive letter */
    int k = 1;  /* this is again acting as the key given which will be used to decrypt the given encryption, initialised to one so that each consecutive 
                key value in the decryption loop can be tested*/
    int r = 0; /* This variable will be used to determine whether the user wishes to decrypt again with the new key or to exit 
    the program if given the right word*/

    /* The below code is very similar to the code used for encryption with a rotational cipher. 
    However, this time the key number will be removed from the current letters in order to see from 
    which position they were moved from, and therefore print the original word*/
       
       while (i<=n) {
           
    /* the first if statement in this while loop defines that if a character
    of punctuation is entered, i.e. an apostrophe, than it will be printed unchanged*/
           if(i<n && word[i] < 64){
               printf("%c", word[i]);
               i++; 
           }
    /* this else if statement defines that the ASCII code of each letter is taken and has the inputted
    key minused from it in order to achieve the initial ACSII code (before encryption) and 
    printing the corresponding initial letter to the screen*/
            else if (i<n && (word[i] - k )>= 65) {
                word[i] = (word[i] - k);  
                printf("%c", word[i]);
              i++;
            }
    /* this final else if statement defines that if the ACSII code goes below those associated to capital letters (being A), 
    it will rotate the ACSII code back to that associated with Z in order for the original letter to still be found. The plus 
    26 within thise statement accounts for this and keeps the ACSII code within the order and bounds of the alphabet*/
            else if (i<n && (word[i] - k)<66) {
                word[i] = ((word[i] - k) +26);
                printf("%c", word[i]);
                i++;
            }
    /* This final else if statement states that if the deryption is complete, the user is printed a statement 
    to ask them whether the correct word has been deciphered. If it has not, the user inputs "1" to activate 
    the case 1 switch statement, which will reset the word and attempt to decipher with the next consecitive key 
    value. This can be repeated as many times as needed in order to find the correct key to decipher the correct word*/
            else if(i=n) {
                printf("\n");
                printf("Key = %d \n", k); /*This line prints the key used to decipher the text */
                printf("Insert 1 to decrypt again and 2 to exit: ");
                scanf("%d", &r);
                 
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
                                for the initial while loop for this decryption starting around line 212 to again be able to decrypt each letter of the 
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
