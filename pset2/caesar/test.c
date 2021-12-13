
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main (int argc, char *argv[])
{
    //string plain_text;
    // check for the command line argument
    if (argc == 2)
    {
        // convert key to int
        int key = atoi(argv[1]);
        // store key validity
        //bool valid_key = false;

        // check validity of the key
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
               bool valid_key = true;
            }
            // display usage and terminate the program
            else
            {
                printf("Usage ./caesar key\n");
                return 1;
            }
        }

        // check for upper and lower case letters and apply the formula
        if (0 >= key || key <=9)
        {
            //char plain_text[500];

            string plain_text= get_string("plaintext: ");

            for (int i = 0; i < strlen(plain_text); i++)
            {
                if (isupper(plain_text[i]))
                {
                    plain_text[i] = ((plain_text[i] - 65 + key) % 26) + 65;
                }
                else if (islower(plain_text[i]))
                {
                    plain_text[i] = ((plain_text[i] - 97 + key) % 26) + 97;
                }
            }
            printf("ciphertext: %s\n", plain_text);
        }
    }
    // display usage and terminate the program
    else
    {
        printf("Usage ./caesar key\n");
        return 1;
    }
    return 0;
}
