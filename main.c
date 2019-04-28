#include<stdio.h>
#include<string.h>

/* the following code has multiple functions. 
The first function reads words from the user, and then reads a key for the rotational cipher before 
encrypting the given words with the key and printing the result to the screen.
The second function decrypts inputted ciphertext in a similar way, with the encrypted text 
and the key (number of rotations) needing to be known in order to decrypt it. It also prints the original 
phrase to the screen. 
The third function defines how an rotational cipher encrypted ciphertext can be decrypted without the key (number of rotations) being 
known. It tests consecutive values of the key k until the user inputs to the program that the deciphered text is correct. 
The fourth and fifth functions work in the same way as the previous 3, however they read entire blocks of text that the user is 
prompted to input into the file 'input.txt' and the encrypted or decrypted text respectfully will be printed to the file 'output.txt'
However, to decrypt a block of text not knowing the key, it is recommended that the
user uses the 3rd function. 
The 6th function is the same as the first function, however rather than using a rotational cipher, it encrypts text using a substitution cipher, 
and the user is prompted to choose whether they wish to use the commonly used QWERTY substitution cipher or an input cipher. 
The 7th function is the same as the second function, however it decrypts ciphertext encrypted with either the common QWERTY substitution cipher or 
the users input ciphertext.  
The 8th and the 9th function within this program works the same as the 6th and 7th, however it reads text to encrypt from the file 'input.txt' and 
writes the encrypted or decrypted text respectfully to the file 'output.txt'.   
The user is prompted to input all information needeed for the program to work. In the cases of the program reading paragraphs from the 
'input.txt' file, the user is also prompted to make sure they have inputted what they wish to use in there before using the program, if not the 
program indicates the user should quit to do that before running the program again. This is to reduce complication when using these 
features in the program. 
The program can read paragraphs from both the user's input and the file 'input.txt', and therefore it is up to the user to decide which 
function they deem easier to use. 
The single file 'input.txt' should be used whenever the user wishes to input a passages into 4th, 5th, 8th and 9th functions in the program, and 
the encrypted or decrypted text for these functions should be read from the 'output.txt' file as is promted by the program. 
This code has been optimised in order to allow the input of capital and lower case letters, and allows the input of common
punctuation such as apostrophes and spaces, as well as numbers. If the program encounters these characters, they will be ignored 
and printed back the same as the original.  
Program must be run from the terminal section */

char Rencrypt(char *word); /* this is the prototype for the function that will handle encrypting the word using a rotational cipher*/ 
char Rkdecrypt(char *word); /* this is the prototype for the function that will handle decrypting a rotational cipher when given the rotation key*/
char Rdecrypt(char *word); /* this is the prototype for the fucntion that will handle decrypting a rotation cipher word without the rotation key*/
char Rtencrypt(char *word, int k); /* this is the protoype for the encyption of the file input.txt which must be used to encrypt passages rather than just words. it uses
                            rotation key*/
char Rtkdecrypt(char *word, int k); /* This is the prototype for the function that will decrypt whatever is input into 'input.ext' encrypted with a rotational cipher 
                            and given the key, and should be used if the user wishes to decrypt more than one word*/
char Sencrypt(char *word); /* this is the prototype for the function that will encrypt a user inputted word using a qwerty substitution cipher*/
char Sdecrypt(char *word); /* This is the prototype for the function that will take a single inputted cipherword from the user encrypted 
                            with a QWERTY substitution cipher and decrypt it to the original word. */
char Stencrypt(char *word, char *ciphertext);/* This is the prototype for the function that will read text from the file 'input.txt' and encrypt it with a substitution 
                                                cipher inputted by the user*/
char Stdecrypt(char *word, char *ciphertext); /* This is the prototype for the function that will read text from the file 'input.txt' and decrypt it using the substitution 
                                                cipher key inputted by the user. */
char Sunknownkey(char *word, char *alphabet, char *unknownkey); /* Function to determine the key of a substitution cipher after analysing the text */
char Sdecryptk(char *word, char *unknownkey); 

