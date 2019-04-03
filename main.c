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
Words must be in capital letters, as the program is designed to fit within the boundaries of the ACSII codes of capital letters. 
Program must be run from the terminal section */

char Rencrypt(char *word); /* this is the prototype for the function that will handle encrypting the word using a rotational cipher*/ 
char Rdecrypt(char *word); /* this is the prototype for the function that will handle decrypting a rotational cipher*/
int main() 
{
    char word [100]; /*initialises string with a number of letters most words won't exceed */  
    int function = 0; /* f will acts as the integer which chooses out of the multiple functions of this code -
    i.e., 1 will be rotational cipher encryption, 2 will be rotational cipher decryption, 
    3 will be sucstitution cipher encryption and 4 will be rotational cipher decryption*/
  
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
            printf("Insert word to be encrypted (use capital letters):"); // prompts the user to input word
            scanf("%s", word); /*scans the word wished to be encrypted and puts it in the string */ 
            
                Rencrypt(word); /* the line of code indicating the string 'word' will be used 
                in the encrypt function. */
            break;
            
            case 2:
            printf("You chose to decrypt a word using a rotational cipher! \n");
            printf("Insert encrypted word to be decrypted (use capital letters): ");
            scanf("%s", word);
            
                Rdecrypt(word); /* this line of code indicates the string word inputted will be used in the 
                decryption function, as per the users choice*/
            break; 
         }   

            
    return 0; 
}

// the following function will define how the word is encrypted using a rotation cipher

char Rencrypt(char *word) {
    char i = 0; // a counter to consecutively encrypt the letters within the inserted word 
    int k = 0; // this is the 'key', being the number of 'shifts' the letter will move - this will rotate k letters 
    int n = 0; // this is an integer for the number of letters in the word - used to kill the loop when the word is dont being encrypted
    
        printf("Insert amount of letters in word:");
        scanf("%d", &n);
        printf("Insert key for rotation:"); // this printf and scanf is used to read the key from the user for rotation encryption. 
        scanf("%d", &k);
        
     /* the below code takes each character from the string and moves its value to an ACSII character k steps down in the alphabet
     and prints each value as it is determined before increasing the value of the i counter to determine the next character in the string (next letter)
     If the ACSII characters go beyond Z with this rotation, they are rotated back to A etc as per how rotation ciphers work*/
     
       while (i<n) {
           /* if (word[i]==32) {
                printf("%c", 32);
                i++; 
            }*/

            if ((word[i] + k )<91 && word[i] >32) {
                word[i] = (word[i] + k);  
                printf("%c", word[i]);
              i++;
        }

            else if ((word[i] + k)>90) {
                word[i] = ((word[i] + k) -26);
                printf("%c", word[i]);
                i++;
            }
        }
         printf("\n");
     
    return 0;
}

char Rdecrypt(char *word){
    char i = 0; /*again, this is a counter in order to only decrypt each letter of the word once before moving on to the next consecutive letter */
    int k = 0;  /* this is again acting as the key given which will be used to decrypt the given encryption */
    int n = 0;  /* this variable will again be used as the number of letters in the encryption
    and will be used as flow control to finish the function at the end of the word*/
   
        printf("Insert amount of characters in encryption: ");
        scanf("%d", &n);
        printf("Insert given key for number of rotations: ");
        scanf("%d", &k); 

/* The below code is very similar to the code used for encryption with a rotational cipher. 
However, this time the key number will be removed from the current letters in order to see from 
which position they were moved from, and therefore print the original word*/
       
       while (i<n) {
           /* if (word[i]==32) {
                printf("%c", 32);
                i++; 
            }*/

            if ((word[i] - k )>= 65) {
                word[i] = (word[i] - k);  
                printf("%c", word[i]);
              i++;
            }

            else if ((word[i] - k)<66) {
                word[i] = ((word[i] - k) +26);
                printf("%c", word[i]);
                i++;
            }
        }
         printf("\n");
     
    return 0; 
}