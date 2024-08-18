#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
string alphabet = "abcdefghijklmnopqrstuvwxyz";

int compute_score(string word);

int main(void)
{
    string word;
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    // TODO: Compute and return score for string
    // Iterate through all letters of word
    for (int i = 0; i < strlen(word); i++)
    {
        //printf("Top of the word loop letter %c\n", word[i]);
        // Iterate through all letters of the alphabet array (string)
        for (int j = 0; j < 27; j++)
        {
            //printf("Top of the alphabet loop letter %c\n", alphabet[j]);
            // If the word is equivalent to alphabet index number
            if (tolower(word[i]) == alphabet[j])
            {
                // Add score element from POINTS array located same index number
                score = score + POINTS[j];
                //printf("points = %i\n", score);
                break;
            }
        }
    }
    return score;
}
