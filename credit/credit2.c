#include <cs50.h>
#include <stdio.h>



int main(void)
{
    long d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16;
    long nd = 0;
    long c;
    int a, b;
    bool valid = false;
/// / printf("Welcome to Rafael's Credit Card program\n");






////// Beginning of the loop
do
{


//// check that the number isn't negative
        do
    {
         c = get_long("Number:");
    }
    while (c < 0);


///// Check how many digits the card has
    d1 = c;
    do
    {
        d1 = (d1 / 10);
        nd++;
    } while (d1 != 0);
////   / printf("Number of digits is: %li\n", nd);



///// checksum





////Check to see if number is between 13 and 16 digits:
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
/////   printf("%li, %li, %li, %li, %li, %li, %li, %li, %li ,%li, %li, %li, %li\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13);

/////  printf("this card has 13 digits\n");
            if (d1 == 4)
            {
//// multiply every other number by 2 adding their digits when they have 2 digit results
                d2 = d2 * 2;
                if (d2 > 9)
                {
                    a = d2 / 10;
                    b = d2 % 10;
////   printf ("%i, %i", a, b);
                    d2 = (a+b);
                }
                d4 = d4 * 2;
                if (d4 > 9)
                {
                    a = d4 / 10;
                    b = d4 % 10;
////   printf ("%i, %i", a, b);
                    d4 = (a+b);
                }
                d6 = d6 * 2;
                if (d6 > 9)
                {
                    a = d6 / 10;
                    b = d6 % 10;
////   printf ("%i, %i", a, b);
                    d6 = (a+b);
                }
                d8 = d8 * 2;
                if (d8 > 9)
                {
                    a = d8 / 10;
                    b = d8 % 10;
////   printf ("%i, %i", a, b);
                    d8 = (a+b);
                }
                d10 = d10 * 2;
                if (d10 > 9)
                {
                    a = d10 / 10;
                    b = d10 % 10;
////   printf ("%i, %i", a, b);
                    d10 = (a+b);
                }
                d12 = d12 * 2;
                if (d12 > 9)
                {
                    a = d12 / 10;
                    b = d12 % 10;
////   printf ("%i, %i", a, b);
                    d12 = (a+b);
                }
///////// sum all the digits of every other number
                a = (d2 + d4 + d6 + d8 + d10 + d12);
                b = (d1 + d3 + d5 + d7 + d9 + d11 + d13);
                a = (a+b);

//// Check last digit of total sum
                b = a % 10;
                if (b == 0)
                {
                    printf("VISA\n");
                valid = true;
                }


            }



        }
        else if (nd == 14)
///// 14 digits is invalid
        {
            printf("INVALID\n");
        }
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
////  printf("%li, %li, %li, %li, %li, %li, %li, %li, %li ,%li, %li, %li, %li, %li, %li\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15);

/////  printf("this card has 15 digits\n");

    if (d1 == 3 && (d2 == 4 || d2 == 7))
    {

//// multiply every other number by 2 adding their digits when they have 2 digit results
                d2 = d2 * 2;
                if (d2 > 9)
                {
                    a = d2 / 10;
                    b = d2 % 10;
////   printf ("%i, %i", a, b);
                    d2 = (a+b);
                }
                d4 = d4 * 2;
                if (d4 > 9)
                {
                    a = d4 / 10;
                    b = d4 % 10;
////   printf ("%i, %i", a, b);
                    d4 = (a+b);
                }
                d6 = d6 * 2;
                if (d6 > 9)
                {
                    a = d6 / 10;
                    b = d6 % 10;
////   printf ("%i, %i", a, b);
                    d6 = (a+b);
                }
                d8 = d8 * 2;
                if (d8 > 9)
                {
                    a = d8 / 10;
                    b = d8 % 10;
////   printf ("%i, %i", a, b);
                    d8 = (a+b);
                }
                d10 = d10 * 2;
                if (d10 > 9)
                {
                    a = d10 / 10;
                    b = d10 % 10;
////   printf ("%i, %i", a, b);
                    d10 = (a+b);
                }
                d12 = d12 * 2;
                if (d12 > 9)
                {
                    a = d12 / 10;
                    b = d12 % 10;
////   printf ("%i, %i", a, b);
                    d12 = (a+b);
                }
                d14 = d14 * 2;
                if (d14 > 9)
                {
                    a = d14 / 10;
                    b = d14 % 10;
////   printf ("%i, %i", a, b);
                    d14 = (a+b);
                }

///////// sum all the digits of every other number
                a = (d2 + d4 + d6 + d8 + d10 + d12 + d14);
                b = (d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15);
                a = (a+b);

//// Check last digit of total sum
                b = a % 10;
                if (b == 0)
                {
                    printf("AMEX\n");
                    valid = true;
                }


        }


        }
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
/////   printf("%li, %li, %li, %li, %li, %li, %li, %li, %li ,%li, %li, %li, %li, %li, %li\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15);

