#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    // using array index
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n\n", s[2]);

    // using pointer arithmetic
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
