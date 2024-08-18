#include <stdio.h>
#include <cs50.h>

//to usually start coding anything with c you would:
int main (void)
{
    const int MINE = 2;
    int points = get_int("how many points did you lose? ");

    if (points < MINE)
    {
        printf("you lost fewer points than me.\n");
    }
    else if (points > MINE)
    {
        printf ("you lost more points than me.\n");
    }
    else
    {
        printf ("you lost the same points as me.\n");
    }
}