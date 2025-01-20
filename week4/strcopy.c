#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s : ");
    // if user typed so large string that is not able to be stored, system will store NULL in s.
    if (s == NULL)
    {
        return 1;
    }

    // this will do not copy string s into t instead it will copy address of string s to t so t will also point to same string as s.
    // char *t = s;

    char *t = malloc(strlen(s) + 1);
    // if system runs out of memory the malloc will unable to allocate memory to t so it'll return NULL.
    if (t == NULL)
    {
        return 1;
    }

    // this wil copy each element of string s to space allocated to t.
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // substitute for above long method to copy strings
    // strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s : %s\n", s);
    printf("t : %s\n", t);

    // free the memory given using malloc()
    free(t);
    return 0;
}
