#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function takes a character as input
void chfunc (char cChar, char bChar, string argument, string alphabet, int index, int j)
{
// iteration thriugh alphabet
        cChar = alphabet[0];
        while (cChar != '\0')
        {
            // when the character from alphabet is the same as from argument
            if (tolower(bChar) == cChar)
            {

                index = j;
                printf("%c", argument[index]);
                break;

            }
            cChar = alphabet[++j];
            printf("alphabet iterated\n");

        }
}

int main(int argc, string argv[])
{
    bool plaintextIsValid = false;
    string plaintext;
    int lenght = 0;

    // Check if there is only one argument
    if (argc != 2)
    {
        printf("please type only one argument\n");
        return 1;
    }

    // Check if it is long enough
    string argument = argv[1];
    lenght = strlen(argument);
    if (lenght != 26)
    {
        printf("not the right number of characters\n");
        return 1;
    }
    // Check if it is alphabetical
    // Check if it is not double
    int isAlphabetical = 0, i = 0, counter = 0;
    char cChar = argument[0];
    char bChar = argument[0];
    while (bChar != '\0')
    {
        while (cChar != '\0')
        {
            isAlphabetical = isalpha(cChar);
            if (isAlphabetical == 0)
            {
                printf("needs to be alphabetical\n");
                return 1;
            }

            if (tolower(cChar) == tolower(bChar))
            {
                counter++;
            }
            cChar = argument[++i];
        }
        bChar = argument [++i];
    }
    if (counter > 1)
    {
        printf("can't repeat letters in key\n");
        return 1;
    }
    printf("ok\n");

    // get input from the user
    plaintext = get_string("plaintext: ");

    int index = 0, cypherLen = 0, j = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cypherLen = strlen(plaintext);
    string cypher[cypherLen];
    cChar = alphabet[0];
    bChar = plaintext[0];
    char aChar = argument[0];


    // example with qwerty key and Hello there as plaintext

    // First he sets bChar to plaintext and with cChar he finds letter H in alphabet
    // when he finds letter H in alphabet he grabs the index of H in index variable
    // then aChar is set to be of the same number index as the alphabet number index


    // iteration through plaintext
    while (bChar != '\0')
    {
        chfunc (cChar, bChar, argument, alphabet, index, j);
        bChar = plaintext[++i];
        printf("plaintext iterated\n");
        chfunc (cChar, bChar, argument, alphabet, index, j);

    }

}