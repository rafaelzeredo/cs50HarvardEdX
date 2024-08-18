#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n = get_int ("how many payments ");

    int numbers[n];
    int total = 0;

    for (int i=0; i<n; i++)
    {
        numbers[i] = get_int("payment ammount: ");
        total = (total + numbers[i]);
    }

    printf("total money %i\n", total);
}