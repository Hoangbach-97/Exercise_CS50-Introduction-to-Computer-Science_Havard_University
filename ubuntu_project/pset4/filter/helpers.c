#include "helpers.h"
#include <math.h>
#include<cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])

{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            // Take avarage value
            int avarage = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avarage;
        }
    }


}
int cap(int value)
{
    return value > 255? 255 : value;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;
            image[i][j].rgbtRed = cap(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[i][j].rgbtGreen = cap(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            image[i][j].rgbtBlue = cap(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));


        }

    }


}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 =temp;

}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i= 0; i<height ; i++)
    {
        for(int j =0; j< (width/2); j++)
        {
            swap(&image[i][j],&image[i][width-1-i]);
        }
    }

}

bool is_valid_pixel(int i, int j,int height,int width)
{
    return i>=0 && i <=height && j>=0 &&j<=width;
}

RGBTRIPLE get_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width] )
{
    int redValue, greenValue, blueValue;
    redValue = greenValue = blueValue = 0;
    int numOfValidPixel = 0;
    // From central number: one step back/forward (row, column)
    for(int di = -1; di<=1; di++)
    {
        for(int dj = -1; dj<=1; dj++)
        {
            int new_i = i+ di;
            int new_j = j+ dj;
            if(is_valid_pixel(new_i, new_j, height, width))
            {
                numOfValidPixel++;
                redValue += image[new_i][new_j].rgbtRed;
                greenValue += image[new_i][new_j].rgbtGreen;
                blueValue += image[new_i][new_j].rgbtBlue;
            }
        }
    }
    RGBTRIPLE blur_pixel;
    blur_pixel.rgbtRed = round((float)redValue/numOfValidPixel);
    blur_pixel.rgbtGreen = round((float)greenValue/numOfValidPixel);
    blur_pixel.rgbtBlue = round((float)blueValue/numOfValidPixel);
    return blur_pixel;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


    RGBTRIPLE new_image[height][width];

    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            new_image[i][j] = get_blur(i, j, height, width, image);

        }
    }
    for(int i = 0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j]=new_image[i][j];
        }
    }

}
