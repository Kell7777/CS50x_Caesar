#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // If argc doesn't have 2 arguments print error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; 
    }
    else
    {
        // If there are 2 arguments checks if all of the second argument contains digits
        string k = argv[1];
        for (int i = 0; i < strlen(k); i++)
        {
            if (isdigit(k[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // Converts second argument to int
        int myKey = atoi(k);
        
        // Asks users for plaintext to be ciphered
        string plaintext = get_string("Plaintext: "); 
        
        // For loop to convert ciphertext
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]))
            {
                // Change base so that A is 0
                // When you minus capital A ASCII value by 65 it becomes 0
                // Convert back to ASCII
                plaintext[i] = (plaintext[i] - 65);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 65); 
                //print f("%c",plaintext[i]);
            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] - 97);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 97);
                //print f("%c",plaintext[i]);
                
            }
            if (isalpha(plaintext[i]) == 0)
            {
                plaintext[i] = plaintext[i];
                //printf("%c",plaintext[i]);
            }
        }
        printf("Ciphertext: %s", plaintext);
        printf("\n");
        
    }
}
