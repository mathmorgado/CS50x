#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // if for 2
    if (number == 2)
    {
        return true;
    }

    // Filter to get only odd numbers
    if (number % 2 == 1)
    {
        // divide number by all the numbers that are less than its half
        for (int i = 3, h = round(number / 2); i < h; i++)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
