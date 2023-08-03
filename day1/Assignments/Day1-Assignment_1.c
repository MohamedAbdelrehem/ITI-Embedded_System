/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 1----------------------------------------------------*/

#include <stdio.h>

void main(void)
{
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
}