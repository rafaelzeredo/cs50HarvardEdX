#include <stdio.h>
#include <cs50.h>

//to usually start coding anything with c you would:
int main (void)
{
    int n = get_int ("n: ");


    // if n is even
    if (n % 2 == 0)
    {
    printf("even\n");
    }


    // if n is odd
    else
    {
    printf("odd\n");
    }


}