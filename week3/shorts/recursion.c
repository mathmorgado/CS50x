#include <cs50.h>
#include <stdio.h>

int collatz(int num);
int steps = 0;

int main(void)
{
    int num = get_int("Digit: ");
    printf("%i\n", collatz(num));
}

int collatz(int num)
{
    if (num == 1)
    {
        return steps;
    }
    else if (num % 2 == 0)
    {
        steps++;
        return collatz(num / 2);
    }
    else
    {
        steps++;
        return collatz((num * 3) + 1);
    }
}