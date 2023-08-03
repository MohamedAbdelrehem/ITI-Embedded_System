/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

    /*---------------------------------------------------- DAY 2----------------------------------------------------*/

/*----------------------------------------------------Assignment 3----------------------------------------------------*/

/*Write a code that will ask the user to enter 3 numbers, the program will print the maximum number of them.*/

#include <stdio.h>

void main(void)
{
    int num1, num2, num3;

    // scan the numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the third number: ");
    scanf("%d", &num3);

    // find the max number
    int maxNumber = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

    printf("The maximum number is: %d\n", maxNumber);
}
