#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string str);
char encrypt_text(int keynum, char plaintext);

int main(int argc, string argv[])
{
    // prompts user for command line arguments
    if (argc != 2 || only_digits(argv[1]) != true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // prompts user for input
    string text = get_string("plaintext:  ");
    int key = atoi(argv[1]);
    int len = strlen(text);
    char cipher_text[len];

    // for key greater than 26
    if (key > 26)
    {
        key = key % 26;
    }

    // converting plaintext to ciphertext
    for (int i = 0; i < len; i++)
    {
        cipher_text[i] = encrypt_text(key, text[i]);
    }

    // printing ciphertext
    printf("ciphertext: %s\n", cipher_text);
    return 0;
}

// checks argv[1] consists only digits
bool only_digits(string str)
{
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

// encrypts each character of plaintext using key
char encrypt_text(int keynum, char plaintext)
{
    if (isupper(plaintext))
    {
        plaintext = ((plaintext - 'A' + keynum) % 26) + 'A';
    }
    else if (islower(plaintext))
    {
        plaintext = ((plaintext - 'a' + keynum) % 26) + 'a';
    }
    return plaintext;
}
