#include <cs50.h>
#include <stdio.h>

int main (int argc, string argv[])
{
    //make sure user typed only name of program plus his name
    if (argc == 2)
    {
        //make sure the print is the name which is the second thing at the prompt, the first is program name
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        //if the user didn't type anything this is what program prints
        printf("hello, world\n");
    }
}