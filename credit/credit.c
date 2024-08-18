#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16;
    long nd = 0;
    long c;
    int a, b;
    bool valid = false;
    // printf("Welcome to Rafael's Credit Card program\n");
    // Prompt user for credit card input
    c = get_long("Number:");
    // Check how many digits the card has
    d1 = c;
    do
    {
        d1 = (d1 / 10);
        nd++;
    }
    while (d1 != 0);
    // printf("Number of digits is: %li\n", nd);
    if (nd != 13 && nd != 15 && nd != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    // If the number has 13 digits:
    if (nd == 13)
    {
        d13 = c % 10;
        d12 = c % 100;
        d12 = d12 / 10;
        d11 = c % 1000;
        d11 = d11 / 100;
        d10 = c % 10000;
        d10 = d10 / 1000;
        d9 = c % 100000;
        d9 = d9 / 10000;
        d8 = c % 1000000;
        d8 = d8 / 100000;
        d7 = c % 10000000;
        d7 = d7 / 1000000;
        d6 = c % 100000000;
        d6 = d6 / 10000000;
        d5 = c % 1000000000;
        d5 = d5 / 100000000;
        d4 = c % 10000000000;
        d4 = d4 / 1000000000;
        d3 = c % 100000000000;
        d3 = d3 / 10000000000;
        d2 = c % 1000000000000;
        d2 = d2 / 100000000000;
        d1 = c / 1000000000000;
        // If the first digit is 4:
        if (d1 == 4)
        {
            // Multiply every other number by 2 adding their digits when they have 2 digit results
            d2 = d2 * 2;
            if (d2 > 9)
            {
                a = d2 / 10;
                b = d2 % 10;
                d2 = (a + b);
            }
            d4 = d4 * 2;
            if (d4 > 9)
            {
                a = d4 / 10;
                b = d4 % 10;
                d4 = (a + b);
            }
            d6 = d6 * 2;
            if (d6 > 9)
            {
                a = d6 / 10;
                b = d6 % 10;
                d6 = (a + b);
            }
            d8 = d8 * 2;
            if (d8 > 9)
            {
                a = d8 / 10;
                b = d8 % 10;
                d8 = (a + b);
            }
            d10 = d10 * 2;
            if (d10 > 9)
            {
                a = d10 / 10;
                b = d10 % 10;
                d10 = (a + b);
            }
            d12 = d12 * 2;
            if (d12 > 9)
            {
                a = d12 / 10;
                b = d12 % 10;
                d12 = (a + b);
            }
            // Sum all the digits of every other number
            a = (d2 + d4 + d6 + d8 + d10 + d12);
            b = (d1 + d3 + d5 + d7 + d9 + d11 + d13);
            a = (a + b);
            // Check last digit of total sum
            b = a % 10;
            if (b == 0)
            {
                printf("VISA\n");
                valid = true;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }
    else if (nd == 14)
    // 14 digits is invalid
    {
        printf("INVALID\n");
        return 0;
    }
    // If card has 15 digits:
    else if (nd == 15)
    {
        d15 = c % 10;
        d14 = c % 100;
        d14 = d14 / 10;
        d13 = c % 1000;
        d13 = d13 / 100;
        d12 = c % 10000;
        d12 = d12 / 1000;
        d11 = c % 100000;
        d11 = d11 / 10000;
        d10 = c % 1000000;
        d10 = d10 / 100000;
        d9 = c % 10000000;
        d9 = d9 / 1000000;
        d8 = c % 100000000;
        d8 = d8 / 10000000;
        d7 = c % 1000000000;
        d7 = d7 / 100000000;
        d6 = c % 10000000000;
        d6 = d6 / 1000000000;
        d5 = c % 100000000000;
        d5 = d5 / 10000000000;
        d4 = c % 1000000000000;
        d4 = d4 / 100000000000;
        d3 = c % 10000000000000;
        d3 = d3 / 1000000000000;
        d2 = c % 100000000000000;
        d2 = d2 / 10000000000000;
        d1 = c / 100000000000000;
        // If first digits start with 34 or 37
        if (d1 == 3 && (d2 == 4 || d2 == 7))
        {
            // Multiply every other number by 2 adding their digits when they have 2 digit results
            d2 = d2 * 2;
            if (d2 > 9)
            {
                a = d2 / 10;
                b = d2 % 10;
                d2 = (a + b);
            }
            d4 = d4 * 2;
            if (d4 > 9)
            {
                a = d4 / 10;
                b = d4 % 10;
                d4 = (a + b);
            }
            d6 = d6 * 2;
            if (d6 > 9)
            {
                a = d6 / 10;
                b = d6 % 10;
                d6 = (a + b);
            }
            d8 = d8 * 2;
            if (d8 > 9)
            {
                a = d8 / 10;
                b = d8 % 10;
                d8 = (a + b);
            }
            d10 = d10 * 2;
            if (d10 > 9)
            {
                a = d10 / 10;
                b = d10 % 10;
                d10 = (a + b);
            }
            d12 = d12 * 2;
            if (d12 > 9)
            {
                a = d12 / 10;
                b = d12 % 10;
                d12 = (a + b);
            }
            d14 = d14 * 2;
            if (d14 > 9)
            {
                a = d14 / 10;
                b = d14 % 10;
                d14 = (a + b);
            }
            // Sum all the digits of every other number
            a = (d2 + d4 + d6 + d8 + d10 + d12 + d14);
            b = (d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15);
            a = (a + b);
            // Check last digit of total sum
            b = a % 10;
            if (b == 0)
            {
                printf("AMEX\n");
                valid = true;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    // If card has 16 digits:
    else if (nd == 16)
    {
        d16 = c % 10;
        d15 = c % 100;
        d15 = d15 / 10;
        d14 = c % 1000;
        d14 = d14 / 100;
        d13 = c % 10000;
        d13 = d13 / 1000;
        d12 = c % 100000;
        d12 = d12 / 10000;
        d11 = c % 1000000;
        d11 = d11 / 100000;
        d10 = c % 10000000;
        d10 = d10 / 1000000;
        d9 = c % 100000000;
        d9 = d9 / 10000000;
        d8 = c % 1000000000;
        d8 = d8 / 100000000;
        d7 = c % 10000000000;
        d7 = d7 / 1000000000;
        d6 = c % 100000000000;
        d6 = d6 / 10000000000;
        d5 = c % 1000000000000;
        d5 = d5 / 100000000000;
        d4 = c % 10000000000000;
        d4 = d4 / 1000000000000;
        d3 = c % 100000000000000;
        d3 = d3 / 10000000000000;
        d2 = c % 1000000000000000;
        d2 = d2 / 100000000000000;
        d1 = c / 1000000000000000;
        // If card starts with 51, 52, 53, 54 or 55:
        if (d1 == 5 && (d2 == 1 || d2 == 2 || d2 == 3 || d2 == 4 || d2 == 5))
        {
            // Multiply every other number by 2 adding their digits when they have 2 digit results
            d1 = d1 * 2;
            if (d1 > 9)
            {
                a = d1 / 10;
                b = d1 % 10;
                d1 = (a + b);
            }
            d3 = d3 * 2;
            if (d3 > 9)
            {
                a = d3 / 10;
                b = d3 % 10;
                d3 = (a + b);
            }
            d5 = d5 * 2;
            if (d5 > 9)
            {
                a = d5 / 10;
                b = d5 % 10;
                d5 = (a + b);
            }
            d7 = d7 * 2;
            if (d7 > 9)
            {
                a = d7 / 10;
                b = d7 % 10;
                d7 = (a + b);
            }
            d9 = d9 * 2;
            if (d9 > 9)
            {
                a = d9 / 10;
                b = d9 % 10;
                d9 = (a + b);
            }
            d11 = d11 * 2;
            if (d11 > 9)
            {
                a = d11 / 10;
                b = d11 % 10;
                d11 = (a + b);
            }
            d13 = d13 * 2;
            if (d13 > 9)
            {
                a = d13 / 10;
                b = d13 % 10;
                d13 = (a + b);
            }
            d15 = d15 * 2;
            if (d15 > 9)
            {
                a = d15 / 10;
                b = d15 % 10;
                d15 = (a + b);
            }
            // Sum all the digits of every other number
            a = (d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16);
            b = (d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15);
            a = (a + b);
            // Check last digit of total sum
            b = a % 10;
            if (b == 0)
            {
                printf("MASTERCARD\n");
                valid = true;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else if (d1 == 4)
        {
            // Multiply every other number by 2 adding their digits when they have 2 digit results
            d1 = d1 * 2;
            if (d1 > 9)
            {
                a = d1 / 10;
                b = d1 % 10;
                d1 = (a + b);
            }
            d3 = d3 * 2;
            if (d3 > 9)
            {
                a = d3 / 10;
                b = d3 % 10;
                d3 = (a + b);
            }
            d5 = d5 * 2;
            if (d5 > 9)
            {
                a = d5 / 10;
                b = d5 % 10;
                d5 = (a + b);
            }
            d7 = d7 * 2;
            if (d7 > 9)
            {
                a = d7 / 10;
                b = d7 % 10;
                d7 = (a + b);
            }
            d9 = d9 * 2;
            if (d9 > 9)
            {
                a = d9 / 10;
                b = d9 % 10;
                d9 = (a + b);
            }
            d11 = d11 * 2;
            if (d11 > 9)
            {
                a = d11 / 10;
                b = d11 % 10;
                d11 = (a + b);
            }
            d13 = d13 * 2;
            if (d13 > 9)
            {
                a = d13 / 10;
                b = d13 % 10;
                d13 = (a + b);
            }
            d15 = d15 * 2;
            if (d15 > 9)
            {
                a = d15 / 10;
                b = d15 % 10;
                d15 = (a + b);
            }
            // Sum all the digits of every other number
            a = (d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16);
            b = (d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15);
            a = (a + b);
            // Check last digit of total sum
            b = a % 10;
            if (b == 0)
            {
                printf("VISA\n");
                valid = true;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        nd = 0;
        return 0;
    }
}