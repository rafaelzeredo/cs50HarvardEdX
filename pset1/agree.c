#include <stdio.h>
#include <cs50.h>


int main (void)
{
    // prompt user to agree
    char c = get_char ("do you agree? ");

    // check whether user agreed
    if (c == 'y' || c == 'Y')
    {
        printf ("agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf ("not agreed.\n");
    }
}
