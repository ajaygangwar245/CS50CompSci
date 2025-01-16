#include <cs50.h>
#include <stdio.h>

void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(void)
{
    int numbers[] = {5, 2, 1, 3, 6, 4};
    int size;

    size = sizeof(numbers) / sizeof(numbers[0]);

    mergesort(numbers, 0, size - 1);

    // sorted array
    printf("array after sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}

void mergesort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and right
        mid = left + (right - left) / 2;

        // sort the two halves of array
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        // merge the sorted halves of array
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    // temporary arrays
    int tempL[size1], tempR[size2];

    // copy data to left temporary array
    for (int i = 0; i < size1; i++)
    {
        tempL[i] = arr[left + i];
    }

    // copy data to right temporary array
    for (int j = 0; j < size2; j++)
    {
        tempR[j] = arr[mid + 1 + j];
    }

    // merge two temp arrays back int arr[]
    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2)
    {
        if (tempL[i] <= tempR[j])
        {
            arr[k] = tempL[i];
            i++;
        }
        else
        {
            arr[k] = tempR[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of tempL[] array
    while (i < size1)
    {
        arr[k] = tempL[i];
        i++;
        k++;
    }

    // copy remaining elements of tempR[] array
    while (j < size2)
    {
        arr[k] = tempR[j];
        j++;
        k++;
    }

}
