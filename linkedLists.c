#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <cs50.h>

// names up to 256 bytes max
#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
}
person;


unsigned int hash (char *name)
{
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0 ; i < length ; i++)
    {
        hash_value += name[i];
        // increase randomness
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0 ; i < TABLE_SIZE ; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    for (int i = 0 ; i < TABLE_SIZE ; i++)
    {
        if (hash_table[i]==NULL) 
    }
}

int main (void)
{

    init_hash_table();

    printf("Natalie => %u\n", hash("Natalie"));
    printf("Jacob => %u\n", hash("Jacob"));
    printf("Sarah => %u\n", hash("Sarah"));
    printf("Jane => %u\n", hash("Jane"));
    printf("Ron => %u\n", hash("Ron"));
    printf("");
    return 0;
}
