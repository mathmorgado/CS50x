#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's X? ");
    int y = get_int("What's Y? ");

    if (x < y)
    {
        printf("X is less then Y\n");
    }
    else if (x > y)
    {
        printf("X is greater then Y\n");
    }
    else
    {
        printf("X is equal Y\n");
    }
}