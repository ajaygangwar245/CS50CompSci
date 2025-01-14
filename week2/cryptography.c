#include <cs50.h>
#include <stdio.h>
#include <string.h>

void encrypt(int length, string strdata);
void decrypt(int length, string strdata);

int main(void)
{
    char ch;
    do
    {
        string str = get_string("Enter string: ");
        int len = strlen(str);
        int choice = get_int("Enter your choice \n1.Encrypt 2.Decrypt: ");
        switch(choice)
        {
            case 1:
                encrypt(len, str);
                break;
            case 2:
                decrypt(len, str);
                break;
            default:
                printf("Wrong Input");
                break;
        }
        ch = get_char("Type 'y' or 'Y' to continue else press any other key to exit: ");
    }
    while (ch == 'y' || ch == 'Y');
}

void encrypt(int length, string strdata)
{
    for (int i = 0; i < length; i++)
    {
        strdata[i] = strdata[i] + 1;
    }
    printf("Encrypted data: %s\n", strdata);
}

void decrypt(int length, string strdata)
{
    for (int i = 0; i < length; i++)
    {
        strdata[i] = strdata[i] - 1;
    }
    printf("Decrypted data: %s\n", strdata);
}
