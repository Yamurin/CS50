#include "helpers.h"
#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            if (image[w][h].rgbtBlue  == 0 &&
                image[w][h].rgbtGreen == 0 &&
                image[w][h].rgbtRed   == 0)
            {
                image[w][h].rgbtBlue  = 255;
                image[w][h].rgbtGreen = 0;
                image[w][h].rgbtRed   = 0;
            }
        }
    }
}
