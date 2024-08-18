#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    const int maxString = 100;

    //typedef struct person{
      //      char name[maxString];
        //    char number[maxString];
  //  }person;

    char s[maxString];
    printf("Practice Time\n");
    printf("Escreva um nome qualquer: \n");
    scanf("%s", s);
    system("clear");
    printf("tu escreveu: %s\n", s);
    printf("");
    printf("aperte qualquer tecla pra continuar nesse carai...");
    getchar();
    getchar();


/// THIS IS THE MAGIC
    FILE *file = fopen("progData.csv", "a"); // a for append mode  FOPEN IS AS CREATES A FILE AND RETURNS THE ADRESS OF IT IN SYSTEM
    if (file == NULL)
    {
        return 1;
    }
    /// MORE MAGIC UP AHEAD

    system("clear");
    char name[maxString];
    char number[maxString];
    printf("nome do infiliz: \n");
    scanf("%s", name);
    printf("numero: \n");
    scanf("%s", number);

    fprintf(file, "%s, %s\n", name, number);    ////THIS IS THE MAGIC
    fclose(file);
    printf("We wrote it in a file called progData.csv\n");

}

