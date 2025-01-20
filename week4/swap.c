#include <cs50.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("Before: x is %i, y is %i\n", x, y);
    // this below function only pass by value (only copy of x & y)
    // swap(x, y);

    // this below function pass by refrence (passes pointer to original value)
    swap(&x, &y);
    printf("After: x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
