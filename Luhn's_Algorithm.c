#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declaring variables
    long credit;
    int sum = 0;
    do
    {
        // Taking inputs from user
        credit = get_long("Credit: ");
    }
    while (credit < 1);
    // Here we make a copy of the credit number so we can use it in another operation
    long creditCopy = credit;

    // An example to test 4003600000000014
    while (credit != 0)
    {
        // Taking two digits and store them from the right
        int firstDigit = (credit % 10);
        int otherDigit = (credit % 100 / 10) * 2;

        /*
        If we mulitply the other digit and we got another two digit,
        then we sum the two digit
        Example: if the multiplication = 13, then we make it 1 + 3 = 4
        */
        if (otherDigit >= 10)
        {
            int temp = (otherDigit / 10) + (otherDigit % 10);
            sum += temp + firstDigit;
        }
        else
        {
            sum += otherDigit + firstDigit;
        }
        credit /= 100;
    }
    // If the right digit of the sum is 0, then the credit is valid
    if (sum % 10 == 0)
    {
        // Checking the type of credit (American Express, MasterCard, Visa)
        int countDigits = 2;    // counter to count digits, but i assigned it to 2 because there is two digit i will not divide
        while (creditCopy >= 100)
        {
            creditCopy /= 10;
            countDigits++;
        }
        if ((creditCopy == 34 || creditCopy == 37) && (countDigits == 15))
        {
            printf("AMEX\n");
        }
        else if ((creditCopy == 51 || creditCopy == 52 || creditCopy == 53 || creditCopy == 54 || creditCopy == 55) && (countDigits == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((creditCopy / 10) == 4 && (countDigits == 13 || countDigits == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // If not valid
    else
    {
        printf("INVALID\n");
    }
}
