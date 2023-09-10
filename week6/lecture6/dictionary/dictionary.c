// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int word_count = 0;

// Choose number of buckets in hash table
const unsigned int N = 101;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *current = table[hash(word)];

    while (current != NULL)
    {
        if (strcasecmp(word, current->word) == 0)
        {
            return true;
        }

        current = current->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Improve hash function
    int sum = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        sum += (i * (toupper(word[i]) - 'A'));
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char buffer[LENGTH + 1];

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open dictionary file.\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    while (fscanf(dict, "%s", buffer) == 1)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("Could not allocate memory for a new node.\n");
            return false;
        }
        new->next = NULL;

        strcpy(new->word, buffer);

        if (table[hash(new->word)] == NULL)
        {
            table[hash(new->word)] = new;
        }
        else
        {
            new->next = table[hash(new->word)];
            table[hash(new->word)] = new;
        }
        word_count++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *current = NULL;
    node *next = NULL;

    for (int i = 0; i < N; i++)
    {
        current = table[i];
        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }
    }
    return true;
}
