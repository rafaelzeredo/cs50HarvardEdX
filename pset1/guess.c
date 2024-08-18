#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int number = 5;



    int guess = get_int("Qual seu chute :");

    if (guess != number)
    {
        printf("você chutou errado!\n");
    }
    else
    {
        printf("você acertou!\n");
    }

}