#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[])
{
    printf("it compiles\n");
    printf("argc %i", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("%s", *argv[i]);
    }
}
