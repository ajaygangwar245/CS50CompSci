#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string str = get_string("Type word: ");
    int size = strlen(str);
    for (int i = 0; i < size - 1; i++)
    {
        if (str[i] > str[i + 1])
        {
            printf("Not in Alphabetical order\n");
            return 0;
        }
    }
    printf("In alphabetical order\n");
}
