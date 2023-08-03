/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 3----------------------------------------------------*/

/*----------------------------------------------------Assignment 1----------------------------------------------------*/
/*Write a C program the implement 2 function:

1- Function to get the maximum of 4 values
2- Function to get the minimum of 4 values

The program will ask the user first to enter the 4 values, then print the maximum
number and minimum number of them.*/

#include <stdio.h>
#define size 4
void maxNum(int *arr);
void minNum(int *arr);

void main(void)
{
    int arr[4] = {8, 6, 2, 4};
    maxNum(arr);
    minNum(arr);
}
void maxNum(int *arr)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("max = %d\n", max);
}
void minNum(int *arr)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("min = %d\n", min);
}