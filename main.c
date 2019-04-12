#include<stdio.h>
#include<string.h>

/* the following code has multiple functions. 
The first function reads a single word from the user, and then reads a key for the rotational cipher before 
encrypting the given word with the key and printing the result to the screen.
The second function decrypts a single encrypted word in a similar way, with the encrypted word 
and the key (number of rotations) needs to be known in order to decrypt it. It also prints the original 
word to the screen. 
The third function defines how an rotational cipher encrypted word can be decrypted without the key (number of rotations) being 
known. It tests consecutive values of the key k until the user inputs to the program that the deciphered word is correct. 
The fourth and fifth functions work in the same way as the previous 3, however they read entire blocks of text that the user is 
prompted to input into the file 'input.txt' and therefore they can encrypt and decrypt entire blocks of words when given the key,
rather than a single word as is allowed in the first 3 functions. However, to decrypt a block of text not knowing the key, the 
function 5 must be chosen and tested with consecutive values for k, as there is no non-complicated system in place to test consecutive
keys for you. 
The 6th function is the same as the first function, however rather than using a rotational cipher, it encrypts a word using the 
commonly used QWERTY substitution cipher. It also encrypts only a single word that is inputted by the user. 
The 7th function is the same as the second function, however it decrypts words encrypted with the common QWERTY substitution cipher. It 
also only decrypts a single word inputted by the user.    
The user is prompted to input all information needeed for the program to work. In the cases of the program reading paragraphs from the 
'input.txt' file, the user is also prompted to make sure they have inputted what they wish to use in there before using the program, if not the 
program indicates the user should quit to do that before running the program again. This is to reduce complication when using these 
features in the program. 
For the 1st, 2nd, 3rd, 6th and 7th function, words inputted can only be a single word or the program will exit, as when the string reads empty space (i.e. a space) it
recognises it as the end of the string and exits. Therefore, if a sentence is wished to be encrypted, the 5th or 6th function must be used for 
a rotational cipher, and the 8th and 9th function must be used for a substitution cipher. 
The single file 'input.txt' should be used whenever the user wishes to input a passage into the program. 
This code has been optimised in order to allow the input of capital and lower case letters, and allows the input of common
punctuation such as apostrophes, as well as numbers. If the program encounters these characters, they will be ignored 
and printed back the same as the original.  
Program must be run from the terminal section */

char Rencrypt(char *word); /* this is the prototype for the function that will handle encrypting the word using a rotational cipher*/ 
char Rkdecrypt(char *word); /* this is the prototype for the function that will handle decrypting a rotational cipher when given the rotation key*/
char Rdecrypt(char *word, int n); /* this is the prototype for the fucntion that will handle decrypting a rotation cipher word without the rotation key*/
char Rtencrypt(char *word, int k); /* this is the protoype for the encyption of the file input.txt which must be used to encrypt passages rather than just words. it uses
                            rotation key*/
char Rtkdecrypt(char *word, int k); /* This is the prototype for the function that will decrypt whatever is input into 'input.ext' encrypted with a rotational cipher 
                            and given the key, and should be used if the user wishes to decrypt more than one word*/
char Sencrypt(char *word); /* this is the prototype for the function that will encrypt a user inputted word using a qwerty substitution cipher*/
char Sdecrypt(char *word); /* This is the prototype for the function that will take a single inputted cipherword from the user encrypted 
                            with a QWERTY substitution cipher and decrypt it to the original word. */

