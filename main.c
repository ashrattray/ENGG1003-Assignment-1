#include<stdio.h>
#include<string.h>

/* the following code reads a word from the user, and then reads a key for the rotational cipher before 
encrypting the given word with the key and printing the result to the screen.
Words can only be a single word or the program will exit. 
Words must be in capital letters
Program must be run from the terminal section */

char encrypt(char *word); // this is the prototype for the function that will handle encrypting the word

int main() 
{
    char word [100]; //initialises string with a number of letters most words won't exceed.  
    
        printf("Insert word to be encrypted (use capital letters):"); // prompts the user to input word
        scanf("%s", word); //scans the word wished to be encrypted and puts it in the string. 

        encrypt(word); // the line of code indicating the string 'word' will be used in the encrypt function. 
    
    return 0; 
}

// the following function will define how the word is encrypted using a rotation cipher

char encrypt(char *word) {
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
         /*   if (word[i]==32) {
                printf("%c", word[i]);
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

