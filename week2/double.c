#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = get_int("size: ");
    int ar[size];
    ar[0] = 1;
    printf("%i\n", ar[0]);
    for (int i = 1; i < size; i++)
    {
        ar[i] = ar[i - 1] * 2;
        printf("%i\n", ar[i]);
    }
}
