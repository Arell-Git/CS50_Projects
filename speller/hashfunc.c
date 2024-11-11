// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Dictionary Size
int dictionary_size = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Implimit a hash function

}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        //allocate memory for new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //copy current word onto node
        strcpy(n->word, word);
        n->next = NULL;

        //Get bucket (A - Z) via hash function
        int index = hash(word);
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            //Sets the next pointer to head
            n->next = table[index];
            //Makes the node the new head
            table[index] = n;
        }
    dictionary_size++;

    }
    fclose(file);
    return true;
}