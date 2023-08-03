/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

    /*---------------------------------------------------- DAY 2----------------------------------------------------*/

/*----------------------------------------------------Assignment 6----------------------------------------------------*/

/*Write a c program that draw a pyramid of
stars with height entered by the user*/

#include <stdio.h>

void main(void)
{

    printf("Please Enter the hight of the pyramid: ");

    int i, space, rows, k = 0;

    scanf("%d", &rows);

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
