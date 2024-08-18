#include <cs50.h>
#include <stdio.h>
#include <math.h>

int totalChar = 0;
// Functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
//Main program
int main(void)
{
    int numberOfLetters, numberOfWords, numberOfSentences;
    int letters, index;
    float L, S, nol, now, nos, indexFloat;
    // Prompt user for text
    string text = get_string("TEXT: ");
    // Run functions to count letters and words and sentences
    numberOfLetters = count_letters(text);
    numberOfWords = count_words(text);
    numberOfSentences = count_sentences(text);
    // Turn integers into floats to make Coleman-Liau index calculation
    nol = numberOfLetters;
    now = numberOfWords;
    nos = numberOfSentences;
    // Calculate Coleman-Liau index
    L = (nol / now * 100);
    S = (nos / now * 100);
    // Use a float index to calculate with precision
    indexFloat = (0.0588 * L - 0.296 * S - 15.8);
    // Round the float into an integer index variable
    index = roundf(indexFloat);
    // Check if index is over or under set limits
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text)
{
    int numberOfLetters = 0;
    int i = 0;
    char ch = text[0];
    while (ch != '\0')
    {
        // Iterate through all chars in string incrementing variable where there is a letter
        if (ch != ' ' && ch != '!' && ch != '?' && ch != '.' && ch != ',' && ch != ';' && ch != ':' && ch != '\t' && ch != '\n' && ch != 39
            && ch != '"')
        {
            numberOfLetters++;
        }
        ch = text[++i];
        totalChar++;
    }

    return numberOfLetters;
}

int count_words(string text)
{
    int i = 0, Spaces = 0, words = 0;
    char ch = text[0];
    while (ch != '\0')
    {
        // increment words variable wherever there is a space
        if (ch == ' ')
        {
            words++;
        }
        ch = text[++i];
    }
    // add one to words so it is not just counting the spaces in between
    words = words + 1;
    return words;
}

int count_sentences(string text)
{
    int i = 0, sentencesPeriod = 0;
    char ch = text[0];
    while (ch != '\0')
    {
        // If text has sentence breaker then
        if (ch == '!' || ch == '?' || ch == '.')
        {
            // Increment sentencesPeriod variable
            sentencesPeriod++;
        }
        ch = text[++i];
    }
    return sentencesPeriod;
}