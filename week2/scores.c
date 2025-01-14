#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = get_int("How many scores you want to average? ");
    int scores[size];
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        scores[i] = get_int("Score%i: ", (i + 1));
        sum += scores[i];
    }
    printf("Average : %.2f\n", sum / (float) size);
}
