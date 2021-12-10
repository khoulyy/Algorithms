#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(void)
{
    long long int credit_number;
    int digit;
    int sum_digit = 0;
    int count_digit = 0;
    int multi = 0;
    int right_digit;
    int left_digit;
    long long int rmv = 0;
    long long int reverse = 0;

    // Get input
    do
    {
        cout << "Number: ";
        cin >> credit_number;
    }
    while (credit_number < 1);

    long long int even_credit_number = credit_number;

    // Get the even digit and multiply them by 2
    while (even_credit_number != 0)
    {
        digit = even_credit_number % 100;
        digit = digit / 10;

        even_credit_number /= 100;
        multi = digit * 2;
        
        if (multi > 9)
        {
            right_digit = multi % 10;
            left_digit = multi / 10;
            sum_digit += right_digit + left_digit;
        }
        // Sum the multi
        else
        {
            sum_digit += multi;
        }
    }

    long long int odd_credit_number = credit_number;

    // Reverse the number
    while (odd_credit_number != 0)
    {
        rmv = odd_credit_number % 10;
        reverse = reverse * 10 + rmv;
        odd_credit_number  /= 10;
        count_digit++;
    }
    // Get the odd digits
    while (credit_number != 0)
    {
        digit = credit_number % 100;
        digit %= 10;
        credit_number /= 100;
        sum_digit += digit;
    }
    long long int starting_digits = reverse;
    // Check if card valid or not
    if (sum_digit % 10 == 0)
    {
        // Check if card is American Express
        if ((starting_digits  % 100 == 43 || starting_digits % 100 == 73) && count_digit == 15)
        {
            cout << "AMEX" << endl;
        }
        // Check if card is MasterCard
        else if ((starting_digits % 100 == 15 || starting_digits % 100 == 25 || starting_digits % 100 == 35
                || starting_digits % 100 == 45 || starting_digits % 100 == 55) && count_digit == 16)
                {
                    cout << "MASTERCARD" << endl;
                }
        // Check if card is Visa
        else if ((starting_digits % 10 == 4) && (count_digit == 13 || count_digit == 16))
        {
            cout << "VISA" << endl;
        }
        else
        {
            cout << "INVALID" << endl;
        }
        
    }
    // If invalid
    else
    {
        cout << "INVALID" << endl;
    }
}
