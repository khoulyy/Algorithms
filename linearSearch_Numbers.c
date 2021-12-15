#include <stdio.h>
#include <cs50.h>

int main()
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    for (int i = 0; i < 7; i++)
    {
        // Search
        if (numbers[i] == 0)
        {
            printf("Found\n");
            // return 0 to quit the program if it founds the number
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}