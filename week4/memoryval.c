#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // old way to create array of 3 integer
    // int x[3];
    // new way using malloc
    int *x = malloc(3 * sizeof(int));

    // invalid write due to over usage of space as we created memory for only 3 ints and memory leakage when used valgrind ./memory
    // x[1] = 72;
    // x[2] = 73;
    // x[3] = 33;

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    free(x);
}
