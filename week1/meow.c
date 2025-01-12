#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    int num = get_int("Enter number of times you want cat to meow: ");
    meow(num);
}

void meow(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
