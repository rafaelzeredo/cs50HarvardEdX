#include <cs50.h>
#include <stdio.h>



int main(void)
{
    long d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16;
    long nd = 0;
    long c;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;
    int a, b, x;
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
printf("%li, %li, %li, %li, %li, %li, %li, %li, %li ,%li, %li, %li, %li\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13);
n1 = d1;
n2 = d2;
n3 = d3;
n4 = d4;
n5 = d5;
n6 = d6;
n7 = d7;
n8 = d8;
n9 = d9;
n10 = d10;
n11 = d11;
n12 = d12;
n13 = d13;
n14 = d14;
n15 = d15;
n16 = d16;
printf("this card has 13 digits\n");
            if (n1 == 4)
            {
//// multiply every other number by 2 adding their digits when they have 2 digit results
                n2 = n2 * 2;
                if (n2 > 9)
                {
                    a = n2 / 10;
                    b = n2 % 10;
////   printf ("%i, %i", a, b);
                    n2 = (a+b);
                }
                n4 = n4 * 2;
                if (n4 > 9)
                {
                    a = n4 / 10;
                    b = n4 % 10;
////   printf ("%i, %i", a, b);
                    n4 = (a+b);
                }
                n6 = n6 * 2;
                if (n6 > 9)
                {
                    a = n6 / 10;
                    b = n6 % 10;
////   printf ("%i, %i", a, b);
                    n6 = (a+b);
                }
                n8 = n8 * 2;
                if (n8 > 9)
                {
                    a = n8 / 10;
                    b = n8 % 10;
////   printf ("%i, %i", a, b);
                    n8 = (a+b);
                }
                n10 = n10 * 2;
                if (n10 > 9)
                {
                    a = n10 / 10;
                    b = n10 % 10;
////   printf ("%i, %i", a, b);
                    n10 = (a+b);
                }
                n12 = n12 * 2;
                if (n12 > 9)
                {
                    a = n12 / 10;
                    b = n12 % 10;
////   printf ("%i, %i", a, b);
                    n12 = (a+b);
                }
///////// sum all the digits of every other number
                a = (n2 + n4 + n6 + n8 + n10 + n12);
                b = (n1 + n3 + n5 + n7 + n9 + n11 + n13);
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
printf("%li, %li, %li, %li, %li, %li, %li, %li, %li ,%li, %li, %li, %li, %li, %li\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15);
n1 = d1;
n2 = d2;
n3 = d3;
n4 = d4;
n5 = d5;
n6 = d6;
n7 = d7;
n8 = d8;
n9 = d9;
n10 = d10;
n11 = d11;
n12 = d12;
n13 = d13;
n14 = d14;
n15 = d15;
n16 = d16;
printf("this card has 15 digits\n");

    if (n1 == 3 && (n2 == 4 || n2 == 7))
    {

//// multiply every other number by 2 adding their digits when they have 2 digit results
                n2 = n2 * 2;
                if (n2 > 9)
                {
                    a = n2 / 10;
                    b = n2 % 10;
////   printf ("%i, %i", a, b);
                    n2 = (a+b);
                }
                n4 = n4 * 2;
                if (n4 > 9)
                {
                    a = n4 / 10;
                    b = n4 % 10;
////   printf ("%i, %i", a, b);
                    n4 = (a+b);
                }
                n6 = n6 * 2;
                if (n6 > 9)
                {
                    a = n6 / 10;
                    b = n6 % 10;
////   printf ("%i, %i", a, b);
                    n6 = (a+b);
                }
                n8 = n8 * 2;
                if (n8 > 9)
                {
                    a = n8 / 10;
                    b = n8 % 10;
////   printf ("%i, %i", a, b);
                    n8 = (a+b);
                }
                n10 = n10 * 2;
                if (n10 > 9)
                {
                    a = n10 / 10;
                    b = n10 % 10;
////   printf ("%i, %i", a, b);
                    n10 = (a+b);
                }
                n12 = n12 * 2;
                if (n12 > 9)
                {
                    a = n12 / 10;
                    b = n12 % 10;
////   printf ("%i, %i", a, b);
                    n12 = (a+b);
                }
                n14 = n14 * 2;
                if (n14 > 9)
                {
                    a = n14 / 10;
                    b = n14 % 10;
////   printf ("%i, %i", a, b);
                    n14 = (a+b);
                }

///////// sum all the digits of every other number
                a = (n2 + n4 + n6 + n8 + n10 + n12 + n14);
                b = (n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15);
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
printf("%li, %li, %li, %li, %li, %li, %li, %li, %li ,%li, %li, %li, %li, %li, %li, %li\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16);
n1 = d1;
n2 = d2;
n3 = d3;
n4 = d4;
n5 = d5;
n6 = d6;
n7 = d7;
n8 = d8;
n9 = d9;
n10 = d10;
n11 = d11;
n12 = d12;
n13 = d13;
n14 = d14;
n15 = d15;
n16 = d16;
printf("this card has 16 digits\n");

            if (n1 == 5 && (n2 == 1 || n2 == 2 || n2 == 3 || n2 == 4 || n2 == 5))
            {

//// multiply every other number by 2 adding their digits when they have 2 digit results
                n2 = n2 * 2; ///2
                if (n2 > 9)
                {
                    a = n2 / 10;
                    b = n2 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n2 = (a+b);

                }
                printf("d2 = %i\n", n2);
                n4 = n4 * 2; //10
                if (n4 > 9)
                {
                    a = n4 / 10;
                    b = n4 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n4 = (a+b); /// 10 is made into 1
                }
                printf("d4 = %i\n", n4);
                n6 = n6 * 2; ///0
                if (n6 > 9)
                {
                    a = n6 / 10;
                    b = n6 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n6 = (a+b);
                }
                printf("d6 = %i\n", n6);
                n8 = n8 * 2; ///2
                if (n8 > 9)
                {
                    a = n8 / 10;
                    b = n8 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n8 = (a+b);
                }
                printf("d8 = %i\n", n8);
                n10 = n10 * 2; ////10
                if (n10 > 9)
                {
                    a = n10 / 10;
                    b = n10 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n10 = (a+b); ///// 10 turned into 1
                }
                printf("d10 = %i\n", n10);
                n12 = n12 * 2;//0
                if (n12 > 9)
                {
                    a = n12 / 10;
                    b = n12 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n12 = (a+b);
                }
                printf("d12 = %i\n", n12);
                n14 = n14 * 2; ////2
                if (n14 > 9)
                {
                    a = n14 / 10;
                    b = n14 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n14 = (a+b);
                }
                printf("d14 = %i\n", n14);
                n16 = n16 * 2; ////0
                if (n16 > 9)
                {
                    a = n16 / 10;
                    b = n16 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n16 = (a+b);
                }
                printf("d16 = %i\n", n16);

///////// sum all the digits of every other number
                a = (n2 + n4 + n6 + n8 + n10 + n12 + n14 + n16); //// 8
printf("%i\n", a);
                b = (n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15); ///// 17
printf("%i\n", b);
                a = (a+b);
printf("%i\n", a);

//// Check last digit of total sum
                b = a % 10;
                if (b == 0)
                {
                    printf("MASTERCARD\n");
                valid = true;
                }


            }
            else if (n1 == 4)
            {
//// multiply every other number by 2 adding their digits when they have 2 digit results
                n2 = n2 * 2; ///2
                if (n2 > 9)
                {
                    a = n2 / 10;
                    b = n2 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n2 = (a+b);
                    printf("d2 = %i\n", n2);
                }
                n4 = n4 * 2; //10
                if (n4 > 9)
                {
                    a = n4 / 10;
                    b = n4 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n4 = (a+b); /// 10 is made into 1
                    printf("d4 = %i\n", n4);
                }
                n6 = n6 * 2; ///0
                if (n6 > 9)
                {
                    a = n6 / 10;
                    b = n6 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n6 = (a+b);
                    printf("d6 = %i", n6);
                }
                n8 = n8 * 2; ///2
                if (n8 > 9)
                {
                    a = n8 / 10;
                    b = n8 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n8 = (a+b);
                    printf("d8 = %i", n8);

                }
                n10 = n10 * 2; ////10
                if (n10 > 9)
                {
                    a = n10 / 10;
                    b = n10 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n10 = (a+b); ///// 10 turned into 1
                    printf("d10 = %i", n10);
                }
                n12 = n12 * 2;//0
                if (n12 > 9)
                {
                    a = n12 / 10;
                    b = n12 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n12 = (a+b);
                    printf("d12 = %i", n12);
                }
                n14 = n14 * 2; ////2
                if (n14 > 9)
                {
                    a = n14 / 10;
                    b = n14 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n14 = (a+b);
                    printf("d14 = %i", n14);
                }
                n16 = n16 * 2; ////0
                if (n16 > 9)
                {
                    a = n16 / 10;
                    b = n16 % 10;
printf ("a=%i, b=%i\n", a, b);
                    n16 = (a+b);
                    printf("d16 = %i", n16);
                }

///////// sum all the digits of every other number
                a = (n2 + n4 + n6 + n8 + n10 + n12 + n14 + n16); //// 8
printf("%i\n", a);
                b = (n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15); ///// 17
printf("%i\n", b);
                a = (a+b);
printf("%i\n", a);


//// Check last digit of total sum
                b = a % 10;
                printf("b = %i", b);
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
            return 0;
        }


}
while (valid != true);





}



