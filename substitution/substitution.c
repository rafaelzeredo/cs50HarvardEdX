#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string plaintext;
    int lenght = 0, i = 0, j = 0;
    // Check if there is only one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check if it is long enough
    string argument = argv[1];
    lenght = strlen(argument);
    if (lenght != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Check if it is alphabetical
    // Check if it is not duplicated
    int isAlphabetical = 0, counter = 0;
    // Iterating through argument
    for (i = 0; i < strlen(argument) ; i++)
    {
        // If character isn't a letter
        isAlphabetical = isalpha(argument[i]);
        if (isAlphabetical == 0)
        {
            printf("Key must contain 26 alphabetical characters.\n");
            return 1;
        }
        // Checking next element
        for (j = i + 1 ; j < strlen(argument) ; j++)
        {
            // Checking for repeated letters
            if (tolower(argument[j]) == tolower(argument[i]))
            {
                printf("Key must contain each letter exactly once.\n");
                return 1;
            }
        }
    }
    //printf("ok\n");
    // Get input from the user
    plaintext = get_string("plaintext: ");

    int index = 0, cypherLen = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cypherLen = strlen(plaintext);
    string cypher[cypherLen];
    // First set bChar to plaintext[0] and with cChar he finds letter H in alphabet
    int cChar = alphabet[0];
    int bChar = plaintext[0];
    // Output ciphertext
    printf("ciphertext: ");
    // When he finds letter H in alphabet, print the charactar that is in argument at same index location
    for (i = 0; i < strlen(plaintext); i++)
    {
        // iteration through plaintext
        while (bChar != '\0')
        {
            //printf("top of plaintext loop\n");
            // iteration through alphabet
            //printf("cchar was %c\n", cChar);
            j = 0;
            cChar = alphabet[0];
            //printf("now cchar is %c\n", cChar);
            while (cChar != '\0')
            {
                // If character is not alphabetical
                if (isalpha(bChar) == 0)
                {
                    // Print normal char from plaintext
                    printf("%c", plaintext[i]);
                    break;
                }
                // when the character from alphabet is the same as from argument
                if (tolower(bChar) == tolower(cChar))
                {
                    // if isupper != 0 it is uppercase
                    if (isupper(bChar) != 0)
                    {
                        // Print uppercase char
                        index = j;
                        printf("%c", toupper(argument[index]));
                        break;
                    }
                    else if (isupper(bChar) == 0)
                    {
                        // Print lowercase char
                        index = j;
                        printf("%c", tolower(argument[index]));
                        break;
                    }

                }
                cChar = alphabet[++j];
                //printf("alphabet iterated to %c\n", cChar);
            }
            bChar = plaintext[++i];
            //printf("plaintext iterated\n");
            //printf("b char is %c\n", bChar);
        }
    }
    printf("\n");
    return 0;
}