#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int skill;
}
pc;

int main (void)
{
    pc human[2];
    human[0].name = "smith";
    human[0].skill = 5;
    printf("name: %s   skill: %i\n", human[0].name, human[0].skill);
}