#include <stdio.h>

int main(void)
{
    // this type of declaration of string without initialization will gives error
    // char *s;

    // this will only take string of 3 characters, so it's difficult to take user input of string using scanf()
    // as we can't predict how much length of character a user will enter in string
    char s[4];

    printf("s: ");
    scanf("%s", s);
    printf("s : %s\n", s);
}
