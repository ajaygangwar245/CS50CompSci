#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {5, 10, 20, 50, 100, 200, 500};
    int search = get_int("Enter number to search: ");

    int i = 0;
    while (numbers[i] != '\0')
    {
        if (search == numbers[i])
        {
            printf("Found at index = %i\n", i);
            return 0;
        }
        i++;
    }
    printf("Not found\n");
    return 1;
}
