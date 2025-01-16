#include <cs50.h>
#include <stdio.h>

// int size_of_array(int num[]);

int main(void)
{
    int numbers[] = {20, 35, 8, 11, 25, 10, 27, 17, 49, 9};
    int temp, size, swap = -1;

    // size = size_of_array(numbers);
    size = sizeof(numbers) / sizeof(numbers[0]);

    // bubble sort
    for (int i = 0; i < size; i++)
    {
        swap = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swap++;
            }
        }
        if (swap == 0)
        {
            printf("Array sorted\n");
            break;
        }
    }

    printf("array after sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");

}

// calculate size of array
// int size_of_array(int num[])
// {
//     int count = 0;

//     for (int i = 0; num[i] != '\0'; i++)
//     {
//         count++;
//     }
//     return count - 1;
// }
