#include <cs50.h>
#include <stdio.h>

int factorial(int num);

int main(void)
{
    int n = get_int("Enter number to calculate factorial: ");

    int fact = factorial(n);
    printf("factorial: %i\n", fact);
}

int factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
