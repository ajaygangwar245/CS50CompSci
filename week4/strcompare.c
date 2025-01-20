#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    // int n1 = get_int("Integer 1: ");
    // int n2 = get_int("Integer 2: ");
    char *s1 = get_string("String 1: ");
    char *s2 = get_string("String 2: ");

    // if we type same value for both s1 and s2 still output below will be diff because value of both s1 & s2 will be stored at diff address
    // printf("s1 = %p\n", s1);
    // printf("s2 = %p\n", s2);

    // if(n1 == n2)
    // strings cannot be compared directly with equal to operator as it compares stored address unlike integers which compares value
    // if(s1 == s2)
    if(strcmp(s1, s2) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