int main() 
{
    char word [10000]; /*initialises string with a number of letters most words won't exceed */  
    char ciphertext[10000]; //initialises the string to be used for ciphertext
    int function = 0; /* f will acts as the integer which chooses out of the multiple functions of this code -
    i.e., 1 will be rotational cipher encryption, 2 will be rotational cipher decryption, 
    3 will be sucstitution cipher encryption and 4 will be rotational cipher decryption*/
    unsigned char i = 0;
    int k = 0; /* this is the 'key', being the number of 'shifts' the letter will move - this will rotate k letters 
                used only for cases 4 and 5, as they require the key as an argument for their function*/
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; /* Alphabet string to determine key of substitution cipher*/
    char unknownkey[] = "abcdefghijklmnopqrstuvwxyz" ; /* String to hold the key that will be determined in the 'Sunknownkey function' to be used to 
                                decrypt ciphertext with unknown substitution key. */
    
    FILE *input; /* This is introducing the file which can be read from in the functions lower in the list. */
    FILE *output; /* this is introducing the file which will have encryptions/encryptions printed to it from functions called on 
                within main.c */
    
    /* the below 9 lines act as the 'user-friendly' manuel in which the user can insert a number
    from 1-9 to determine which function within the program they would like to use. The prompted input of the user 
    will determine the switch case in which the program is directed to, and therefore the corresponding function. For both 
    rotational and substitution cipher methods, the user is given the option to either encrypt/decrypt a single word inputted into 
    the program, or they can choose to encrypt/decrypt and entire passage which they are prompted to input into the 'input.txt' file. 
    Therefore the user can clearly choose whichever function which most accurately matches their need*/
 
        printf("Insert number of function you wish to use: \n");
        printf("(1) to encrypt using a rotational cipher \n");
        printf("(2) to decrypt ciphertext using a rotational cipher (given the key) \n");
        printf("(3) to decrypt ciphertext using a rotational cipher (not given the key() \n");
        printf("(4) to encrypt a phrase from the file 'input.txt' with a rotational cipher\n");
        printf("(5) to decrypt a phrase from the file 'input.txt' encrypted using a rotational cipher (given the key)\n");
        printf("(6) to encrypt using a substitution cipher \n");
        printf("(7) to decrypt ciphertext encrypted using a substitution cipher\n"); 
        printf("(8) to encrypt a phrase from the file 'input.txt' using a substitution cipher\n");
        printf("(9) to decrypt a phrase from the file 'input.txt' encrypted using a substitution cipher (given the key) \n");
        printf("(10) to decrypt a phrase from the file 'input.txt' encrypted with a substitution cipher (without the key)\n"); 
       
        scanf("%d", &function); //reads the input of a number from 1-9 from the user to initiate a particular switch statement designated to the desired function. 
        
    /* The following switch statement will take the users inputted value of 'function' in order to determine which 
    function the user wishes to use. Each inputted number relates to a different case statement corresponding to that 
    number which each call for the corresponding function definitions needed to complete the function the user chooses.*/
        switch (function) {
    /* Switch case 1, used when the user inputs 1 into 'function' indicates to the program that it must first recieve an input
    word from the user in which they wish to encrypt, convert any lower case letters within this input to capitals 
    and then input this all capital lettered word into the 'Rencrypt' function (definition found at bottom of code)
    which will define how this word will be encrypted */
            case 1:
                printf("You chose to encrypt using a rotational cipher! \n");
                printf("Insert words to be encrypted:"); // prompts the user to input text to encrypt
                scanf(" %[^\n]s", word); /*scans the text wished to be encrypted and puts it in the string 'word' */ 

    /* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
                while(word[i] != 0 ) {
                    if (word[i] > 96) { /* this line effectively says "If the ACSII code of the letter lies within the values
                                    of lower case letters (i.e. ACSII numbers above 96), then the difference between a capital 
                                    letter and its respective lower case letter (being 32) must be subtracted from the lower case 
                                    ACSII number in order to convert the lower case letter to its respective captial. This definiton 
                                    of this while loops applies to all while loops within this code commented to also be converting
                                    lower case letters to uppercase letters (as the loops are the same with the same outcome*/
                        word[i] = (word[i] - 32);
                        i++; //increments the value of i in order to check if the next consecutive letter is a capital or not
                    }
    /* This else statement states that if the letter stored in word[i] is not a lower case (so is either a capital, punctuation or number 
    etc) then it will remain the same and the program will move to test next consecutive letter in the string. */
                    else { 
                        word[i] = word[i];
                        i++; //increments the value of i to test the nect consecutive value. 
                    }
                }
               
               Rencrypt(word); /* the line of code indicating the string 'word' (which has now been converted to upper case 
                                letters, will be used in the rotational encrypt function. */
               
               printf("%s\n", word); /* Prints encrypted word returned from the Rencrypt function*/
               
            break; /* the breaks within this switch case are used so that only one
            function will be used before the program exits (without it, the program will 
            run through ALL cases. This applies to other breaks found within this switch*/
 
    /* The switch case 2 statement defines that if the user inputs the value 2 into 'function' that they which to decrypt
    an encrypted word and have been given the key to do so. It will them prompt the user to input the encrypted word to 
    be deciphered - which is then converted to all capital letters again - before putting this all capitals word into the 
    Rkdecrypt function which defines how this input word will be decrypted*/          
            case 2:
                printf("You chose to decrypt ciphertext encrypted using a rotational cipher (given the key)! \n");
                printf("Insert ciphertext to be decrypted: "); /*this line prompts the user to input the 
                encrypted text they wish to decrypt*/
                scanf(" %[^\n]s", word); /* this scanf places the input ciphertext within the string that is to be 
                used in the function, therefore meaning it is the text that will be decrypted*/
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function. For explanation
    on how this works, read the comments within case 1. */
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
                
                Rkdecrypt(word); /* this line of code indicates the string 'word' inputted by the user will be used in the 
                rotational decryption function, as per the users choice*/
               
               printf("%s\n", word); /* Prints the decrypted text returned from the rkdecrypt function*/ 
         
            break; 
            
    /* The switch case 3 statement defines that if the user inputs the value 3 into 'function' that they wish to
    decrypt a word encrypted using a rotational cipher, and that they have not been given the key. The program will 
    again prompt the user for the encrypted word to be input, will convert it to capitals and then will put this word 
    into the Rdecrypt function, which defines how it will be decrypted without the needed key*/
            case 3: 
                printf("You chose to decrypt cipertext using a rotational cipher (without the key)! \n");
                printf("Insert ciphertext to be decrypted: "); /*this line prompts the user to input the cipher word*/
                scanf(" %[^\n]s", word); /* this scanf puts the text inserted by the user into the string 'word' to be used 
                                            in the decryption function */ 
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function. See explanation 
    within case 1. */
                while(word[i] != 0 ) {
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        i++;
                    }
                    else {
                        word[i] = word[i];
                        i++;
                    }
                } 
                
                Rdecrypt(word); /* This line of code indicates the string 'word' inputted will be used in the decryption
                function for rotational encrypted ciphertext when not given the key*/ 
               
               
    /* As the Rdecrypt function needs to be repeated until the user tells the program that the correct word is found, 
    the print statements are found within the function, as well as the key and the other values needed for the function to work. 
    This allows the function to be repeated until the user tells it to stop, when the correct key is found. */
                
            break;
    
    /* The following switch case 4 statement defines that if a user inputs 4, the program will be prompted to read data letter 
    by letter from the file input.txt and encode it letter by letter and they must insert the phrase 
    into the file before running the program*/
   
            case 4:
                printf("You chose to encrypt a phrase from 'input.txt' with a rotational cipher! \n");  
                printf("\n!!Insert text you wish to encrypt into the fie 'input.txt' before continuing!! \n");/* this statement prompts the user
                                                                                                                to input their wanted phrases into the 
                                                                                                                file which will be read.*/
                
                input = fopen("input.txt", "r"); /* This opens the file that the program will read and then ecrypt*/
                output = fopen("output.txt", "w"); /* This opens the file that the program will write the encryption to*/
                
                printf("\nInsert key for rotation:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
                scanf("%d", &k); // scans the input key from the user and places it within 'k' to be later passed to the function. 
            
    /* The following while loop works to read every character within the file one-by-one, until it reaches the end of the characters within the file,
    which is indicated by feof in which the while loop will then stop*/
                while(!feof(input)) {
                    char c; /* This is a variable that will be used to store single characters read by the following fscanf before they are inserted 
                            into the string 'word' that will be used in the function to encrypt the phrase*/
                    fscanf(input, "%c", &c); /* This fscanf reads a single character from the file 'input.txt' and puts it in the variable 
                                                c*/
                    
                    word [i] = c; /* This assigns the single character from the file read by the program to the first memory storage place
                                    within the string 'word' so that it can be inputted later into the Rtencrypt function*/
                    
    /* this if statement works to convert any lower case letters input into capitals before the letter continues through the while loops and 
    enters the function which will ecnrypt it only as a capital letter */
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        } 
    /* This second if statement within the loop again tests if the scanned character of the file is the end (feof). If so, this if statement will 
    prompt the user to observe the finished encryption within the output file, close all the files which have been used and end the program. Without 
    this statement the program would print the last letter in 'input.txt' twice.*/
                    if (feof(input)) {
                        printf("\nAlso observe encryption within the file 'output.txt'\n"); //tells the user to see their encryption within the file 'ouput.txt'
                        fclose(input); //closes the input file 
                        fclose(output); //closes the output file
                        return 0; //ends the program, as the file has been read and encrypted to completion
                    }
                    
                    Rtencrypt(word, k); /* This line indicates that the single read character input into the string 'word', as well as they key inputted by the user 
                                            will be used in the Rtencrypt function*/
    
                    printf("%c", word[i]); //prints the encrypted letter to the screen 
    /* The following print statement prints the encrypted letter found within the function and returned to this
    while loop to the file 'output.txt'. */
                    fprintf(output, "%c", word[i]); 
                }

            break;
            
    /* The switch case 5 defines that if the user inputs 5, that single letters will be read from the file 'input.txt' and used in 
    the Rtdecrypt function to be decrypted. It will decrypt letter by letter and print each original letter to this screen 
    until it reaches the end of the file. */
   
            case 5:
                
                printf("You chose to decrypt a phrase read from 'input.txt' encrypted with a rotational cipher! \n");
                printf("\n!!Input ciphertext you wish to decrypt into the file 'input.txt' before continuing!! \n");
                input = fopen("input.txt", "r"); /* This opens the file that the program will read and then decrypt*/
                output = fopen("output.txt", "w"); /* This opens the file in which the function will print the decryption to*/
                
                printf("\nInsert key for decryption:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
                scanf("%d", &k);
            
    /* The following while loop works to read every character within the file one-by-one, until it reaches the end of the characters within the file,
    in which the while loop will then stop*/
                while(feof(input) != 1) {
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
                    
    /* This second if statement within the loop again tests if the scanned character of the file is the end (feof). If so, this if statement will 
    prompt the user to observe the finished decryption within the output file, close all the files which have been used and end the program. Without 
    this statement the program would print the last letter in 'input.txt' twice.*/
                    if (feof(input)) {
                        printf("\nAlso observe decryption within the file 'output.txt'\n"); //tells the user to see their encryption within the file 'ouput.txt'
                        fclose(input); //closes the input file 
                        fclose(output); //closes the output file
                        return 0; //ends the program, as the file has been read and decrypted to completion
                    }

                    Rtkdecrypt(word, k); /* This line indicates that the single read character input into the string 'word'
                                            will be used in the Rtdecrypt function*/
    
                    printf("%c", word[i]); // prints the decrypted letter to the screen
    /* The following print statement prints the decrypted letter found within the function and returned to this
    case to the file 'output.txt'*/
                    fprintf(output, "%c" , word[i]); 
                }
        
            break;
            
    /* The switch case 6 statement defines that if the user inputs 6, then the program will initiate this case statement which 
    will read inputted phrases from the user and enter them within the function that will encrypt them with a substitution cipher
    of the users choosing.*/
   
            case 6:
            
                printf("You chose to encrypt input text using a substitution cipher! \n");
                printf("Insert words to be encrypted:"); /* Prompts user to input text */
                scanf(" %[^\n]s", word); /* Puts the inputted text into the string 'word' to be encrypted*/
            
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function. see explanation 
    within case 1*/
                while(word[i] != 0) {
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        i++;
                    }
    /* This else statement states that if the word is a capital letter, then it will be left unchanged */
                    else {
                        word[i] = word[i];
                        i++;
                    }
                }

                Sencrypt(word); /* Puts the inputted text into the substitution encryption function*/
                
                printf("%s\n", word); /* Prints the encrypted ciphertext in which the substitution encryption function encrypts and returns*/
               
            
            break;
            
    /* The switch case 7 statement defines that if the user inputs 7 into the program, then it will initiate 
    this case 7 which will promt the program to take inputted words from the user and pass them to the function 
    responsible for decrypting phrases encrypted with a substitution cipher*/
            case 7:
            
                printf("You chose to decrypt ciphertext encrypted with a substitution cipher! \n");
                printf("Insert ciphertext to be decrypted: "); //promts user to insert cipherwords
                scanf(" %[^\n]s", word); //stores the ciphertext within the string 'word' to later be passed to a function
                i = 0; //sets counter for the string 'word' to 0
                
    /* this while loop works to convert any lower case letters input into capitals before the word enters the function (as explained in the first switch case statement)*/
                    while(word[i] != 0) {
                        if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                        i++;
                        }
                        
                        else { //letter remains unchanged if already upper case letter 
                        word[i] = word[i];
                        i++;
                        }
                    }
                
                Sdecrypt(word); // passes the inputted ciphertext into the sdecrypt function. 
                
                printf("%s\n", word); // prints the decrypted text to the screen. 
                
            break;
            
    /* The switch case 8 statement defines that if the user inputs 8 into the user-friendly manuel, then the program will initiate the 
    following steps in order to read inputted text from the file 'input.txt' and encrypt the contents using a substitional cipher when 
    the scanned text is passed to the stencrypt function. It will also print the output to the file 'output.txt'. */
            case 8:
            
                printf("You chose to encrypt a phrase from the file 'input.txt' using a substitution cipher!\n");
                printf("\n!!Insert phrase you wish to encrypt into the file 'input.txt'!!\n"); /* Prompts the user to input the 
                                                                                                text they wish to encrypt into the file 
                                                                                                'input.txt'*/
                printf("Insert substitution cipher key below their designated letters\n"); /* Prompts the user to input the key for the substitutional 
                                                                                            encryption key into the program */
                printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"); /* Gives the user a visual reference to see what each letter of the alphabet becomes once they 
                                                        have fully inserted the key. Also assists the user visually to ensure they insert all 26 letters of the 
                                                        new alphabet substitution*/
                scanf("%s", ciphertext); // scans the ciphertext inputted by the user and stores it within the string 'ciphertext'
                
                input = fopen("input.txt", "r"); /* This opens the file that the program will read and then ecrypt*/
                output = fopen("output.txt", "w"); /* This opens the file that the program will write the encryption to*/
                
                while(!feof(input)) {
                    char c; /* This is a variable that will be used to store single characters read by the following fscanf before they are inserted 
                            into the string that will be used in the function to encrypt the phrase*/
                    fscanf(input, "%c", &c); /* This fscanf reads a single character from the file 'input.txt' and puts it in the variable 
                                                c*/
            
                    word [i] = c; /* This assigns the first value of the string 'word' with the letter read from the file 'input.txt'. */
            
    /* this if statement works to convert any lower case letters input into capitals before the word enters the function*/
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                    } 

    /* This second if statement within the loop again tests if the scanned character of the file is the end (feof). If so, this if statement will 
    prompt the user to observe the finished encryption within the 'output.txt' file, close all the files which have been used and end the program. Without 
    this statement the program would print the last letter in 'input.txt' twice.*/        
                    if (feof(input)){
                        printf("\nAlso observe decrypted text within the file 'output.txt'\n"); //promts user to observe output from the file 'output.txt'
                        fclose(input); //closes the input file 
                        fclose(output); //closes the output file
                        return 0; //ends the program as the file has been read and encrypted to completion.  
                    }
                    
                    Stencrypt(word, ciphertext); //passes the single scanned letter to the function stencrypt 
                    
                    printf("%c", word[i]); // prints the encrypted letter to the screen
                    fprintf(output, "%c" , word[i]); // prints the encrypted letter to the file 'output.txt'
                }
                
            break; 
            
    /* The switch case 9 statement defines that if the user inputs 9 into the user-friendly manual, then the program 
    will initiate the following steps which will work to read text letter by letter from the file 'input.txt' and pass it to the function
    stdecrypt in order to decrypt its substitutional encryption. It will print the decrypted text to the file 'output.txt'. */
            case 9:
           
                printf("You chose to decrypt a phrase from the file 'input.txt' encrypted with a substitution cipher!\n");
                printf("\n!!Insert phrase you wish to decrypt into the file 'input.txt'!!\n"); /* Promts the user to insert the ciphertext to the 
                                                                                                file 'input.text'*/
                printf("Insert ciphertext used to encrypt below their designated letters\n"); /* Prompts the user to insert the substitutional alphabet
                                                                                                key used to encrypt the inserted ciphertext. */
                printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"); /* Gives visual aid to the user when inserting the key to see what letters of the alphabet become and 
                                                        ensure that all 26 letters are inputted. */
                scanf("%s", ciphertext); //stores the inputted ciphertext into the string 'ciphertext' to be passed to the stdecrypt function
            
                input = fopen("input.txt", "r"); /* This opens the file that the program will read and then ecrypt*/
                output = fopen("output.txt", "w"); /* This opens the file that the program will write the encryption to*/
                
                while(!feof(input)) {
                    char c; /* This is a variable that will be used to store single characters read by the following fscanf before they are inserted 
                            into the string that will be used in the function to encrypt the phrase*/
                    fscanf(input, "%c", &c); /* This fscanf reads a single character from the file 'input.txt' and puts it in the variable 
                                                c*/
            
                    word [i] = c; /* This assigns the first value of the string 'word' with the letter read from the file 'input.txt'. */
            
    /* this if statement works to convert any lower case letters input into capitals before the word enters the function*/
                    if (word[i] > 96) { 
                        word[i] = (word[i] - 32);
                    } 
    /* This second if statement within the loop again tests if the scanned character of the file is the end (feof). If so, this if statement will 
    prompt the user to observe the finished decryption within the 'output.txt' file, close all the files which have been used and end the program. Without 
    this statement the program would print the last letter in 'input.txt' twice.*/  
                    if (feof(input)){
                        printf("\nAlso observe decrypted text within the file 'output.txt'\n"); //promts user to observe output from the file 'output.txt'
                        fclose(input); //closes the input file 
                        fclose(output); //closes the output file
                        return 0; // ends the program as the file has been read and decrypted to completion. 

                    }
                    
                    Stdecrypt(word, ciphertext); //passes the character within 'word' and the inserted ciphertext key to the function stdecrypt. 
                    
                    printf("%c", word[i]); //prints the decrypted letter to the screen 
                    fprintf(output, "%c" , word[i]); //prints the decrypted letter found and returned from within the function stdecrypt. 
                }
            
            break;
            
            case 10:
                printf("You chose to decrypt a substitution cipher from the file 'input.txt' without a key!\n");
                printf("\n!!Insert phrase you wish to decrypt into the file 'input.txt'!!\n"); /* Promts the user to insert the ciphertext to the 
                                                                                                file 'input.text' */
                input = fopen("input.txt", "r"); /* This opens the file that the program will read and then ecrypt*/
                output = fopen("output.txt", "w"); /* This opens the file that the program will write the encryption to*/
            
                while (!feof(input)) {
                    
                fscanf(input, "%s", word); // reads a word from the file 
                 
                    
                    Sunknownkey(word, alphabet, unknownkey); // passes the word to the function to decrypt a key  
                }
                
                fclose(input); //closes the input file 
                fclose(output); //closes the output file
                
                input = fopen("input.txt", "r");  /*This opens the file that the program will read and then ecrypt*/
                output = fopen("output.txt", "w"); /* This opens the file that the program will write the encryption to*/
               
                while (!feof(input)){
                    fscanf(input, "%s", word); // reads a word from the file
                    Sdecryptk(word, unknownkey); 
                    printf("%s\n", word); 
                } 



                
    } // end of switch statement bracket so STOP DELETING IT

    return 0; 
}

