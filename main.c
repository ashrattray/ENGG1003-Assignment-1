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
The user is prompted to input all information needeed for the program to work. 
Words can only be a single word or the program will exit, as when the string reads empty space (i.e. a space) it
recognises it as the end of the string and exits. Therefore, if a sentence is to be decrypted, each word must be input into the program
separately (one at a time).   
This code has been optimised in order to allow the input of capital and lower case letters, and allows the input of common
punctuation such as apostrophes, as well as numbers; however spaces still cause the program to 
quit and should be avoided.  
Program must be run from the terminal section */

char Rencrypt(char *word); /* this is the prototype for the function that will handle encrypting the word using a rotational cipher*/ 
char Rkdecrypt(char *word); /* this is the prototype for the function that will handle decrypting a rotational cipher when given the rotation key*/
char Rdecrypt(char *word, int n); /* this is the prototype for the fucntion that will handle decrypting a rotation cipher word without the rotation key*/

int main() 
{
    char word [1000]; /*initialises string with a number of letters most words won't exceed */  
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
                scanf("%s[^\n]s", word); /*scans the word wished to be encrypted and puts it in the string */ 
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                while(word[i] != 0 ) {
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
               
               Rencrypt(word); /* the line of code indicating the string 'word' will be used 
                in the encrypt function. */
               
               i = 0; /* This statement returns the value of the couunter i to 0 in order to print 
               only the values of the string associated with the encrypted word in the following while 
               loop */
                
    /* This following while statement prints the new encrypted word returned from the function to the screen*/ 
               while (word[i] != 0) {
                   printf("%c", word[i]);
                   i++; 
               }
               
                printf("\n"); 
               
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
           /*     printf("Insert number of characters (including punctuation) in encryption: "); /* this allows the user to tell how many letters are to be 
                            encrypted before the function is to be killed, which stops the program from printing and encrypting the remaining irrelevant 
                            characters within the string*/
           /*     scanf("%d", &n); */
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                while(word[i] != 0) {
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        i++;
                    }
                    else {
                        word[i] = word[i];
                        i++;
                    }
                }
                
                Rkdecrypt(word); /* this line of code indicates the string word inputted will be used in the 
                decryption function, as per the users choice*/
               
               i = 0; /* This statement returns the value of the couunter i to 0 in order to print 
               only the values of the string associated with the decrypted word in the following while 
               loop */
               
    /* The following while function prints the decrypted word found within the function and returned to this
    case to the screen*/
                while (word[i] !=0) {
                    printf("%c", word[i]);
                    i++; 
                }
                
                printf("\n"); 
         
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
                while(i < n ) {
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        i++;
                    }
                    else {
                        word[i] = word[i];
                        i++;
                    }
                } 
                
                Rdecrypt(word, n); /* This line of code indicates the string word inputted will be used in the decryption
                function*/ 
               
               
    /* As the Rdecrypt function needs to be repeated until the user tells the program that the correct word is found, 
    the print statements are found within the function, as well as the key and the other values needed for the function to work. 
    This allows the function to be repeated until the user tells it to stop*/
                
            break;
        }

    return 0; 
}

