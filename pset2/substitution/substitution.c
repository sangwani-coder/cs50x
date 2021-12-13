#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, string argv[])
{
    // check for arguments and key length
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        // check for non-duplicate alphabet letters
        bool valid_key = false;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            for (int j = i + 1; j < strlen(argv[1]) + 1; j++)
            {
                if (isalpha(argv[1][i]) && tolower(argv[1][i]) != tolower(argv[1][j])) //Convert uppercase char to lowercase
                {
                    valid_key = true;
                }
                else
                {
                    printf("Usage ./substitution key\n");
                    return 1;
                }

            }

        }

        // get plaintext
        string plain_text = get_string("plaintext: ");
        printf("\n");

        // encrypt letter
        for (int i = 0; i < strlen(plain_text); i++)
        {
            if (islower(plain_text [i]))
            {
                plain_text [i] = tolower(argv[1][plain_text [i] - 97]);
            }
            else if (isupper(plain_text [i]))
            {
                plain_text [i] = toupper(argv[1][plain_text [i] - 65]);
            }
        }

        // output ciphertext
        printf("ciphertext: %s", plain_text);
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage ./substitution key\n");
        return 1;
    }

}