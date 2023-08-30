#include "helpers.h"
#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 255)
            {
                continue;
            }
            else
            {
                image[i][j].rgbtRed = 0xff;
                image[i][j].rgbtGreen = 0xff;
                image[i][j].rgbtBlue = 0x00;
            }
        }
    }
}