#include <stdio.h>

int main (void)
{
    char name [100];
    printf("whats your name?\n");
    fgets(name, sizeof(name), stdin);
    printf("\nyou typed: %s\n", name);

    return 0;
}
