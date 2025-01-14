#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string str);
int count_words(string str);
int count_sentences(string str);

int main(void)
{
    // prompt user for text input
    string text = get_string("Text: ");

    // count total number of letters and words
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // average number of letters per 100 words
    float L = ((float) letters / (float) words) * 100;

    // avereage number of sentences per 100 words
    float S = ((float) sentences / (float) words) * 100;

    // calculate Coleman-liau Index
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    // print grade level using Coleman-Liau Index
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

// counts total letters
int count_letters(string str)
{
    int letter_count = 0;
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (isalpha(str[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

// counts total words
int count_words(string str)
{
    int word_count = 0;
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (str[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count + 1;
}

// counts total sentences
int count_sentences(string str)
{
    int sentence_count = 0;
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (str[i] == '.' || str[i] == '?' || str[i] == '!')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
