#include <cs50.h>
#include <stdio.h>

int get_height(void);
void duol_pyramid(int height);
void left_pyramid(int height, int h);

int main(void)
{
    int height = get_height();
    duol_pyramid(height);
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

void duol_pyramid(int height)
{
    int h;
    for (h = 1; h <= height; h++)
    {
        int spc;
        for (spc = height - h; spc > 0; spc--)
        {
            printf(" ");
        }

        left_pyramid(height, h);

        printf("  ");

        left_pyramid(height, h);

        printf("\n");
    }
}

void left_pyramid(int height, int h)
{
    for (int hs = 0; hs < h; hs++)
    {
        printf("#");
    }
}