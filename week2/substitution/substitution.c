#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_alpha(string str);
bool no_repeat(string str);
char encrypt(string key, char plaintext);

int main(int argc, string argv[])
{
    // checks for valid key as command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (only_alpha(argv[1]) != true)
    {
        printf("Key must contain alphabetic characters.\n");
        return 1;
    }
    else if (no_repeat(argv[1]) != true)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    // prompt user for text input
    string text = get_string("plaintext: ");
    int length = strlen(text);
    char ciphertext[length];

    // encrypting the text
    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = encrypt(argv[1], text[i]);
    }

    // prints ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
    return 0;
}

// to check key contains only alphabets
bool only_alpha(string str)
{
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

// to check contains no repeated characters
bool no_repeat(string str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}

// to encrypt the text using key
char encrypt(string key, char plaintext)
{
    int index;
    if (isupper(plaintext))
    {
        index = plaintext - 'A';
        return toupper(key[index]);
    }
    else if (islower(plaintext))
    {
        index = plaintext - 'a';
        return tolower(key[index]);
    }
    else
    {
        return plaintext;
    }
}
