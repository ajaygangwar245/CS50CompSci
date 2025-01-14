#include <cs50.h>
#include <stdio.h>
#include <string.h>

// to convert string to uppercase
// #include <ctype.h>

int main(void)
{
    string str = get_string("String: ");
    int length = strlen(str);

    // creating own method to convert each character of string to uppercase
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        printf("%c", str[i]);

        // using toupper() function
        // printf("%c", toupper(str[i]));
    }
    printf("\n");

}
