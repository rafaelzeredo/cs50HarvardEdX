#include <cs50.h>
#include <stdio.h>
#include <math.h>

int totalChar = 0;

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int numberOfLetters, numberOfWords, numberOfSentences;
    int letters, index;
    float L, S, nol, now, nos;
    string text = get_string("TEXT: ");
    numberOfLetters = count_letters(text);
    numberOfWords = count_words(text);
    numberOfSentences = count_sentences(text);
    nol = numberOfLetters;
    now = numberOfWords;
    nos = numberOfSentences;
    L = (nol / now * 100);
    S = (nos / now * 100);
    ////    printf("%s\n", text);
    //printf("%i characters\n", totalChar);
    //printf("%i letters\n", numberOfLetters);
    //printf("%i words\n", (numberOfWords));
    //printf("%i sentences\n", (numberOfSentences));
    //printf("L: %f, S: %f\n", L, S);
    index = (0.0588 * L - 0.296 * S - 15.8);
    index = roundf(index);
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
        if (ch != ' ' && ch != '!' && ch != '?' && ch != '.' && ch != ',' && ch != ';' && ch != ':' && ch != '\t' && ch != '\n' && ch != 39 && ch != '"')
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
        if (ch == ' ')
        {
            words++;
        }
        ch = text[++i];
    }
    words = words + 1;
    return words;
}

int count_sentences(string text)
{
    int i = 0, sentencesPeriod = 0;
    bool textHasLetters = false, textHasPeriods = false;
    char ch = text[0];
    while (ch != '\0')
    {
        // If text has sentence breaker then
        if (ch == '!' || ch == '?' || ch == '.')
        {
            // Set boolean value to true and increment sentencesPeriod variable
            textHasPeriods = true;
            sentencesPeriod++;
        }
        // if there are no sentence breakers
        if (sentencesPeriod == 0)
        {
            // Then if there are letters, set hasLetters to true
            if (ch != '!' && ch != '?' && ch != '.')
            {
                textHasLetters = true;
            }
        }
        ch = text[++i];
    }
    // If text has letters but has no periods, set text to have one sentence
    if (textHasLetters == true && textHasPeriods == false)
    {
        sentencesPeriod = 1;
    }
    // If text has letters and periods count the sentences adding one to periods
    else if (textHasLetters == true && textHasPeriods == true)
    {
        if (text[i-1] != '!' && text[i - 1] != '?' && text[i - 1] != '.' && text[i - 1] != ';')
        {
            sentencesPeriod = sentencesPeriod + 1;
        }
    }
    // If text has no letters it has no sentences no matter the periods
    else if (textHasLetters == false)
    {
        sentencesPeriod = 0;
    }
    return sentencesPeriod;
}