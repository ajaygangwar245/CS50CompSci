#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for height of pyramid
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0);

    // loop to print pyramid
    for (int i = 0; i < height; i++)
    {
        // prints left half of pyramid
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // prints space in mid of pyramid
        printf("  ");

        // prints right half of pyramid
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }

        printf("\n");
    }
}
