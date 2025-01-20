#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                temp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = temp;
            }
        }

        if (width % 2 != 0)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                temp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed, sumGreen, sumBlue, counter;
            sumRed = sumGreen = sumBlue = counter = 0;

            for (int p = -1; p < 2; p++)
            {
                for (int q = -1; q < 2; q++)
                {
                    if (i + p < 0 || i + p > (height - 1))
                    {
                        continue;
                    }
                    if (j + q < 0 || j + q > (width - 1))
                    {
                        continue;
                    }

                    sumRed += image[i + p][j + q].rgbtRed;
                    sumGreen += image[i + p][j + q].rgbtGreen;
                    sumBlue += image[i + p][j + q].rgbtBlue;
                    counter++;
                }
            }

            copy[i][j].rgbtRed = round(sumRed / counter);
            copy[i][j].rgbtGreen = round(sumGreen / counter);
            copy[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Sobel operator Gx and Gy kernels
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxRed, gxGreen, gxBlue, gyRed, gyGreen, gyBlue, red, green, blue;
            gxRed = gxGreen = gxBlue = gyRed = gyGreen = gyBlue = 0;

            for (int p = -1; p < 2; p++)
            {
                for (int q = -1; q < 2; q++)
                {
                    if (i + p < 0 || i + p > (height - 1))
                    {
                        continue;
                    }
                    if (j + q < 0 || j + q > (width - 1))
                    {
                        continue;
                    }

                    // calculate value of gx and gy for RGB colors in pixel by multiplying each
                    // pixel in 9x9 grid with Gx and Gy arrays respective value
                    gxRed += image[i + p][j + q].rgbtRed * gx[p + 1][q + 1];
                    gyRed += image[i + p][j + q].rgbtRed * gy[p + 1][q + 1];
                    gxGreen += image[i + p][j + q].rgbtGreen * gx[p + 1][q + 1];
                    gyGreen += image[i + p][j + q].rgbtGreen * gy[p + 1][q + 1];
                    gxBlue += image[i + p][j + q].rgbtBlue * gx[p + 1][q + 1];
                    gyBlue += image[i + p][j + q].rgbtBlue * gy[p + 1][q + 1];
                }
            }

            // calculate amount of RGB by solving gx and gy values of RGB
            red = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));

            // copy color to image's copy and cap values of RGB to 255 if more than that
            copy[i][j].rgbtRed = (red > 255) ? 255 : red;
            copy[i][j].rgbtGreen = (green > 255) ? 255 : green;
            copy[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
