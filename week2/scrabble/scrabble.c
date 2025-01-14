#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_points(string word);

int main(void)
{
    // prompt user for words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // calculate points of players
    int points1 = calculate_points(word1);
    int points2 = calculate_points(word2);

    // Prints the winner
    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points1 < points2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// calculates the points using string entered by player
int calculate_points(string word)
{
    int pointsum = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        // checks input is alphabet
        if (isalpha(word[i]))
        {
            // checks if input is lowercase then make it uppercase
            if (islower(word[i]))
            {
                word[i] = toupper(word[i]);
            }
            pointsum += points[word[i] - 'A'];
        }
    }
    return pointsum;
}
