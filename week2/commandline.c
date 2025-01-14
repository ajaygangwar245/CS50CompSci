#include <cs50.h>
#include <stdio.h>

// library added to use atoi() function
#include <stdlib.h>

void mario(int size);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./commandline number\n");
        return 1;
    }
    else
    {
        // atoi() converts string to integer
        mario(atoi(argv[1]));
        return 0;
    }
}

void mario(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
