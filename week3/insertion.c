#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 35, 8, 11, 25, 10, 27, 17, 49, 9};
    int size, insert, index;

    size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 1; i < size; i++)
    {
        insert = numbers[i];
        index = i - 1;

        // move elements from 0 to i-1 that are greater than insert number
        while (index >= 0 && numbers[index] > insert)
        {
            numbers[index + 1] = numbers[index];
            index--;
        }
        numbers[index + 1] = insert;
    }

    // other way of doing
    // for (int i = 1; i < size; i++)
    // {
    //     insert = numbers[i];
    //     if (numbers[i - 1] > numbers[i])
    //     {
    //         for (int j = i - 1; j >= 0; j--)
    //         {
    //             if (numbers[j] > insert)
    //             {
    //                 numbers[j + 1] = numbers[j];
    //                 index = j;
    //             }
    //         }
    //         numbers[index] = insert;
    //     }
    // }

    // sorted array
    printf("array after sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}
