// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

typedef char *string; // Declaring type string.

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//vars
unsigned int words, hash_result;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_result = hash(word);
    node *c = table[hash_result];

    while (c != 0)
    {
        if (strcasecmp(word, c -> word) == 0)
        {
            return true;
        }
        c = c -> next;

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    /* Would have made the parameters: const string word.
    But dictonary.h has the prototype as const char *word.
    could change it but I don't really want to change distribution code.
    Algorithm credits: http://www.cse.yorku.ca/~oz/hash.html */
    unsigned long hash = 5381;

    int c = *word;

    c = tolower(c);

    while (*word != 0)
    {

        hash = ((hash << 5) + hash) + c;

        c = *word++;

        c = tolower(c);

    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        return false;
    }
    char w[LENGTH + 1]; // + 1 for /0

    while (fscanf(f, "%s", w) != EOF) // https://manual.cs50.io/3/fscanf EOF stands for END-OF-FILE.
    {
        node *n = malloc(sizeof(node));
        // Checking if malloc failed...
        if (n == NULL)
        {
            return false;
        }
        strcpy(n -> word, w);

        hash_result = hash(w);
        n -> next = table[hash_result];
        table[hash_result] = n;
        words++;
    }
    fclose(f); // https://manual.cs50.io/3/fclose


    return true;
}



// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (words > 0) // Would have written it like this: if (words > 0) return words; But style50 doesn't like it.
    {
        return words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *c = table[i];

        while (c != NULL)
        {
            node *temp = c;

            c = c -> next;

            free(temp);

        }

        if (c == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
