#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

// used uint8_t instead of int because it is single byte long whereas int is 4 byte long
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./pdf filename\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    BYTE buffer[4];

    // depicts first 4 bytes of a pdf file
    int pdf[4] = {37, 80, 68, 70};
    int count = 0;

    fread(&buffer, 1, 4, file);

    // prints value in buffer
    for (int i = 0; i < 4; i++)
    {
        printf("%i is %i\n", i, buffer[i]);
    }

    // checks if file is pdf or not
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != pdf[i])
        {
            printf("Not PDF\n");
            break;
        }
        else
        {
            count++;
        }
    }
    if (count == 4)
    {
        printf("Yes PDF\n");
    }

    fclose(file);
    return 0;
}
