#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char character, int key);

int main(int argc, string argv[])
{
    // if the program runs with a single command-line before add functionality
    if (argc != 2)
    {
        // exit
        printf("Usage: ./casear key\n");
        return 1;
    }

    // check if the key is digits only
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./casear key\n");
            return 1;
        }
    }

    // convert the argument from string to int
    int arg = atoi(argv[1]);

    // taking plaintext as input
    string plain_text = get_string("Plaintext:  ");
    char cipher_text = 0;

    // print output
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain_text); i++)
    {
        cipher_text = rotate(plain_text[i], arg);
        printf("%c", cipher_text);
    }
    // new line
    printf("\n");

    return 0;
}

bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]))
        {
            return true;
        }
    }
    return false;
}

// a function takes (character & key) and rotate that character by that key
char rotate(char character, int key)
{
    int cipher_char;
    // formula: ci = (pi + k) % 26
    if (isalpha(character))
    {
        if (isupper(character))
        {
            // ci = (pi + k) % 26
            cipher_char = ((character + key) - 'A') % 26 + 'A';
            return cipher_char;
        }
        else if (islower(character))
        {
            cipher_char = ((character + key) - 'a') % 26 + 'a';
            return cipher_char;
        }
        else
        {
            return character;
        }
    }
    return character;
}
