#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float grayscale = (image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0;

            image[h][w].rgbtRed = image[h][w].rgbtGreen = image[h][w].rgbtBlue = round(grayscale);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])

{
    RGBTRIPLE temp_image[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            temp_image[h][w] = image[h][(width - 1) - w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp_image[h][w];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float pixel_count = 0.0;

            float qty_red = 0.0;
            float qty_green = 0.0;
            float qty_blue = 0.0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (((h + i) >= 0 && (h + i) < height) && ((w + j) >= 0 && (w + j) < width))
                    {
                        pixel_count++;

                        qty_red += image[h + i][w + j].rgbtRed;
                        qty_green += image[h + i][w + j].rgbtGreen;
                        qty_blue += image[h + i][w + j].rgbtBlue;
                    }
                }
            }

            temp_image[h][w].rgbtRed = round(qty_red / pixel_count);
            temp_image[h][w].rgbtGreen = round(qty_green / pixel_count);
            temp_image[h][w].rgbtBlue = round(qty_blue / pixel_count);
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp_image[h][w];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];

    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1},
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1},
    };

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int GxRed = 0, GxGreen = 0, GxBlue = 0;
            int GyRed = 0, GyGreen = 0, GyBlue = 0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (((h + i) >= 0 && (h + i) < height) && ((w + j) >= 0 && (w + j) < width))
                    {
                        RGBTRIPLE pixel = image[h + i][w + j];

                        GxRed += pixel.rgbtRed * Gx[i + 1][j + 1];
                        GxGreen += pixel.rgbtGreen * Gx[i + 1][j + 1];
                        GxBlue += pixel.rgbtBlue * Gx[i + 1][j + 1];

                        GyRed += pixel.rgbtRed * Gy[i + 1][j + 1];
                        GyGreen += pixel.rgbtGreen * Gy[i + 1][j + 1];
                        GyBlue += pixel.rgbtBlue * Gy[i + 1][j + 1];
                    }
                }
            }

            int newRed = round(sqrt((GxRed * GxRed) + (GyRed * GyRed)));
            int newGreen = round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
            int newBlue = round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));

            if (newRed > 255)
            {
                newRed = 255;
            }
            if (newGreen > 255)
            {
                newGreen = 255;
            }
            if (newBlue > 255)
            {
                newBlue = 255;
            }

            temp_image[h][w].rgbtRed = newRed;
            temp_image[h][w].rgbtGreen = newGreen;
            temp_image[h][w].rgbtBlue = newBlue;
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp_image[h][w];
        }
    }
}
