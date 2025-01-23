#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./append 1 2 3 ....n\n");
        return 1;
    }

    // create a node pointer list
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);

        // new node created
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            // free memory
            return 1;
        }

        n->number = num;
        n->next = NULL;

        // if the list is empty
        if (list == NULL)
        {
            list = n;
        }

        // if list is not empty and has numbers and nodes
        else
        {
            // iterate over list nodes using temporary pointer ptr
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // if at the end of list
                if (ptr->next == NULL)
                {
                    // allocate next pointer of last node with pointer to new node
                    ptr->next = n;
                    break;
                }
            }
        }

    }

    // print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
