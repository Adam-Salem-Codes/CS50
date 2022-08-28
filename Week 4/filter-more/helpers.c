#include "helpers.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Converting all color values to floats.
            float R = image[j][i].rgbtRed;
            float G = image[j][i].rgbtGreen;
            float B = image[j][i].rgbtBlue;

            int gray = round((R + G + B) / 3); // Calculates the average of the color values.

            // Sets all of the images color values to the average.
            image[j][i].rgbtBlue = gray;
            image[j][i].rgbtGreen = gray;
            image[j][i].rgbtRed = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int middle = width / 2; // Gets the middle of the image. (width / 2 equals the middle of the image).

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < middle; j++)
        {
            RGBTRIPLE tmp = image[i][j]; // Creates a temporary copy of the image.

            image[i][j] = image[i][width - j - 1];

            image[i][width - j - 1] = tmp;
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagecopy[height][width]; // Declaring copy of image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagecopy[i][j] = image[i][j]; // Copying the original image into the copy.
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int R, G, B;
            R = G = B = 0; // Setting all of the RGB values to zero.
            float n = 0.00; // Declaring counter.

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // Looping through the 3x3 box.

                    int X = i + x;
                    int Y = j + y;

                    if (X < 0 || X > (height - 1) ||
                        Y < 0 || Y > (width - 1))
                    {
                        continue;
                    }

                    R += image[X][Y].rgbtRed;
                    G += image[X][Y].rgbtGreen;
                    B += image[X][Y].rgbtBlue;
                    n++; // Counter = Counter + 1.
                }

                imagecopy[i][j].rgbtRed = round(R / n);
                imagecopy[i][j].rgbtGreen = round(G / n);
                imagecopy[i][j].rgbtBlue = round(B / n);

            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Copying copy of image into the original image.
            image[i][j].rgbtRed = imagecopy[i][j].rgbtRed;
            image[i][j].rgbtGreen = imagecopy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = imagecopy[i][j].rgbtBlue;

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cpy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cpy[i][j] = image[i][j];
        }
    }

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int RX = 0;
            int GX = 0;
            int BX = 0;
            int RY = 0;
            int GY = 0;
            int BY = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (i - 1 + x < 0 || i - 1 + x > height - 1 || j
                        - 1 + y < 0 || j - 1 + y > width - 1)
                    {
                        continue;
                    }

                    RX += (image[i - 1 + x][j - 1 + y].rgbtRed * gx[x][y]);

                    GX += (image[i - 1 + x][j - 1 + y].rgbtGreen * gx[x][y]);

                    BX += (image[i - 1 + x][j - 1 + y].rgbtBlue * gx[x][y]);

                    RY += (image[i - 1 + x][j - 1 + y].rgbtRed * gy[x][y]);

                    GY += (image[i - 1 + x][j - 1 + y].rgbtGreen * gy[x][y]);

                    BY += (image[i - 1 + x][j - 1 + y].rgbtBlue * gy[x][y]);


                }
            }

            int red = round(sqrt((RX * RX) + (RY * RY)));
            int green = round(sqrt((GX * GX) + (GY * GY)));
            int blue = round(sqrt((BX * BX) + (BY * BY)));

            if (red > 255) // If the red value is bigger than 255 set it to 255.
            {
                red = 255;
            }
            if (green > 255) // If the green value is bigger than 255 set it to 255.
            {
                green = 255;
            }
            if (blue > 255) // If the blue value is bigger than 255 set it to 255.
            {
                blue = 255;
            }

            cpy[i][j].rgbtRed = red;

            cpy[i][j].rgbtGreen = green;

            cpy[i][j].rgbtBlue = blue;

            // Setting the copy images pixels equal to the new RGB values.

        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = cpy[i][j].rgbtRed;
            image[i][j].rgbtGreen = cpy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = cpy[i][j].rgbtBlue;

        }
    }
    return;
}
