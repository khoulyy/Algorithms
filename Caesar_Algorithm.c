#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h> // To use islower() and isupper() functions
#include <string.h> // To use Get_string() function
#include <stdlib.h> // To use atoi() function for converting string to integer

int main(int argc, string argv[])
{
    // Handles if arguments more than 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int argv1_length = strlen(argv[1]);

    // Handles if arguments not numeric
    for (int i = 0; i < argv1_length; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int arg = atoi(argv[1]);

    string plaintext = get_string("Plaintext: ");

    printf("Ciphertext: ");

    // Cipher the plaintext
    int n = strlen(plaintext);
    for (int j = 0; j < n; j++)
    {
        char ciphertext = 0;
        if (isalpha(plaintext[j]))
        {
            if (isupper(plaintext[j]))
            {
                // Formula c = (p + k) % 26
                ciphertext = (((plaintext[j] - 'A') + arg) % 26) + 'A';
                // Print with upper case
                printf("%c", ciphertext);
            }
            else if (islower(plaintext[j]))
            {
                // Formula c = (p + k) % 26
                ciphertext = (((plaintext[j] - 'a') + arg) % 26) + 'a';
                // Print with lower case
                printf("%c", ciphertext);
            }
            else
            {
                // Do nothing (nothing to change)
                printf("%c", plaintext[j]);
            }
        }
        else
        {
            // Do nothing (nothing to change)
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}