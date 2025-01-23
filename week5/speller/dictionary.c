// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// keeps the count of word loaded in hash table
int word_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // hash the word using hash function
    int index = hash(word);

    // create a traversal pointer which initially points to head of that linked list
    node *ptr = table[index];

    // traverse linked list until reached last node
    for (node *trav = ptr; trav != NULL; trav = trav->next)
    {
        // if word found in any node of linked list
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
    }

    // if traversed whole linked list and word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int num = (toupper(word[i]) - 'A') * i;
        sum += num;
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file to read words
    FILE *dict_file = fopen(dictionary, "r");

    // check if file opened correctly or not
    if (dict_file == NULL)
    {
        return false;
    }

    // to store words read from file
    char dword[LENGTH + 1];

    // store each word read from file until the end of file
    while (fscanf(dict_file, "%s", dword) != EOF)
    {
        // increase word count as word loaded in to hash table
        word_count++;

        // create new node to store word
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            return false;
        }

        // store word read from file in new node and next pointer will points to NULL
        strcpy(new_node->word, dword);
        new_node->next = NULL;

        // hash index in table's array using hash function to store node in hash table
        unsigned int index = hash(dword);

        // if it's the very first node
        if (table[index] == NULL)
        {
            table[index] = new_node;
        }

        // if there is already one or more nodes exist
        else
        {
            // firstly new node's next pointer will point to table's head at that index
            new_node->next = table[index];

            // then table's head will point to new node
            table[index] = new_node;
        }
    }

    // close dictionary file
    fclose(dict_file);

    // TODO
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // create a pointer assign NULL value
    node *ptr = NULL;

    // loop to access each bucket in the array of hash table
    for (int i = 0; i < N; i++)
    {
        ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }

        if (i == (N - 1))
        {
            return true;
        }
    }

    return false;
}
