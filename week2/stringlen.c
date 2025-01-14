#include <cs50.h>
#include <stdio.h>

// header file for string operations i.e., to use strlen()
// #include <string.h>

int stringlen(string strdata);

int main(void)
{
    string str = get_string("Enter string: ");
    int strlength = stringlen(str);

    // strlen() to calcualte length of string
    // int strlength = strlen(str);

    printf("Length: %i\n", strlength);
}

int stringlen(string strdata)
{
    int n = 0;
    while (strdata[n] != '\0')
    {
        n++;
    }
    return n;
}
