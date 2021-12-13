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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int GX[3][3];
    int GY[3][3];

    GX[0][0] = -1, GX[0][1] = 0, GX[0][2] = 1;
    GX[1][0] = -2, GX[1][1] = 0, GX[1][2] = 2;
    GX[2][0] = -1, GX[2][1] = 0, GX[2][2] = 1;

    /* 3x3 GY Sobel mask.  Ref: www.cee.hw.ac.uk/hipr/html/sobel.html */
    GY[2][0] = -1, GY[2][1] = -2, GY[2][2] = -1;
    GY[1][0] =  0, GY[1][1] =  0, GY[1][2] =  0;
    GY[0][0] =  1, GY[0][1] =  2, GY[0][2] =  1;


    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            int rowCord[] = {i - 1, i, i + 1};
            int colCord[] = {j - 1,j, j + 1};

            float redGx =0, greenGx =0, blueGx = 0;
            float redGy =0, greenGy =0, blueGy = 0;

            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col <3; col++)
                {
                    int curRow = rowCord[row];
                    int curCol = colCord[col];

                    if (curRow >=0 && curRow < height && curCol >=0 && curCol <width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];

                        redGx += GX[row][col] * pixel.rgbtRed;
                        greenGx += GX[row][col]  * pixel.rgbtGreen;
                        blueGx += GX[row][col] * pixel.rgbtBlue;

                        redGy += GY[row][col] * pixel.rgbtRed;
                        greenGy += GY[row][col]  * pixel.rgbtGreen;
                        blueGy += GY[row][col] * pixel.rgbtBlue;

                    }
                }
            }
            int R = round(sqrt(redGx * redGx + redGy * redGy));
            int G = round(sqrt(greenGx * greenGx + greenGy * greenGy));
            int B = round(sqrt(blueGx * blueGx + blueGy * blueGy));

            if (R > 255)
            {
               R = 255;
               temp[i][j].rgbtRed = R;
            }
            else
            {
                temp[i][j].rgbtRed = R;
            }

            if (G > 255)
            {
               G = 255;
               temp[i][j].rgbtGreen = G;
            }
            else
            {
                temp[i][j].rgbtGreen = G;
            }
            if (B > 255)
            {
               B= 255;
               temp[i][j].rgbtBlue = B;
            }
            else
            {
                temp[i][j].rgbtBlue = B;
            }
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
