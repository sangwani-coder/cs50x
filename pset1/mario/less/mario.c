#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {

   height = get_int ("Height:");

    }
    while (height < 1 || height > 8);

    // outer loop iterating through each row
     for (int i= 1; i <= height; i++)
    {
        //loop for spaces
        for (int h=i; h < height; h++)
        {
            printf(" ");
        }

        // innner loop to print hashes
        for(int j=1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }


}

