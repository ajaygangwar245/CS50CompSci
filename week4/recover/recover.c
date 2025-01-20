#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    // create buffer for JPEG block data i.e., of 512 bytes
    BYTE buffer[512];

    // pointer to create & write to new image file
    FILE *img = NULL;

    // new file to store image data
    char *filename = malloc(8);

    // counts the number of blocks read
    int counter = 0;

    // While there's still data left to read from the memory card
    while (fread(buffer, sizeof(BYTE), 512, card) == 512)
    {
        // if we found start of new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            // if this is start of first image file
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                counter++;
            }

            // if this is start of image but this is not first image
            // close previous file and open new and write
            else if (counter > 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                counter++;
            }
        }

        // if new JPEG file not found continue to write to old image file
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(BYTE), 512, img);
        }
    }

    // free memory allocated using malloc()
    free(filename);

    // closing opened files
    fclose(img);
    fclose(card);
}
