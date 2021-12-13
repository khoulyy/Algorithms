#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h> // To use get_string() function
#include <math.h> // To use round() function

float count_l(string text);
float count_w(string text);
float count_s(string text);

// Global variable
string s;

int main()
{
    // Getting Text from the user
    s = get_string("Text: ");

    // Formulas
    float L = 0;
    L = count_l(s) / count_w(s);

    float S = 0;
    S = count_s(s) / count_w(s);

    float index = 0;
    index = round((0.0588 * L * 100) - (0.296 * S * 100) - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", index);
    }
}

// Function to count letters
float count_l(string text)
{
    float count_letters = 0;
    int str_length = strlen(s);

    for (int i = 0; i < str_length; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            count_letters += 1;
        }
    }
    return count_letters;
}

// Function to count words
float count_w(string text)
{
    float count_words = 0;
    int str_length = strlen(s);

    for (int j = 0; j < str_length; j++)
    {
        if (s[j] == ' ')
        {
            count_words++;
        }
    }
    count_words += 1;

    return count_words;
}

// Function to count sentences
float count_s(string text)
{
    float count_sentences = 0;
    int str_length = strlen(s);

    for (int k = 0; k < str_length; k++)
    {
        if (s[k] == '.' || s[k] == '!' || s[k] == '?')
        {
            count_sentences++;
        }
    }
    return count_sentences;
}
