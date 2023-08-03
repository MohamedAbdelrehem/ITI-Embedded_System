/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

    /*---------------------------------------------------- DAY 2----------------------------------------------------*/

/*----------------------------------------------------Assignment 4----------------------------------------------------*/

/*Write a C program that ask the user to enter two numbers and print their summation,
     this program should never ends until the user close the window*/

#include <stdio.h>

void main(void)
{
    int num1, num2;
    while (1)
    {
        // scan the numbers
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);
        printf("The result is %d\n\n", num1 + num2);
    }
}
