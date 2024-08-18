#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int pstr = 3;
int pdex = 3;
int pvit = 3;
int pper = 2;
int pint = 2;
int pmoney = 100;
int plife = 10;

int pskill = 3;
int psuccess = 0;
int eskill = 0;
int evit = 0;
int elife = 10;
int esuccess = 0;


//// END OF VARIABLES AND BEGGINING OF PROGRAM FUNCTION DECLARATIONS START:

////COMBAT FUNCTION COMBAT:
void combatfunction() ///Main body function head


{    //////COMBATFUCNTION BEGIN


//// COMBAT MENU OPTIONVARIABLE:
    int option = 0;

    srand (time(0)); /// Função que gera random seed atraves do valor do tempo
    int eskill = (rand() % 5) + 1; //GERERATES RANDOM NUM FROM 1-5
    int evit = (rand() % 5) + 1;
    printf("Enemy skill: %d\n", eskill);
    printf("Enemy vitality: %d\n", evit);





///////////MENULOOPBEGIN:

//////// do
///{
    //// COMBATMENU:
    if (option == 0)
    {
        printf("Options:\n");
        printf("1 - Keep fighting\n");
        printf("2 - Try to run away\n");
        option = input();
    }

    switch (option)
    {
        case 1 :
            {///OPTION 1 BEGIN COMBAT LOOP BEGIN

        ////PLAYERS DICE ROLL PROLLS:

    int result;
    int i;
    for (i = 0; i<pskill; i++)
    {
        result = rand() % 9;
        if (result >= 5) ; psuccess++;
    }


////ENEMY DICE ROLLS EROLLS:

    for (i = 0; i<eskill; i++)
    {
        result = rand() % 9;
        if (result >= 5) ; esuccess++;
    }


    printf("the psuc is %d, and the esuc is %d\n", psuccess, esuccess);

//// IF STATEMENTS WIN, LOSE OR TIE WINLOSEORTIE:



///// IF TIE:
    if (psuccess == esuccess)
    {
        ///DAMAGEISDEFAULT:
        plife = plife - 1 ; elife = elife - 1;
        printf("both player and enemy hit each other losing 1 life point\n");
        printf ("player life count: %d, enemy life count %d\n", plife, elife);
    }



//// IF PLAYER WINS WINS:
    if (psuccess > esuccess)
    {
        /// IF STATEMENT PREVENTING NEGATIVE DAMAGE DAMAGECALCULATED:
        int damage = (psuccess - esuccess);
        if (damage < (evit - 2)) ////if damage is negative it becomes 0
        {
            damage = 0;
        }
        if ((evit-2) < 0)  ///too weak, negative absorb
        {
            printf("Enemy is so fragile he takes bonus damage\n");
            damage = (damage - (evit - 2));
        }

        else  ///if not negative, apply absorb
        {
            printf("Enemy absorbs %d damage points\n", (evit-2));
            damage = (damage - (evit - 2));
        }

        elife = (elife - damage);
        printf("sucess diference: player %d, enemy %d\n", psuccess, esuccess);
        printf("Player hits enemy. Enemy takes %d points damage\n", damage);
        printf ("player life count: %d, enemy life count %d\n", plife, elife);

    }


    /////// IF PLAYER LOSES:
    if (esuccess > psuccess)
    {
        /// IF STATEMENT PREVENTING NEGATIVE DAMAGE DAMAGECALCULATED:
        int damage = (esuccess - psuccess);
        if (damage < (pvit - 2))////if damage is negative it becomes 0
        {
            damage = 0;
        }
        if ((pvit-2) < 0) ///too weak, negative absorb
        {
            printf("You are so fragile you take bonus damage\n");
            damage = (damage - (pvit - 2));
        }
        else   /// if not negative apply absorb
        {
            printf("Player absorbs %d damage\n",(pvit-2));
            damage = (damage - (pvit - 2));
        }

        plife = (plife - damage);
        printf("sucess diference: player %d, enemy %d\n", psuccess, esuccess);
        printf("Enemy hits player. Player takes %d points damage\n", damage);
        printf ("player life count: %d, enemy life count %d\n", plife, elife);
    }

        option = 0; //// SET LOOP BACK TO MENU

            } ///OPTION 1 END COMBAT LOOP END



        case 2 :
            {
                break;
            }
        default :
            {
                printf("Invalid option. please type number from 1-3");
                option = 0;
            }
    return 0;

    }


//// IF DEAD:

    if (plife <= 0)
    {
        printf ("Combat is over, you are dead");
        option = 2;
    }
    if (elife <= 0)
    {
        printf ("Combat is over, you have won");
        option = 2;
    }





/////   } while (option != 2);

} /////COMBAR FUCTION END







////// INICIO PROGRAMA:

int main (void)
{
 combatfunction();
}