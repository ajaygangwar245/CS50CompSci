#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./sorted 1 3 9 5 ....n (random numbers)\n");
        return 1;
    }

    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);

        // create new node pointer
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // free memory
            return 1;
        }

        n->number = num;
        n->next = NULL;

        // if list is empty
        if (list == NULL)
        {
            list = n;
        }

        // if there is numbers in list
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // if end of the list
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }

                // if middle of list
                // new node number is less than number in the next node of the current pointer ptr
                // so new node will come between current pointer (ptr) and next pointer (ptr->next) to current pointer
                else if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // prints numbers
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
