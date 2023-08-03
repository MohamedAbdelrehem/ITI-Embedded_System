/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 1----------------------------------------------------*/

#include <stdio.h>

void main(void)
{
    /*NOTE:
        all code run at the same time without coments
        but feel free to comment any part
    */

    /*----------------------------------------------------Assignment 1----------------------------------------------------*/
    // write a code that can draw this pyramid

    //----- first way normal printf

    printf("     *\n    ***\n   *****\n  *******\n *********\n***********\n");

    //----- second way "for loop"

    printf("\n\n");

    int i, space, rows = 6, k = 0;

    for (i = 1; i <= rows; ++i, k = 0)
    {
        for (space = 1; space <= rows - i; ++space)
        {
            printf(" ");
        }
        while (k != 2 * i - 1)
        {
            printf("*");
            ++k;
        }
        printf("\n");
    }

    /*----------------------------------------------------Assignment 2----------------------------------------------------*/
    // write a code that scan 3 numbers from the user and print them in reversed order
    printf("\n\n");

    int number1, number2, number3;

    printf("Please enter number 1: ");
    scanf("%d", &number1);
    printf("Please enter number 2: ");
    scanf("%d", &number2);
    printf("Please enter number 3: ");
    scanf("%d", &number3);

    // reverse numbers without sorting
    printf("number 3: %d\n", number3);
    printf("number 2: %d\n", number2);
    printf("number 1: %d\n", number1);

    /*----------------------------------------------------Assignment 3----------------------------------------------------*/
    // write a code that takes 2 numbers and print their summation,subtraction,adding,oring,and Xoring
    printf("\n\n");

    int a, b;
    printf("Please enter number a: ");
    scanf("%d", &a);
    printf("Please enter number b: ");
    scanf("%d", &b);

    printf("a + b = %d\na - b = %d\na & b = %d\na | b = %d\na ^ b = %d", a + b, a - b, a & b, a / b, a ^ b);
}