#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rgbaverage = round(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) + (3 / 2)) / 3);
            image[i][j].rgbtRed = rgbaverage;
            image[i][j].rgbtGreen = rgbaverage;
            image[i][j].rgbtBlue = rgbaverage;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagetemp[height][width];
    for (int i = 0; i < height; i ++)
    {
        //Flip right hand to left
        for (int j = 0; j < width / 2; j++)
        {
            imagetemp[i][j] = image[i][(width - 1) - j];
        }
        //Flip left hand to right
        for (int j = width / 2; j < width; j++)
        {
            imagetemp[i][j] = image[i][abs(j + 1 - width)];
        }
    }
    memcpy(image, imagetemp, sizeof imagetemp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagetemp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float blue = 0;
            float green = 0;
            int pixlecount = 0;

            if (j + 1 < width)
            {
                red += image[i][j + 1].rgbtRed;
                blue += image[i][j + 1].rgbtBlue;
                green += image[i][j + 1].rgbtGreen;
                pixlecount++;
            }
            if (j - 1 >= 0)
            {
                red += image[i][j - 1].rgbtRed;
                blue += image[i][j - 1].rgbtBlue;
                green += image[i][j - 1].rgbtGreen;
                pixlecount++;
            }
            if (i + 1 < height)
            {
                red += image[i + 1][j].rgbtRed;
                blue += image[i + 1][j].rgbtBlue;
                green += image[i + 1][j].rgbtGreen;
                pixlecount++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                red += image[i + 1][j + 1].rgbtRed;
                blue += image[i + 1][j + 1].rgbtBlue;
                green += image[i + 1][j + 1].rgbtGreen;
                pixlecount++;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                red += image[i + 1][j - 1].rgbtRed;
                blue += image[i + 1][j - 1].rgbtBlue;
                green += image[i + 1][j - 1].rgbtGreen;
                pixlecount++;
            }
            if (i - 1 >= 0)
            {
                red += image[i - 1][j].rgbtRed;
                blue += image[i - 1][j].rgbtBlue;
                green += image[i - 1][j].rgbtGreen;
                pixlecount++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += image[i - 1][j + 1].rgbtRed;
                blue += image[i - 1][j + 1].rgbtBlue;
                green += image[i - 1][j + 1].rgbtGreen;
                pixlecount++;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += image[i - 1][j - 1].rgbtRed;
                blue += image[i - 1][j - 1].rgbtBlue;
                green += image[i - 1][j - 1].rgbtGreen;
                pixlecount++;
            }
            red += image[i][j].rgbtRed;
            blue += image[i][j].rgbtBlue;
            green += image[i][j].rgbtGreen;
            pixlecount++;

            imagetemp[i][j].rgbtRed = round(red / pixlecount);
            imagetemp[i][j].rgbtBlue = round(blue / pixlecount);
            imagetemp[i][j].rgbtGreen = round(green / pixlecount);
        }
    }
    memcpy(image, imagetemp, sizeof imagetemp);
    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagetemp[height + 2][width + 2];
    memset(imagetemp, 0, height + 2 * width + 2 * sizeof(RGBTRIPLE));

    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            imagetemp[i][j].rgbtRed = 0;
            imagetemp[i][j].rgbtBlue = 0;
            imagetemp[i][j].rgbtGreen = 0;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagetemp[i][j].rgbtRed = image[i][j].rgbtRed;
            imagetemp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            imagetemp[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }
    for (int i = 0; i < height + 2; i++)
    {
        RGBTRIPLE temp = imagetemp[i][width + 1];
        for (int j = width + 1; j > 0; j--)
        {
            imagetemp[i][j] = imagetemp[i][j - 1];
        }
        imagetemp[i][0] = temp;
    }
    for (int j = 0; j < width + 2; j++)
    {
        RGBTRIPLE temp = imagetemp[height + 1][j];
        for (int i = height + 1; i > 0; i--)
        {
            imagetemp[i][j] = imagetemp[i - 1][j];
        }
        imagetemp[0][j] = temp;
    }
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            int gxr = ((imagetemp[i - 1][j - 1].rgbtRed * - 1) + (imagetemp[i - 1][j + 1].rgbtRed) + (imagetemp[i][j - 1].rgbtRed * -2) +
                       (imagetemp[i][j + 1].rgbtRed * 2) + (imagetemp[i + 1][j - 1].rgbtRed * -1) + (imagetemp[i + 1][j + 1].rgbtRed));
            int gxb = ((imagetemp[i - 1][j - 1].rgbtBlue * - 1) + (imagetemp[i - 1][j + 1].rgbtBlue) + (imagetemp[i][j - 1].rgbtBlue * -2) +
                       (imagetemp[i][j + 1].rgbtBlue * 2) + (imagetemp[i + 1][j - 1].rgbtBlue * -1) + (imagetemp[i + 1][j + 1].rgbtBlue));
            int gxg = ((imagetemp[i - 1][j - 1].rgbtGreen * - 1) + (imagetemp[i - 1][j + 1].rgbtGreen) + (imagetemp[i][j - 1].rgbtGreen * -2) +
                       (imagetemp[i][j + 1].rgbtGreen * 2) + (imagetemp[i + 1][j - 1].rgbtGreen * -1) + (imagetemp[i + 1][j + 1].rgbtGreen));

            int gyr = ((imagetemp[i - 1][j - 1].rgbtRed * - 1) + (imagetemp[i - 1][j].rgbtRed * -2) + (imagetemp[i - 1][j + 1].rgbtRed * -1) +
                       (imagetemp[i + 1][j - 1].rgbtRed) + (imagetemp[i + 1][j].rgbtRed * 2) + (imagetemp[i + 1][j + 1].rgbtRed));
            int gyb = ((imagetemp[i - 1][j - 1].rgbtBlue * - 1) + (imagetemp[i - 1][j].rgbtBlue * -2) + (imagetemp[i - 1][j + 1].rgbtBlue * -1)
                       + (imagetemp[i + 1][j - 1].rgbtBlue) + (imagetemp[i + 1][j].rgbtBlue * 2) + (imagetemp[i + 1][j + 1].rgbtBlue));
            int gyg = ((imagetemp[i - 1][j - 1].rgbtGreen * - 1) + (imagetemp[i - 1][j].rgbtGreen * -2) +
                       (imagetemp[i - 1][j + 1].rgbtGreen * -1) +
                       (imagetemp[i + 1][j - 1].rgbtGreen) + (imagetemp[i + 1][j].rgbtGreen * 2) + (imagetemp[i + 1][j + 1].rgbtGreen));

            int red = round(sqrt(pow(gxr, 2) + pow(gyr, 2)));
            int blue = round(sqrt(pow(gxb, 2) + pow(gyb, 2)));
            int green = round(sqrt(pow(gxg, 2) + pow(gyg, 2)));
            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            image[i - 1][j - 1].rgbtRed = red;
            image[i - 1][j - 1].rgbtBlue = blue;
            image[i - 1][j - 1].rgbtGreen = green;
        }
    }
    return;
}