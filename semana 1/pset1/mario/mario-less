#include <cs50.h>
#include <stdio.h>

int get_height(void);
void hashes_pyramid(int height);

int main(void)
{
    // input height (1 to 8)
    int height = get_height();

    // print hashes (pyramid)
    hashes_pyramid(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void hashes_pyramid(int height)
{
    int h;
    for (h = 1; h <= height; h++)
    {
        int spc;
        for (spc = height - h; spc > 0; spc--)
        {
            printf(" ");
        }

        for (int hs = 0; hs < h; hs++)
        {
            printf("#");
        }
        printf("\n");
    }
}