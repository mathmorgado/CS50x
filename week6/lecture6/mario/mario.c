#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h <= 0);

    for (int i = 0; i < h; i++)
    {
        printf("#\n");
    }
}