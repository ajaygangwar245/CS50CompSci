#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string firstName = get_string("Enter First Name: ");
    string lastName = get_string("Enter Last Name: ");

    printf("Hello, %s %s\n", firstName, lastName);
}
