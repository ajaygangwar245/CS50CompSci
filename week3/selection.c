#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 35, 8, 11, 25, 10, 27, 17, 49, 9};
    int temp, index, small, size;

    // size = size_of_array(numbers);
    size = sizeof(numbers) / sizeof(numbers[0]);

    // selection sort
    for (int i = 0; i < size; i++)
    {
        small = numbers[i];
        index = i;
        for (int j = i; j < size; j++)
        {
            if (numbers[j] < small)
            {
                small = numbers[j];
                index = j;
            }
        }
        temp = numbers[i];
        numbers[i] = small;
        numbers[index] = temp;
    }

    // sorted array
    printf("array after sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}
