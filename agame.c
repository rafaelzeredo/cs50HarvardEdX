#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>



// Functions
void draw (int life, int gold, int armor, string weapon, int weaponDamage)
{
    system("clear");
    printf("life: %i    gold: %i    armor: %i    weapon: %s    weapon damage: %i\n\n", life, gold, armor, weapon, weaponDamage);
}


int main (void)
{
    int choice = 0;
    int level = 0;
    int life = 10, gold = 100, armor = 0, weaponDamage = 2;
    string weapon = "short sword";
    bool gameOn = true;
    // Continues looping through the game checking for the levels
    while (gameOn == true)
    {
        if (level == 0)
        {
            draw(life, gold, armor, weapon, weaponDamage);
            printf("This is the beggining of the game. You are inside the City\n");
            printf("1 - go to the blacksmith\n");
            printf("2 - go to the inn\n");
            printf("3 - go outside the city\n");
            printf("4 - exit\n");
            choice = get_int("type the menu choice number. your choice: ");
        }
        switch (choice)
        {
            case 1 :
            {
                level = 1;
                break;
            }
            case 2 :
            {
                level = 2;
                break;
            }
            case 3 :
            {
                level = 3;
                break;
            }
            case 4 :
            {
                level = 4;
                break;
            }
            default :
            {
                printf("wrong choice. type number from 1 to 4\n");
            }
        }




        if (level == 1)
        {
            draw(life, gold, armor, weapon, weaponDamage);
            printf("blacksmith\n");
            printf("1 - buy weapon\n");
            printf("2 - buy armor\n");
            printf("3 - walk out\n");
            choice = get_int("your choice:\n");
            switch (choice)
            {
                case 3 :
                {
                    printf("walking out\n");
                    level = 0;
                    break;
                }
                default :
                {
                    printf("wrong choice\n");
                }
            }
        }
        if (level == 2)
        {
            draw (life, gold, armor, weapon, weaponDamage);
            printf("inn\n");
            printf("here you can rest for some time and for a price\n");
            printf("1 - rest for a day (regain 3 life points - 20 gold)\n");
            printf("2 - leave the inn\n");
            choice = get_int("Your choice: \n");
            switch (choice)
            {
                case 1 :
                {
                    if (gold > 19)
                    {
                        gold = gold - 20;
                        life = life + 3;
                        printf("you're healed\n");
                    }
                    else printf ("you don't have any money\n");
                }
                case 2 :
                {
                    printf("you walk out\n");
                }
                default : printf("invalid option\n");
            }

            level = 0;
        }
        if (level == 3)
        {
            draw (life, gold, armor, weapon, weaponDamage);
            printf("outside\n");
            gameOn = false;
        }
        if (level == 4)
        {
            printf("exitting\n");
            gameOn = false;
        }
    }
}


