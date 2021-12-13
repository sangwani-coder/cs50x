#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK 512

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("error reading file\n");
        return 1;
    }
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK];
    size_t bytes;
    bool firstJP = false;
    FILE *currentFile;
    char current_fileName[100];
    int fileNumber = 0;
    bool found_jpg = false;


    //open memory card
    while (true)
    {
        //  repeat until end of card:
        // read 512 bytes into a buffer
        bytes = fread(buffer, sizeof(BYTE), BLOCK, file);

        if (bytes == 0)
        {
            break; //end of file
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpg = true;
            // if start of new JPEG
            //if first JPEG
            if (!firstJP)
            {
                firstJP = true;
            }
            else
            {
                // close current file
                fclose(currentFile);

            }
            sprintf(current_fileName, "%03i.jpg", fileNumber);
            currentFile = fopen(current_fileName, "w");
            fwrite(buffer, sizeof(BYTE), bytes, currentFile);
            fileNumber ++;
        }
        else
        {
            //if already found JPEG
            if (found_jpg)
            {
                fwrite(buffer, sizeof(BYTE), bytes, currentFile);
            }

        }

    }
    fclose(file);
    fclose(currentFile);
    return 0;

}
