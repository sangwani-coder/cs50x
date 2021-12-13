#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i< height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int ave = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed)/3.0);
            image[i][j].rgbtBlue = ave;
            image[i][j].rgbtGreen = ave;
            image[i][j].rgbtRed = ave;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            //find the average
            int sepiaRed = round((.393 * pixel.rgbtRed) + (.769 * pixel.rgbtGreen) + (.189 * pixel.rgbtBlue));
            int sepiaGreen = round((.349 * pixel.rgbtRed) + (.686 * pixel.rgbtGreen)  + (.168 * pixel.rgbtBlue));
            int sepiaBlue = round((.272 * pixel.rgbtRed) + (.534 * pixel.rgbtGreen)  + (.131 * pixel.rgbtBlue));


           // check if color channel has exceeded max
           // cap color channel to max 255
           // assign each pixel in the image to the new value
            if (sepiaRed > 255)
            {
               sepiaRed = 255;
               image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
               sepiaGreen = 255;
               image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
               sepiaBlue = 255;
               image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    //copy to temp variable
    for (int i = 0; i < height; i++)
    {
        int current_pos = 0;
        for (int j = width - 1; j >= 0; j--, current_pos++)
        {
            temp[i][current_pos] = image[i][j];
        }
    }

    for (int i = 0; i< height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE temp[height][width];
    /*
    for each row
    for each col
        set count to 0
        for every neighboring pixel within the radius m in the x direction
             add the color to the total
             count++
        final_color = total/count
        setpixel(current x, current y, final_color)

repeat above for y direction
    */
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int rowCord[] = {i - 1, i, i + 1};
            int colCord[] = {j - 1,j, j + 1};

            float redTotal =0, greenTotal =0, blueTotal = 0;

            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col <3; col++)
                {
                    int curRow = rowCord[row];
                    int curCol = colCord[col];

                    if (curRow >=0 && curRow < height && curCol >=0 && curCol <width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];

                        redTotal += pixel.rgbtRed;
                        greenTotal += pixel.rgbtGreen;
                        blueTotal += pixel.rgbtBlue;
                        counter++;
                    }
                }
            }

            temp[i][j].rgbtRed = round(redTotal / counter);
            temp[i][j].rgbtGreen = round(greenTotal / counter);
            temp[i][j].rgbtBlue = round(blueTotal / counter);

        }

    }

    for (int i = 0; i< height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           image[i][j] = temp[i][j];
        }
    }
    return;
}
