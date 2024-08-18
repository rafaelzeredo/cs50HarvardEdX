#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n;

    // User input checks if the int is invalid and sets it to variable "n"
    do
    {
        n = get_int("Piramid Height (1-8): ");
    }
    while (n < 1 || n > 8);

    int s = (n - 1);

    //Rows:
    for (int i = 0; i < n; i++)
    {
        //Columns:
        // first the space before the hashes following a reversed pattern
        for (int x = 0 ; x < s; x++)
        {
            printf(" ");
        }
        /// here we decrease the spaces by one row by row to reverse the normal pyramid
        s--;
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        //// Print the spaces in the middle of the pyramid outside the other loops because for each row they are the same
        printf("  ");
        /// make the normal left-aligned pyramid inside the same row loop
        for (int y = 0; y < (i + 1); y++)
        {
            printf("#");
        }
        //// here every row ends
        printf("\n");
    }
}