/////  printf("this card has 16 digits\n");

            if (d1 == 5 && (d2 == 1 || d2 == 2 || d2 == 3 || d2 == 4 || d2 == 5))
            {

//// multiply every other number by 2 adding their digits when they have 2 digit results
                d2 = d2 * 2; ///2
                if (d2 > 9)
                {
                    a = d2 / 10;
                    b = d2 % 10;
////   printf ("%i, %i", a, b);
                    d2 = (a+b);
                }
                d4 = d4 * 2; //10
                if (d4 > 9)
                {
                    a = d4 / 10;
                    b = d4 % 10;
////   printf ("%i, %i", a, b);
                    d4 = (a+b); /// 10 is made into 1
                }
                d6 = d6 * 2; ///0
                if (d6 > 9)
                {
                    a = d6 / 10;
                    b = d6 % 10;
///   printf ("%i, %i", a, b);
                    d6 = (a+b);
                }
                d8 = d8 * 2; ///2
                if (d8 > 9)
                {
                    a = d8 / 10;
                    b = d8 % 10;
////   printf ("%i, %i", a, b);
                    d8 = (a+b);
                }
                d10 = d10 * 2; ////10
                if (d10 > 9)
                {
                    a = d10 / 10;
                    b = d10 % 10;
////   printf ("%i, %i", a, b);
                    d10 = (a+b); ///// 10 turned into 1
                }
                d12 = d12 * 2;//0
                if (d12 > 9)
                {
                    a = d12 / 10;
                    b = d12 % 10;
////   printf ("%i, %i", a, b);
                    d12 = (a+b);
                }
                d14 = d14 * 2; ////2
                if (d14 > 9)
                {
                    a = d14 / 10;
                    b = d14 % 10;
////   printf ("%i, %i", a, b);
                    d14 = (a+b);
                }
                d16 = d16 * 2; ////0
                if (d16 > 9)
                {
                    a = d16 / 10;
                    b = d16 % 10;
////   printf ("%i, %i", a, b);
                    d16 = (a+b);
                }

///////// sum all the digits of every other number
                a = (d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16); //// 8
/// printf("%i\n", a);
                b = (d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15); /////
////  printf("%i\n", b);
                a = (a+b);
//// printf("%i\n", a);

//// Check last digit of total sum
                b = a % 10;
                if (b == 0)
                {
                    printf("MASTERCARD\n");
                valid = true;
                }


            }
            else if (d1 == 4)
            {
//// multiply every other number by 2 adding their digits when they have 2 digit results
                d2 = d2 * 2;
                if (d2 > 9)
                {
                    a = d2 / 10;
                    b = d2 % 10;
////   printf ("%i, %i", a, b);
                    d2 = (a+b);
                }
                d4 = d4 * 2;
                if (d4 > 9)
                {
                    a = d4 / 10;
                    b = d4 % 10;
////   printf ("%i, %i", a, b);
                    d4 = (a+b);
                }
                d6 = d6 * 2;
                if (d6 > 9)
                {
                    a = d6 / 10;
                    b = d6 % 10;
////   printf ("%i, %i", a, b);
                    d6 = (a+b);
                }
                d8 = d8 * 2;
                if (d8 > 9)
                {
                    a = d8 / 10;
                    b = d8 % 10;
////   printf ("%i, %i", a, b);
                    d8 = (a+b);
                }
                d10 = d10 * 2;
                if (d10 > 9)
                {
                    a = d10 / 10;
                    b = d10 % 10;
////   printf ("%i, %i", a, b);
                    d10 = (a+b);
                }
                d12 = d12 * 2;
                if (d12 > 9)
                {
                    a = d12 / 10;
                    b = d12 % 10;
////   printf ("%i, %i", a, b);
                    d12 = (a+b);
                }
                d14 = d14 * 2;
                if (d14 > 9)
                {
                    a = d14 / 10;
                    b = d14 % 10;
////   printf ("%i, %i", a, b);
                    d14 = (a+b);
                }
                d16 = d16 * 2;
                if (d16 > 9)
                {
                    a = d16 / 10;
                    b = d16 % 10;
////   printf ("%i, %i", a, b);
                    d16 = (a+b);
                }

///////// sum all the digits of every other number
                a = (d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16);
                b = (d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15);
                a = (a+b);

//// Check last digit of total sum
                b = a % 10;
                if (b == 0)
                {
                    printf("VISA\n");
                    valid = true;
                }

            }



        }
        else
        {
            printf("INVALID\n");
            nd = 0;
        }


}
while (valid != true);





}



