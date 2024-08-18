#include <cs50.h>
#include <stdio.h>

int main (void)
{
    typedef struct
    {
        int r, g, b;
    }
    pixel;

    typedef struct
    {
        int rgbtRed;
        int rgbtGreen;
        int rgbtBlue;
    }
    image

    pixel pixels[height][width];
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
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            if (i != 0)
            {
                // Then if we're not on top we get the pixel right on top
                red = red + image[i - 1][j].rgbtRed;
                green = green + image[i - 1][j].rgbtGreen;
                blue = blue + image[i - 1][j].rgbtBlue;
                sp++;
            }
            if (i != height)
            {
                // If we're not at the bottom we get the pixel right at the bottom
                red = red + image[i + 1][j].rgbtRed;
                green = green + image[i + 1][j].rgbtGreen;
                blue = blue + image[i + 1][j].rgbtBlue;
                sp++;
            }
            if (j != 0)
            {
                // If we're not at the left border, get the left pixel
                red = red + image[i][j - 1].rgbtRed;
                green = green + image[i][j - 1].rgbtGreen;
                blue = blue + image[i][j - 1].rgbtBlue;
                sp++;
            }
            if (j != width)
            {
                // If we're not at the right edge, get the pixel on the right
                red = red + image[i][j + 1].rgbtRed;
                green = green + image[i][j + 1].rgbtGreen;
                blue = blue + image[i][j + 1].rgbtBlue;
                sp++;
            }
            // Now we deal with the corner cases. If not on top left corner, collect the top left pixel
            if (i != 0 && j != 0)
            {
                red = red + image[i - 1][j - 1].rgbtRed;
                green = green + image[i - 1][j - 1].rgbtGreen;
                blue = blue + image[i - 1][j - 1].rgbtBlue;
                sp++;
            }
            // If not on top right corner collect the top right pixel
            if (i != 0 && j != width)
            {
                red = red + image[i - 1][j + 1].rgbtRed;
                green = green + image[i - 1][j + 1].rgbtGreen;
                blue = blue + image[i - 1][j + 1].rgbtBlue;
                sp++;
            }
            // If not on bottom left corner collect the bottom left pixel
            if (i != height && j != 0)
            {
                red = red + image[i + 1][j - 1].rgbtRed;
                green = green + image[i + 1][j - 1].rgbtGreen;
                blue = blue + image[i + 1][j - 1].rgbtBlue;
                sp++;
            }
            // If not on bottom right corner collect the bottom right pixel
            if (i != height && j != width)
            {
                red = red + image[i + 1][j + 1].rgbtRed;
                green = green + image[i + 1][j + 1].rgbtGreen;
                blue = blue + image[i + 1][j + 1].rgbtBlue;
                sp++;
            }
            // Now I divide the sum of all colors in pixel by the number of pixels and round them
            red = red / sp;
            green = green / sp;
            blue = blue / sp;
            pixels[i][j].r = lroundf(red);
            pixels[i][j].g = lroundf(green);
            pixels[i][j].b = lroundf(blue);
            // Then I apply the values to the image colors
            image[i][j].rgbtRed = pixels[i][j].r;
            image[i][j].rgbtGreen = pixels[i][j].g;
            image[i][j].rgbtBlue = pixels[i][j].b;
        }
    }
    return;
}





// Other algorithm
{
    // I created a structure to copy the image so that the blurred image is first generated in the copy
    // This is in order to not corrupt the data as the filter is processing each pixel
    typedef struct
    {
        int r, g, b;
    }
    pixel;

    pixel pixels[height][width];
    float floatRed = 0, floatGreen = 0, floatBlue = 0;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // If pixel is at the TOP and the LEFT, in this case collect pixels to the right and bottom
            if (i == 0 && j == 0)
            {
                ///.       /---First the pixels to the center and right--/. /---------Then pixels to the bottom right-------------/ Divide by 4
                floatRed = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4;
                ///.        /--First the pixels to the center and right-----/. /------------------The the pixels to the bottom right--/ Divide by 4
                floatBlue = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4;
                ///.         /-First the pixels to the center and right-------/.  /-------The the pixels to the bottom right--------------/ Divide by 4
                floatGreen = (image[i][j].rgbtGreen + image[i][j+ 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
            // If pixel is somewhere in the TOP MIDDLE
            else if (i == 0 && j > 0 && j < width)
            {   //.           Center-left               Center-pixel             Center-right.            Bottom-left.                   Bottom-center.             Bottom-right.        Divide by 6
                floatRed = (image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6;
                floatBlue = (image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6;
                floatGreen = (image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
            // If the pixel is at the TOP and the RIGHT
            else if (i == 0 && j == width)
            {
                //               First pixels to the center left,                  then pixels to the bottom left
                floatRed = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4;
                floatBlue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4;
                floatGreen = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
            // If the pixel is at the MIDDLE RIGHT
            else if (i > 0 && i < height && j == width)
            {
                //.              center                 top.                        bottom.                    left.                   top-left.                     bottom-left.           Divide by 6
                floatRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6;
                floatBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6;
                floatGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);

            }
            // If pixel is at the BOTTOM RIGHT corner
            else if (i == height && j == width)
            {
                ///.           center.                     top.                     left.                    top-left
                floatRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4;
                floatBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4;
                floatGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
            // If the pixel is somewher at the BOTTOM MIDDLE
            else if (i == height && j < width && j > 0)
            {
                ///.             center.               center-left.           center-right.                  top.                  top-left.                    top-right
                floatRed = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6;
                floatBlue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6;
                floatGreen = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
            // If pixel is at the BOTTOM LEFT corner
            if (i == height && j == 0)
            {
                //.            center.                   top.                    right                      top-right
                floatRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4;
                floatBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4;
                floatGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
            // If the pixel is at the MIDDLE LEFT
            if (j == 0 && i < height && i > 0)
            {
                //.                center.                 top.                    bottom.                   right.                   top-right.                   bottom-right.      Divide by 6
                floatRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6;
                floatBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6;
                floatGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) /6;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
            // If the pixel is not touching any edges (NO EDGES)
            else if (i > 0 && i < height && j > 0 && j < width)
            {
                //.                  center.               top.                    bottom.                      left.                      right.                  top-left.                     top-right.                       bottom-left.                 bottom-right.              Divide by 9
                floatRed = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9;
                floatBlue = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9;
                floatGreen = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9;
                pixels[i][j].r = lroundf(floatRed);
                pixels[i][j].g = lroundf(floatGreen);
                pixels[i][j].b = lroundf(floatBlue);
            }
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
