/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 3----------------------------------------------------*/

/*----------------------------------------------------Assignment 3----------------------------------------------------*/
/*Write a C code that ask the user to enter 10 values and save them in an array
using a for loop. Then print the minimum and the maximum of the values.*/

#include <stdio.h>

void main(void)
{
    // Scan the numbers from the user
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0, min = arr[0];
    // compare and check the max and min val
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Max Value is %d\nMin Value is %d", max, min);
}