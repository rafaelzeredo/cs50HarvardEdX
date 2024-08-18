#include <cs50.h> //get string works with this
#include <stdio.h> //printf works with this



int main(void)
{
    string name = get_string("what is your name? \n");
    printf("hello, %s\n", name);
}