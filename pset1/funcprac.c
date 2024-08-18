#include <cs50.h>
#include <stdio.h>
//declare function
int add2ints (int a, int b);

int main (void)
{
    //ask user for input
    printf("Give me the first number: ");
    int x = get_int();

    printf("Give me the second number: ");
    int y = get_int();

    int z = add2ints (x, y);
    //output do resultado
    printf("The sum of %i and %i is %i", x, y, z);
}

int add2ints (int a, int b)
{
    int soma = a + b;
    return soma;
}