int main() 
{
    char word [1000]; /*initialises string with a number of letters most words won't exceed */  
    int function = 0; /* f will acts as the integer which chooses out of the multiple functions of this code -
    i.e., 1 will be rotational cipher encryption, 2 will be rotational cipher decryption, 
    3 will be sucstitution cipher encryption and 4 will be rotational cipher decryption*/
    unsigned char i = 0;
    int n=0; /* this is an integer for the number of letters in the word - 
                used to kill the loop when the word is done being encrypted - used only for case 3 */
    int k = 0; /* this is the 'key', being the number of 'shifts' the letter will move - this will rotate k letters 
                used only for cases 4 and 5, as they require the key as an argument for their function*/
    
    FILE *input; /* This is introducing the file which can be read from in the functions lower in the list. */
    
    
    /* the below 9 lines act as the 'user-friendly' manuel in which the user can insert a number
    from 1-9 to determine which function within the program they would like to use. The prompted input of the user 
    will determine the switch case in which the program is directed to, and therefore the corresponding function. For both 
    rotational and substitution cipher methods, the user is given the option to either encrypt/decrypt a single word inputted into 
    the program, or they can choose to encrypt/decrypt and entire passage which they are prompted to input into the 'input.txt' file. 
    Therefore the user can clearly choose whichever function which most accurately matches their need*/
 
        printf("Insert number of function you wish to use: \n");
        printf("(1) to encrypt a single input word using a rotational cipher \n");
        printf("(2) to decrypt a single input cipherword using a rotational cipher, given the key \n");
        printf("(3) to decrypt a single input cipherword using a rotational cipher, not given the key \n");
        printf("(4) to encrypt a phrase from the file 'input.txt' to encrypt with a rotational cipher\n   (note: \n   1.Phrase must be input into this file before the program is run.\n     If this has not been done, exit the program to do so before running the program again.)\n");
        printf("(5) to decrypt a phrase from the file 'input.txt' to decrypt a rotational cipher (given the key)\n   (note: \n   1.Phrase must be input into this file before the program is run.\n     If this has not been done, exit the program to do so before running the program again.\n   2.If the key is not known, use function (3) and input a single cipherword from the passage in 'input.txt'\n     to determine the key, then use this function with the determined key to determine the entire message.)\n");
        printf("(6) to encrypt a single input word a substitution cipher \n");
        printf("(7) to decrypt a single input cipherword encrypted using a substitution cipher\n"); 
       
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
                printf("You chose to encrypt an input word using a rotational cipher! \n");
                printf("Insert word to be encrypted:"); // prompts the user to input word
                scanf("%s", word); /*scans the word wished to be encrypted and puts it in the string */ 
            
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
               
               printf("%s\n", word); /* Prints encrypted word returned from the Rencrypt function*/
               
            break; /* the breaks within this switch case are used so that only one
            function will be used before the program exits (without it, the program will 
            run through ALL cases. This applies to other breaks found within this switch*/
 
    /* The switch case 2 statement defines that if the user inputs the value 2 into 'function' that they which to decrypt
    an encrypted word and have been given the key to do so. It will them prompt the user to input the encrypted word to 
    be deciphered - which is then converted to all capital letters again - before putting this all capitals word into the 
    Rkdecrypt function which defines how this input word will be decrypted*/          
            case 2:
                printf("You chose to decrypt an input word encrypted using a rotational cipher (given the key)! \n");
                printf("Insert cipherword to be decrypted: "); /*this line prompts the user to input the 
                encrypted word they wish to decrypt*/
                scanf("%s", word); /* this scanf places the input word within the string that is to be 
                used in the function, therefore meaning it is the word that will be decrypted*/
            
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
               
               printf("%s\n", word); /* Prints the decrypted word returned from the rkdecrypt function*/ 
         
            break; 
            
    /* The switch case 3 statement defines that if the user inputs the value 3 into 'function' that they wish to
    decrypt a word encrypted using a rotational cipher, and that they have not been given the key. The program will 
    again prompt the user for the encrypted word to be input, will convert it to capitals and then will put this word 
    into the Rdecrypt function, which defines how it will be decrypted without the needed key*/
            case 3: 
                printf("You chose to decrypt a word using a rotational cipher (without the key)! \n");
                printf("Insert cipherword to be decrypted: "); /*this line prompts the user to input the cipher word*/
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
    
    /* The following switch case 4 statement defines that if a user inputs 4, the program will be prompted to read data letter 
    by letter from the file input.txt and encode it letter by letter (rather than reading a single word inputted by the user). This 
    function is to be used if the user wishes to encode more than a word (i.e. a paragraph) and they must insert the phrase 
    into the file before running the program*/
   
            case 4:
                printf("You chose to encrypt a phrase from 'input.txt' with a rotational cipher! \n"); 
                
                input = fopen("input.txt", "r"); /* This opens the file that the program will read and then ecrypt*/
                
                printf("Insert key for rotation:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
                scanf("%d", &k);
            
    /* The following while loop works to read every character within the file one-by-one, until it reaches the end of the characters within the file,
    in which the while loop will then stop*/
                while(feof(input) == 0) {
                    char c; /* This is a variable that will be used to store single characters read by the following fscanf before they are inserted 
                            into the string that will be used in the function to encrypt the phrase*/
                    fscanf(input, "%c", &c); /* This fscanf reads a single character from the file 'input.txt' and puts it in the variable 
                                                c*/
                    
                    
                    word [i] = c; /* This assigns the single character from the file read by the program to the first place
                                    within the string 'word' so that it can be inputted later into the Rtencrypt function*/
                    
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        } 
                    
                    Rtencrypt(word, k); /* This line indicates that the single read character input into the string 'word'
                                            will be used in the Rtencrypt function*/
    
    /* The following print statement prints the encrypted letter found within the function and returned to this
    case to the screen*/
                    printf("%c", word[i]); 
                }
                
                printf("\n");
                
            break;
            
    /* The switch case 5 defines that if the user inputs 5, that single letters will be read from the file 'input.txt' and used in 
    the Rtdecrypt function to be decrypted. It will decrypt letter by letter and print each original letter to this screen 
    until it reaches the end of the file. */
   
            case 5:
                
                printf("You chose to decrypt a phrase read from 'input.txt' encrypted with a rotational cipher! \n");
                
                input = fopen("input.txt", "r"); /* This opens the file that the program will read and then decrypt*/
                
                printf("Insert key for decryption:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
                scanf("%d", &k);
            
    /* The following while loop works to read every character within the file one-by-one, until it reaches the end of the characters within the file,
    in which the while loop will then stop*/
                while(feof(input) == 0) {
                    char c; /* This is a variable that will be used to store single characters read by the following fscanf before they are inserted 
                            into the string that will be used in the function to decrypt the phrase*/
                    fscanf(input, "%c", &c); /* This fscanf reads a single character from the file 'input.txt' and puts it in the variable 
                                                c*/
                    
                    
                    word [i] = c; /* This assigns the single character from the file read by the program to the first place
                                    within the string 'word' so that it can be inputted later into the Rtdecrypt function*/
                    
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        } 
                    
                    Rtkdecrypt(word, k); /* This line indicates that the single read character input into the string 'word'
                                            will be used in the Rtdecrypt function*/
    
    /* The following print statement prints the decrypted letter found within the function and returned to this
    case to the screen*/
                    printf("%c", word[i]); 
                }

                    printf("\n");
            break;
            
            case 6:
            
                printf("You chose to encrypt an input word using a substitution cipher! \n");
                printf("Insert word to be encrypted:"); /* Prompts user to input word */
                scanf("%s", word); /* Puts the inputted word into the string 'word' to be encrypted*/
            
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

                Sencrypt(word); /* Puts the inputted word into the substitution encryption function*/
                
                printf("%s\n", word); /* Prints the word in which the substitution encryption function encrypts and returns*/
               
            
            break;
            
            case 7:
            
                printf("You chose to decrypt a single cipherword encrypted with a substitution cipher! \n");
                printf("Insert cipherword to be decrypted: ");
                scanf("%s", word); 
                i = 0; //sets counter for the string 'word' to 0
                
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function (as explained in the first switch case statement)*/
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
                
                Sdecrypt(word); // passes the inputted word into the sdecrypt function. 
                
                printf("%s\n", word); // prints the decrypted word to the screen. 
                
            break;
            
                
            
            
            
    } // end of switch statement bracket so STOP DELETING IT

    return 0; 
}

