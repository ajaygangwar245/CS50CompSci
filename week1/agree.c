#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char answer = get_char("Do you agree? (Y/N): ");

    if (answer == 'Y' || answer == 'y')
    {
        printf("User Agreed!\n");
    }
    else if (answer == 'N' || answer == 'n')
    {
        printf("User Not Agreed!\n");
    }
    else
    {
        printf("Wrong Input\n");
    }
}
