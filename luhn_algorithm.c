#include <cs50.h>
#include <stdio.h>

// Functions Prototypes
long get_credit_card(void);
int sum_of_multiplied_digits(long credit_card);
int sum_of_other_digits(long credit_card);
bool validate_card(int total_sum);
void type_of_credit_card(long credit_card, bool validation);

int main(void)
{
    // Get credit card number from the user
    long credit_card = get_credit_card();
    int total_sum = sum_of_multiplied_digits(credit_card) + sum_of_other_digits(credit_card);
    bool validation = validate_card(total_sum);
    type_of_credit_card(credit_card, validation);
}

// Function to get input from the user
long get_credit_card(void)
{
    // Getting input
    long card_number = 0;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 1);
    return card_number;
}

// Function to get the sum of the digits that multiplied
int sum_of_multiplied_digits(long credit_card)
{
    int pair_of_digits = 0;
    int left_digit = 0;
    int sum = 0;
    int multiplied_digit = 0;

    while (credit_card != 0)
    {
        // Get pairs of digits
        pair_of_digits = credit_card % 100;
        // Get the left digit of the pair
        left_digit = pair_of_digits / 10;
        // Multiply the left digit
        multiplied_digit = left_digit * 2;

        // If the multiplied digit has two digit after multiplication
        if (multiplied_digit / 10 != 0)
        {
            // Separate them
            int inner_right_digit = 0;
            int inner_left_digit = 0;
            // Get the right digit
            inner_right_digit = multiplied_digit % 10;
            // Get the left digit
            inner_left_digit = multiplied_digit / 10;
            // Add the digits to the sum
            sum += inner_right_digit + inner_left_digit;
        }
        else
        {
            sum += multiplied_digit;
        }
        // Remove two digits from the right of the credit card number
        credit_card /= 100;
    }
    return sum;
}

// Function to get the sum of the digits that weren't multiplied
int sum_of_other_digits(long credit_card)
{
    int pair_of_digits = 0;
    int right_digit = 0;
    int sum = 0;
    while (credit_card != 0)
    {
        // Get pair of digits
        pair_of_digits = credit_card % 100;
        // Get the right digit
        right_digit = pair_of_digits % 10;
        // Add to the sum
        sum += right_digit;
        // Remove two digits from the right of the credit card number
        credit_card /= 100;
    }
    return sum;
}

bool validate_card(int total_sum)
{
    if (total_sum % 10 == 0)
    {
        return true;
    }
    return false;
}

// Function to Check for the type of the credit card
void type_of_credit_card(long credit_card, bool validation)
{
    int length = 2;
    int left_digit = 0;
    // If validation is true
    if (validation)
    {
        // while credit >= 100
        while (credit_card >= 100)
        {
            // Remove one digit from the right of the credit card number
            credit_card /= 10;
            // Increment the counter by 1
            length++;
        }
        // American Express Validation
        if ((credit_card == 34 || credit_card == 37) && (length == 15))
        {
            printf("AMEX\n");
        }
        // MasterCard Validation
        else if ((credit_card == 51 || credit_card == 52 || credit_card == 53 ||
                  credit_card == 54 || credit_card == 55) &&
                 (length == 16))
        {
            printf("MASTERCARD\n");
        }
        // Visa Validation
        else if ((credit_card / 10) == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        // Invalid
        else
        {
            printf("INVALID\n");
        }
    }
    // Invalid
    else
    {
        printf("INVALID\n");
    }
}
