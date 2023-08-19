#include <cs50.h>
#include <stdio.h>

long verify_num_card(long credit_card);
void verify_card(long digit);

long number_of_digits = 0;
long first_digit;
long second_digit;

int main(void)
{
    long credit_card = get_long("Credit card: ");
    long digit = verify_num_card(credit_card);

    verify_card(digit);
}

long verify_num_card(long credit_card)
{
    long get_digit = 10;
    long digits = 100;
    long digit = (credit_card % digits) / get_digit;
    long sum = 0;

    do
    {
        digit = (credit_card % digits) / get_digit;
        digit = digit * 2;

        if (digit >= 10)
        {
            long digit1 = digit / 10;
            long digit2 = digit % 10;
            sum += digit1 + digit2;
        }
        else
        {
            sum += digit;
        }

        get_digit *= 100;
        digits *= 100;
        number_of_digits++;
    }
    while (get_digit <= credit_card);

    if (number_of_digits % 2 == 0)
    {
        first_digit = digit / 2;
    }
    else
    {
        second_digit = digit / 2;
    }

    get_digit = 1;
    digits = 10;

    do
    {
        digit = (credit_card % digits) / get_digit;
        sum += digit;

        get_digit *= 100;
        digits *= 100;
        number_of_digits++;
    }
    while (get_digit <= credit_card);

    if (number_of_digits % 2 != 0)
    {
        first_digit = digit;
    }
    else
    {
        second_digit = digit;
    }

    return sum;
}

void verify_card(long digit)
{
    if (digit % 10 == 0)
    {
        if (first_digit == 4 && (number_of_digits == 13 || number_of_digits == 16))
        {
            printf("VISA\n");
        }
        else if (number_of_digits == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
        {
            printf("AMEX\n");
        }
        else if (number_of_digits == 16 && first_digit == 5 && second_digit < 6)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}