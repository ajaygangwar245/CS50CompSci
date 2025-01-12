#include <cs50.h>
#include <stdio.h>

void compare(int a, int b);

int main(void)
{
    int x = get_int("Enter First Number: ");
    int y = get_int("Enter Second Number: ");

    compare(x, y);
}

void compare(int a, int b)
{
    if (a > b)
    {
        printf("%i is greater than %i\n", a, b);
    }
    else if (a < b)
    {
        printf("%i is less than %i\n", a, b);
    }
    else
    {
        printf("%i is equals to %i\n", a, b);
    }
}
