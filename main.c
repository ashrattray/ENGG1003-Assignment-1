#include<stdio.h>
#include<string.h>

/* the following code has multiple functions. The first function reads a word from the user, and then reads a key for the rotational cipher before 
encrypting the given word with the key and printing the result to the screen.
The second function decrypts an encrypted word in a similar way, with the encrypted word 
and the key (number of rotations) needs to be known in order to decrypt it. It also prints the original 
word to the screen. The third and fourth functions work the same way respictevely, however uses 
the method of a substitution cipher rather than a rotational cipher. 
The use is prompted to input all information needeed for the program to work. 
Words can only be a single word or the program will exit, as when the string reads empty space (i.e. a space) it
recognises it as the end of the string and exits.  
This code has been optimised in order to allow the input of capital and lower case letters, and allows the input of common
punctuation such as apostrophes, as well as numbers; however spaces still cause the program to 
quit and should be avoided.  
Program must be run from the terminal section */

char Rencrypt(char *word); /* this is the prototype for the function that will handle encrypting the word using a rotational cipher*/ 
char Rdecrypt(char *word); /* this is the prototype for the function that will handle decrypting a rotational cipher*/
int main() 
{
    char word [100]; /*initialises string with a number of letters most words won't exceed */  
    int function = 0; /* f will acts as the integer which chooses out of the multiple functions of this code -
    i.e., 1 will be rotational cipher encryption, 2 will be rotational cipher decryption, 
    3 will be sucstitution cipher encryption and 4 will be rotational cipher decryption*/
    int i=0;
    
  /* the below 5 lines act as the 'user-friendly' manuel in which the user can insert a number
  from 1-4 to determine which function within the program they would like to use*/
 
        printf("Choose function you wish to use: \n");
        printf("Insert 1 to encrypt using a rotational cipher \n");
        printf("Insert 2 to decrypt using a rotational cipher \n");
      /*  printf("Insert 3 to encrypt using a substitution cipher, \n");
        printf("Insert 4 to decrypt using a substitution cipher: "); */
        scanf("%d", &function);
        
        switch (function) {
            case 1:
            printf("You chose to encrypt a word using a rotational cipher! \n");
            printf("Insert word to be encrypted:"); // prompts the user to input word
            scanf("%s", word); /*scans the word wished to be encrypted and puts it in the string */ 
          
/* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
           while(word[i] > 96) {
                word[i] = (word[i] - 32);
             i++;
           }
                Rencrypt(word); /* the line of code indicating the string 'word' will be used 
                in the encrypt function. */
               
            break; /* the breaks within this switch case are used so that only one
            function will be used before the program exits (without it, the program will 
            run through ALL cases. This applies to other breaks found within this switch*/
            
            case 2:
            printf("You chose to decrypt a word using a rotational cipher! \n");
            printf("Insert encrypted word to be decrypted: "); /*this line prompts the user to input the 
            encrypted word they wish to decrypt*/
            scanf("%s", word); /* this scanf places the input word within the string that is to be 
            used in the function, therefore meaning it is the word that will be decrypted*/
            
/* this while loop works to convert any lower case letters input into capitals before the word enters the function*/
           while(word[i] > 96) {
                word[i] = (word[i] - 32);
             i++;
           }
                Rdecrypt(word); /* this line of code indicates the string word inputted will be used in the 
                decryption function, as per the users choice*/
            break; 
         }   

            
    return 0; 
}

/* the following function will define how the word is encrypted using a rotation cipher*/

char Rencrypt(char *word) {
    char i = 0; // a counter to consecutively encrypt the letters within the inserted word 
    int k = 0; // this is the 'key', being the number of 'shifts' the letter will move - this will rotate k letters 
    int n = 0; // this is an integer for the number of letters in the word - used to kill the loop when the word is dont being encrypted
    
        printf("Insert number of characters (including punctuation)in word:"); /* this prompts the user to input the amount of loops needed in order 
        to kill the loop when the word is finished being encrypted*/
        scanf("%d", &n);
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
         printf("\n");
     
    return 0;
}

/* The following function defines how a given cipher word encrypted via. rotational cipher can be 
decrypted if given the key */

char Rdecrypt(char *word){
    char i = 0; /*again, this is a counter in order to only decrypt each letter of the word once before moving on to the next consecutive letter */
    int k = 0;  /* this is again acting as the key given which will be used to decrypt the given encryption */
    int n = 0;  /* this variable will again be used as the number of letters in the encryption
    and will be used as flow control to finish the function at the end of the word*/
   
        printf("Insert amount of characters in encryption: "); /* this again allows the user to tell how many letters are to be 
        encrypted before the function is to be killed, which stops the program from printing and encrypting the remaining irrelevant 
        characters within the string*/
        scanf("%d", &n);
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