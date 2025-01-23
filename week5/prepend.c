#include <stdio.h>
#include <stdlib.h>

// define a node consist of a number and a next pointer of type node which points to next node
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./prepend 1 2 3 ..... n (random numbers)\n");
        return 1;
    }

    // create a list pointer
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        // allocate number from command line to a varable num
        int num = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // free memory
            return 1;
        }

        // allocate number in new node with the user typed input num
        n->number = num;

        // allocate next pointer of new node with pointer to the list
        // this will pre-append new node to the list
        n->next = list;

        // we should not allocate list pointer with new node if the next pointer in node is NULL
        // this will orphan the old nodes to which list was pointing previously
        // n->next = NULL;
        list = n;
    }

    // prints whole list
    node *ptr = list;

    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);

        // moves pointer ptr to next node after printing previous number
        ptr = ptr->next;
    }

    // Free memory
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
