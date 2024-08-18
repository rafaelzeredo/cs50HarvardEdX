#include <cs50.h>
#include <stdio.h>

int totalChar = 0, spaces = 0;

int count_letters(string text);
int count_words(string text);

int main(void)
{
    int numberOfLetters, numberOfWords;
    int letters;
    string text = get_string("TEXT: ");
    numberOfLetters = count_letters(text);
    numberOfWords = count_words(text);
////    printf("%s\n", text);
    printf("%i letters\n", numberOfLetters);
    printf("%i characters\n", totalChar);
    printf("%i spaces characters\n", spaces);
    printf("%i words\n", (numberOfWords));
}

int count_letters(string text)
{
    int numberOfLetters = 0;
    int i = 0;
    char ch = text[0];
    while (ch != '\0')
    {
        if (ch != ' ' && ch != '!' && ch != '?' && ch != '.' && ch != ',' && ch != ';' && ch != '\t' && ch != '\n')
        {
            numberOfLetters++;
        }
        else
        {
            spaces++;
        }
        ch = text[++i];
        totalChar++;
    }

    return numberOfLetters;
}

int count_words(string text)
{
    int i = 0, Spaces = 0, words = 0, letters = 0;
    char ch = text[0];
    bool textStart = false;
    bool isSpace = false;
    while (ch != '\0')
    {


        // If there is a space element in array
        if (ch == ' ' && ch == '!' && ch == '?' && ch == '.' && ch == ',' && ch == ';' && ch == '\t' && ch == '\n')
        {
            // Then if next element in array is not a space count it as one space
            if (text[i] != 0)
            {
                if (text[i - 1] != text[i])
                {
                    Spaces++;
                }
            }
            else
            {
                Spaces++;
            }
        }
        else
        {
            textStart = true;
        }
        if (textStart == true)
        {
            letters++;
        }
        words = spaces + 1;
        ch = text[++i];
    }
    printf("%i words variable\n", words);
    printf("%i white spaces\n", Spaces);
    return words;
}