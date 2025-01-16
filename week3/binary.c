#include <cs50.h>
#include <stdio.h>

void bubble_sort(int arr[], int size);
void binary(int arr[], int left, int right, int num);

int main(void)
{
    int numbers[] = {20, 35, 8, 11, 25, 10, 27, 17, 49, 9};
    int search = get_int("Enter number you want to search: ");
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // sort array
    bubble_sort(numbers, size);

    // sorted array
    printf("array after sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");

    // gets index if number found
    binary(numbers, 0, size - 1, search);

}

void bubble_sort(int arr[], int size)
{
    int swap, temp;
    for (int i = 0; i < size; i++)
    {
        swap = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap++;
            }
        }
        if (swap == 0)
        {
            // printf("Array sorted\n");
            break;
        }
    }
}

void binary(int arr[], int left, int right, int num)
{
    int mid;

    if (left <= right)
    {
        mid = left + (right - left) / 2;
        if (num == arr[mid])
        {
            printf("Number found at location: %i\n", mid);
        }
        else if (num > arr[mid])
        {
            binary(arr, mid + 1, right, num);
        }
        else if (num < arr[mid])
        {
            binary(arr, left, mid - 1, num);
        }
    }
    else
    {
        printf("Not found\n");
    }

}
