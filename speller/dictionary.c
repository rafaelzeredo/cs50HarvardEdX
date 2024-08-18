// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

int wordCount = 0;

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
    // FILE *file = fopen(dictionary, "r");
    // if (file == NULL)
    // {
    //    printf("Memory error\n");
    //    return 1;
    // }
    // return false;
    //    char word[LENGHT+1];
    // Hashes word to a number

    int hashV = hash(word);
    node *cursor = table[hashV];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dicFile = fopen(dictionary, "r");
    if (dicFile == NULL)
    {
        printf("Failed to load...\n");
    }
    char buffer[LENGTH];

    while (fscanf(dicFile, "%s", buffer) != EOF)
    {
        node *nWord = malloc(sizeof(node));
        int hashV = hash(buffer);
        strcpy(nWord->word, buffer);
        nWord->next = table[hashV];
        table[hashV] = nWord;
        wordCount++;
    }
    fclose(dicFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
