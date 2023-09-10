#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");

    if (x > y)
    {
        printf("X is greater then Y!\n");
    }
    else if (y > x)
    {
        printf("Y is greater then X!\n");
    }
    else
    {
        printf("X and Y is equal!\n");
    }
}