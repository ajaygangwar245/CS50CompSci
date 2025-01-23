#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

bool binarySearchTree(node *ptr, int number);

int main(int argc, int argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./binarySearchTree 5 6 2 9 4 ....n (random numbers)\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);
    }
}

bool binarySearchTree(node *tree, int number)
{
    if (tree == NULL)
    {
        return FALSE;
    }
    else if (number < tree->number)
    {
        return binarySearchTree(tree->left, number);
    }
    else if (number > tree->number)
    {
        return binarySearchTree(tree->right, number);
    }
    else if (number == tree->number)
    {
        return TRUE;
    }
}
