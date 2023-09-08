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

// TODO: Choose number of buckets in hash table
const unsigned int N = 42;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *current = table[hash(word)];

    bool found = false;
    while (current != NULL)
    {
        if (strcasecmp(word, current->word) == 0)
        {
            return true;
        }

        if (current->next == NULL)
        {
            break;
        }
        current = current->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0; word[i] < '\0'; i++)
    {
        sum += toupper(word[i]) - 'A';
    }
    return sum % 43;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char buffer[LENGTH + 1];
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    while (fscanf(dict, "%s", buffer) == 1)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
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
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *current = NULL;
    node *next = NULL;

    for (int i = 0; i < word_count; i++)
    {
        current = table[i];
        while (current != NULL)
        {
            if (current->next == NULL)
            {
                free(current);
                break;
            }

            next = current->next;
            free(current);
            current = next;
        }
    }
    return true;
}
