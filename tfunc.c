#include <cs50.h>
#include <stdio.h>

bool vtriangle (int a, int b, int c);

bool vtriangle (int a, int b, int c)
{

    if ((a+b>c) || (a+c> b) || (c+b>a))
    {
        return true;
    }
    else
    {
        return false;
    }
}