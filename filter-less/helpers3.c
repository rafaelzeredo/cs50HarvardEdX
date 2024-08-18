#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Float variable to get correct division results on average
    float average = 0;
    // Iterate through all lines (height)
    for (int i = 0 ; i < height ; i++)
    {
        // Iterate through all columns (width)
        for (int j = 0; j< width ; j++)
        {
            // I calculated the average using round function to round the results. Here is where I learned to use the round function:
            // https://iq.opengenus.org/rounding-and-truncating-numbers-in-c/#:~:text=round()%20function%20in%20c,the%20decimal%20value%20is%20from%20%22.
            average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = lroundf(average);
            image[i][j].rgbtGreen = lroundf(average);
            image[i][j].rgbtBlue = lroundf(average);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float flNum = 0;
    int sepiaRed = 0, sepiaGreen = 0, sepiaBlue = 0;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // Get the Red color of each new pixel and round the result
            flNum = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);
            sepiaRed = lroundf(flNum);
            // Make sure no value is greater than 255
            if (sepiaRed > 255)
                sepiaRed = 255;
            // Get the green color of each new pixel and round the result
            flNum = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            sepiaGreen = lroundf(flNum);
            // Make sure no value is greater than 255
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            // Get the blue color of each new pixel and round the result
            flNum = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);
            sepiaBlue = lroundf(flNum);
            // Make sure no value is greater than 255
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        int r, g, b;
    }
    pixel;

    pixel pixels[height][width];

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0; j< width ; j++)
        {
            pixels[i][j].r = image[i][width - j].rgbtRed;
            pixels[i][j].g = image[i][width - j].rgbtGreen;
            pixels[i][j].b = image[i][width - j].rgbtBlue;
        }
    }

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0; j< width ; j++)
        {
            image[i][j].rgbtRed = pixels[i][j].r;
            image[i][j].rgbtGreen = pixels[i][j].g;
            image[i][j].rgbtBlue = pixels[i][j].b;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        int r, g, b;
    }
    pixel;

    pixel pixels[height][width];
    float red = 0, green = 0, blue = 0, average = 0;
    // sp is a variable to help check edges/corners. 6 indicates edge, 4 is a corner and 9 is in the middle of the image
    // it is the number of pixels collected and the number by which to divide the total pixels of a given color
    int sp = 1;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // get the average of all surrounding pixels including the center pixel dinamically
            // First we always get the center pixel
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            if (i != 0)
            {
                // Then if we're not on top we get the pixel right on top
                average = image[i - 1][j].rgbtRed;
                sp++;
            }
            if (i != height)
            {
                // If we're not at the bottom we get the pixel right at the bottom
                average = image[i + 1][j].rgbtRed;
                sp++;
            }
            if (j != 0)
            {
                // If we're not at the left border, get the left pixel
                average = image[i][j - 1].rgbtRed;
                sp++;
            }
            if (j != width)
            {
                // If we're not at the right edge, get the pixel on the right
                average = image[i][j + 1].rgbtRed;
                sp++;
            }
            // Now we deal with the corner cases. If not on top left corner, collect the top left pixel
            if (i != 0 && j != 0)
            {
                average = image[i - 1][j - 1].rgbtRed;
                sp++;
            }
            // If not on top right corner collect the top right pixel
            if (i != 0 && j != width)
            {
                average = image[i - 1][j + 1].rgbtRed;
                sp++;
            }
            // If not on bottom left corner collect the bottom left pixel
            if (i != height && j != 0)
            {
                average = image[i + 1][j - 1].rgbtRed;
                sp++;
            }
            // If not on bottom right corner collect the bottom right pixel
            if (i != height && j != width)
            {
                average = image[i + 1][j + 1].rgbtRed;
                sp++;
            }








            average = (image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed);
            average = average + (image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed);
            average = average + (image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
            average = average / 9;
            pixels[i][j].r = lroundf(average);
            // set it to image
            image[i][j].rgbtRed = pixels[i][j].r;

            // get average of green in all surrounding pixels
            average = (image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen);
            average = average + (image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen);
            average = average + (image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
            average = average / 9;
            pixels[i][j].g = lroundf(average);
            // set it to image
            image[i][j].rgbtGreen = pixels[i][j].g;

            // get average of blue in all surrouning pixels
            average = (image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue);
            average = average + (image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue);
            average = average + (image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
            average = average / 9;
            pixels[i][j].b = lroundf(average);
            // set it to image
            image[i][j].rgbtBlue = pixels[i][j].b;

        }
    }
    return;
}
