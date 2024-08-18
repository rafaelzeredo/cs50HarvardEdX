#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int array[5];
    int i;
    int j;
    j=10;
    for (i = 0; i<5; i++)
    {
        array[i] = (j+i);
    }
printf("the second element is: %d", array[2]);
printf("the fourth element is: %d", array[4]);
}