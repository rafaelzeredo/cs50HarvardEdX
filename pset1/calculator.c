#include <stdio.h>
#include <cs50.h>

int main (void)
{
    //prompt user for x
    long x = get_long("x: ");

    //prompt user for y
    long y = get_long("y: ");

    //Perform addition
       printf("%li\n", x + y);
}