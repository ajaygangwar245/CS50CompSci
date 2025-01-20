#include <stdio.h>
// strings using cs50 library
/*
    #include <cs50.h>

    int main(void)
    {
        string s = "HI!";
        printf("%s\n", s);
    }
*/

// strings using pointers
int main(void)
{
    char *s = "HI!";
    printf("s = %s\n", s);
    printf("address = %p\n", s);

    printf("s[0] = %c\n", s[0]);
    printf("address = %p\n", &s[0]);

    printf("s[1] = %c\n", s[1]);
    printf("address = %p\n", &s[1]);

    printf("s[2] = %c\n", s[2]);
    printf("address = %p\n", &s[2]);
}
