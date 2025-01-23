#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // creating a temporary array to add one more number to list
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        // if error then we have to first free memory allocated to list above then close the program
        free(list);
        return 1;
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%i\n", list[i]);
    // }

    // copy numbers from old list array to new temporary array
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;

    // free list array memory no need now
    free(list);

    // now point list to the temporary array
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // free memory
    free(list);
}
