#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pixel = image[h][w];
            float gray = (pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0;

            image[h][w].rgbtRed = image[h][w].rgbtGreen = image[h][w].rgbtBlue = round(gray);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pixel = image[h][w];

            float sepiaRed = .393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue;
            float sepiaGreen = .349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue;
            float sepiaBlue = .272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue;

            if (sepiaRed > 255 || sepiaGreen > 255 || sepiaBlue > 255)
            {
                if (sepiaRed > 255)
                {
                    sepiaRed = 255;
                }
                if (sepiaGreen > 255)
                {
                    sepiaGreen = 255;
                }
                if (sepiaBlue > 255)
                {
                    sepiaBlue = 255;
                }
            }

            image[h][w].rgbtRed = round(sepiaRed);
            image[h][w].rgbtGreen = round(sepiaGreen);
            image[h][w].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_line[width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pixel = image[h][(width - 1) - w];

            temp_line[w] = pixel;
        }

        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp_line[w];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int valid_pixel_count = 0;

            int avarege_Red = 0;
            int avarege_Green = 0;
            int avarege_Blue = 0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (h + i >= 0 && h + i < height)
                    {
                        if (w + j >= 0 && w + j < width)
                        {
                            valid_pixel_count++;

                            avarege_Red += image[h + i][w + j].rgbtRed;
                            avarege_Green += image[h + i][w + j].rgbtGreen;
                            avarege_Blue += image[h + i][w + j].rgbtBlue;
                        }
                    }
                }
            }

            float total_red = (float) avarege_Red / valid_pixel_count;
            float total_green = (float) avarege_Green / valid_pixel_count;
            float total_blue = (float) avarege_Blue / valid_pixel_count;

            temp_image[h][w].rgbtRed = round(total_red);
            temp_image[h][w].rgbtGreen = round(total_green);
            temp_image[h][w].rgbtBlue = round(total_blue);
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp_image[h][w];
        }
    }
    return;
}
