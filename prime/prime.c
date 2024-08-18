#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // if number is 1 it is not prime
    if (number == 1)
    {
        return false;
    }
    // if number is 2 or 3 it is prime
    if (number == 2 || number == 3 || number == 5)
    {
        return true;
    }
    // if number is two it is prime
    if (number > 2)
    {
        if (number % 2 != 0)
        {
            if (number % 3 != 0)
            {
                if (number % 5 != 0)
                {
                    return true;
                }

            }
        }
    }
    return false;
}