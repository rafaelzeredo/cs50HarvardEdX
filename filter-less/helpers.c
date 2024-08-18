#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Float variable to get correct division results on average
    float average = 0, r = 0, g = 0, b = 0;
    // Iterate through all lines (height)
    for (int i = 0 ; i < height ; i++)
    {
        // Iterate through all columns (width)
        for (int j = 0; j< width ; j++)
        {
            // I calculated the average using round function to round the results. Here is where I learned to use the round function:
            // https://iq.opengenus.org/rounding-and-truncating-numbers-in-c/#:~:text=round()%20function%20in%20c,the%20decimal%20value%20is%20from%20%22.
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;
            average = (r + g + b) / 3;
            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
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
            sepiaRed = roundf(flNum);
            // Make sure no value is greater than 255
            if (sepiaRed > 255)
                sepiaRed = 255;
            // Get the green color of each new pixel and round the result
            flNum = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            sepiaGreen = roundf(flNum);
            // Make sure no value is greater than 255
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            // Get the blue color of each new pixel and round the result
            flNum = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);
            sepiaBlue = roundf(flNum);
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
        for (int j = 0; j < width ; j++)
        {
            pixels[i][j].r = image[i][width - (j + 1)].rgbtRed;
            pixels[i][j].g = image[i][width - (j + 1)].rgbtGreen;
            pixels[i][j].b = image[i][width - (j + 1)].rgbtBlue;
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
    // I came up with this very nice way of doing this but I was having an issue
    // when geting check50 to check the 3x3 and 4x4 images.
    // I managed do download them and run my program with printfs to debug
    // In the end it was a simple height - 1 and width - 1 issue to get the
    // right and bottom corners correctly.
    // I searched for the 3x3 and 4x4 issue and found a post online with links for the images
    // I downloaded the 3x3 and 4x4 images from here: https://www.reddit.com/r/cs50/comments/hk65al/pset_4_blur_filter_does_not_work_on_3x3_and_4x4/
    typedef struct
    {
        int r, g, b;
    }
    pixel;

    pixel pixels[height][width];
    // make them integers later shes calling me cant do it now
    float red = 0, green = 0, blue = 0, average = 0;
    // sp is a variable to help check edges/corners. 6 indicates edge, 4 is a corner and 9 is in the middle of the image
    // it is the number of pixels collected and the number by which to divide the total pixels of a given color
    // We always collect the colors from the center pixel so the value of sp starts at 1.
    int sp = 1;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // get the average of all surrounding pixels including the center pixel dinamically
            // First we always get the center pixel
            red = 0;
            green = 0;
            blue = 0;
            sp = 1;
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            //printf("got the main center pixel\n");
            //printf("red: %f | green: %f | blue %f \n", red, green, blue);
            // Then if we're not on top we get the pixel right on top
            if (i > 0)
            {
                red = red + image[i - 1][j].rgbtRed;
                green = green + image[i - 1][j].rgbtGreen;
                blue = blue + image[i - 1][j].rgbtBlue;
                sp++;
                //printf("got the center pixel\n");
                //printf("red: %f | green: %f | blue %f \n", red, green, blue);
                // If not on top left corner, collect the top left pixel
                if (j > 0)
                {
                    red = red + image[i - 1][j - 1].rgbtRed;
                    green = green + image[i - 1][j - 1].rgbtGreen;
                    blue = blue + image[i - 1][j - 1].rgbtBlue;
                    sp++;
                    //printf("got the top left pixel\n");
                    //printf("red: %f | green: %f | blue %f \n", red, green, blue);
                }
                // If not on top right corner collect the top right pixel
                // width - 1 is because width is counting 3x3 not counting from 0
                if (j < (width - 1))
                {
                    red = red + image[i - 1][j + 1].rgbtRed;
                    green = green + image[i - 1][j + 1].rgbtGreen;
                    blue = blue + image[i - 1][j + 1].rgbtBlue;
                    sp++;
                    //printf("got the top right pixel\n");
                    //printf("red: %f | green: %f | blue %f \n", red, green, blue);
                }
            }
            // If we're not at the bottom we get the pixel right at the bottom
            // height - 1 here is because height counts 3x3 but not from 0
            if (i < (height - 1))
            {
                red = red + image[i + 1][j].rgbtRed;
                green = green + image[i + 1][j].rgbtGreen;
                blue = blue + image[i + 1][j].rgbtBlue;
                sp++;
                //printf("got the bottom pixel\n");
                //printf("red: %f | green: %f | blue %f \n", red, green, blue);
                // If not on bottom left corner collect the bottom left pixel
                if (j > 0)
                {
                    red = red + image[i + 1][j - 1].rgbtRed;
                    green = green + image[i + 1][j - 1].rgbtGreen;
                    blue = blue + image[i + 1][j - 1].rgbtBlue;
                    sp++;
                    //printf("got the bottom left pixel\n");
                    //printf("red: %f | green: %f | blue %f \n", red, green, blue);
                }
                // If not on bottom right corner collect the bottom right pixel
                if (j < (width - 1))
                {
                    red = red + image[i + 1][j + 1].rgbtRed;
                    green = green + image[i + 1][j + 1].rgbtGreen;
                    blue = blue + image[i + 1][j + 1].rgbtBlue;
                    sp++;
                    //printf("got the bottom right pixel\n");
                    //printf("i is %i and j is %i. height is %i and width is %i\n", i, j, height, width);
                    //printf("red: %f | green: %f | blue %f \n", red, green, blue);
                }
            }
            if (j > 0)
            {
                // If we're not at the left border, get the left pixel
                red = red + image[i][j - 1].rgbtRed;
                green = green + image[i][j - 1].rgbtGreen;
                blue = blue + image[i][j - 1].rgbtBlue;
                sp++;
                //printf("got the left pixel\n");
                //printf("red: %f | green: %f | blue %f \n", red, green, blue);
            }
            // width - 1 her is because 3x3 does't count from 0
            if (j < (width - 1))
            {
                // If we're not at the right edge, get the pixel on the right
                red = red + image[i][j + 1].rgbtRed;
                green = green + image[i][j + 1].rgbtGreen;
                blue = blue + image[i][j + 1].rgbtBlue;
                sp++;
                //printf("got the right side pixel\n");
                //printf("red: %f | green: %f | blue %f \n", red, green, blue);
            }
            // Now I divide the sum of all colors in pixels by the number of pixels and round them
            printf("This pixel turned. out to be sp: %i\n", sp);
            red = red / sp;
            green = green / sp;
            blue = blue / sp;
            pixels[i][j].r = round(red);
            pixels[i][j].g = round(green);
            pixels[i][j].b = round(blue);
            //printf("after rounding up pixel has:");
            //printf("red: %i | green: %i | blue %i \n", pixels[i][j].r, pixels[i][j].g, pixels[i][j].b);
        }
    }


    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // Then I apply the values to the image colors
            image[i][j].rgbtRed = pixels[i][j].r;
            image[i][j].rgbtGreen = pixels[i][j].g;
            image[i][j].rgbtBlue = pixels[i][j].b;
        }
    }
    return;
}






