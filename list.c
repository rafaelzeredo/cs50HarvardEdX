#include <stdio.h>
#include <stdlib.h>

// create the node structure datatype with two fields
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (int argc, char *argv[])
{
    // create a pointer of node type and set to NULL
    node *list = NULL;

    // Iterate through command line arguments
    // i starts at one because argc 0 is program name
    for (int i = 1; i < argc; i++)
    {
        // create int var and convert argv into int
        int number = atoi(argv[i]);

        // n pointer gets the space of a node allocated
        node *n = malloc(sizeof(node));
        // if there is not enough space quit with error
        if (n == NULL)
        {
            return 1;
        }
        // go to node where n pointer points to and
        // set the number field to equal number var
        n->number = number;
        // go to node where n pointer points to and
        // set the next field to NULL
        n->next = NULL;
        // go to node where n pointer points to and
        // set the next field to point at the same node
        // list is pointing to
        n->next = list;
        // make list pointer point to where n is pointing
        list = n;
    }

    // make a temporary pointer variable to iterate
    // and print the numbers in the nodes
    // ptr pointer of type node points to where list is
    // pointing to
    node *ptr = list;
    // while not at the end of the list
    while (ptr != NULL)
    {
        // print number ptr points to
        printf("%i\n", ptr->number);
        // make ptr point to the next node by referencing
        // the next field in the node ptr points to
        // "iterate through numbers in nodes"
        ptr = ptr->next;
    }

    // make ptr point to node that list is pointing to
    ptr = list;
    while (ptr != NULL)
    {
        // pointer called next of type node, points to
        // not the same node ptr is pointig to, but to
        // the next node (grabs the next field from
        // the node ptr is pointing to)
        node *next = ptr->next;
        // then free allocated memory in that node
        free(ptr);
        // then makes the field next point to where ptr
        // is pointing to
        ptr = next;
    }
}