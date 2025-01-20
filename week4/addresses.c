#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    printf("n = %i\n", n);
    printf("address of n = %p\n", &n);

    int *p = &n;
    printf("p = %p\n", p);
    printf("value of n using p = %i\n", *p);
}
