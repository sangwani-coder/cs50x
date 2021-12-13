#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {

   height = get_int("Height:");

    }
    while (height < 1 || height > 8);


    //main loop
    for (int i = 1; i <= height; i++)
    {

//first pyramid loop
//loop to align first pyramid to right
    for (int h=i; h < height; h++)
    {
    printf(" ");
    }

    // innner loop to print first pyramid hashes
    for (int j = 1; j <= i; j++)
    {
    printf("#");
    }

    //loop for spaces between pyramids
    for (int k = i; k <= i; k++)
    {
    printf("  ");
    }

    // second pyramid loop

    for(int j = 1; j <= i; j++)
    {
    printf("#");
    }

    printf("\n");
    }
}

