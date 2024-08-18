#include <cs50.h>
#include <stdio.h>

int calculate(int startSize, int endSize);

int main(void)
{
    // TODO: Prompt for start size
    int startSize = 0;
    // Repeat the prompt until the number entered is at least 9
    while (startSize < 9)
    {
        startSize = get_int("Start size: ");
    }

    // TODO: Prompt for end size
    int endSize = 0;
    // Repeat prompt until end size is at least greater than or equal to start size
    while (endSize < startSize)
    {
        endSize = get_int("End size: ");
    }
    // TODO: Calculate number of years until we reach threshold
    int result = 0;
    // Conditional statement to see if the start size is the same as the end size
    if (startSize == endSize)
    {
        // If the start size is the same as the end size then no time is taken to get to goal so 0 years are needed
        result = 0;
    }
    else
    {
        // Function calculate returns the number of years needed to achieve the end size of the llama population
        result = calculate(startSize, endSize);
    }
    // TODO: Print number of years
    printf("Years: %d\n", result);
}

// Function that calculates the number of years needed to get to the target population
int calculate(int startSize, int endSize)
{
    // Variable called size is used to manipulate the actual size of the population through a given specific time
    // In the beginning the size is equal to start size
    int size = startSize;
    int years = 0;
    // The next two variables are used to calculate how many llamas are lost and how many gained
    int gain = 0;
    int lose = 0;

    // Repeat this process until the starting size is greater or equal to the end size
    do
    {
        gain = (size / 3);
        lose = (size / 4);
        // What interests me is only by how many llamas does the population increase, so I subtract "lose" from "gain"
        gain = (gain - lose);
        // Then I increment the size of the population by how many llamas are gained in that year
        size = (size + gain);
        // Then I increment the year variable
        years++;
    }
    while (size < endSize);
    return years;
}