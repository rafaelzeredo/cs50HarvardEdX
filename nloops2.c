#include <stdio.h>
#include <cs50.h>

int globalChoice = 0;
bool gameOn = true;
// Submenu prototype
int subMenuFunc (int menuChoice);



int main (void)
{
    int menuChoice = 0;
    while (gameOn == true)
    {
        printf("choices:\n");
        printf("1 - choice\n");
        printf("2 - exit\n");
        scanf("%d",&menuChoice);

        globalChoice = subMenuFunc(menuChoice);

    }
}


// Submenu definition
int subMenuFunc (int menuChoice)
{

    int smoption = 0;
    bool isInSubmenu = true;
    if (menuChoice == 1)
    {
        printf("choice 1\n");
    }
    else if (menuChoice == 2)
    {
        printf("Exiting\n");
        gameOn = false;
    }
    else
    {
        printf("invalid\n");
    }
    return 0;
}
