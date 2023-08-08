/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 4----------------------------------------------------*/

/*----------------------------------------------------Assignment 1----------------------------------------------------*/
/*Write a C code that defines a function which takes an array as input argument and
apply the bubble sorting algorithm on it, then print the result*/

#include <stdio.h>
#define size 10

void MyBubbleSort(int *arrToSort);

void main(void)
{
    int arr[size] = {8, 5, 3, 9, 1, 10, 64, 32, 2, 1};
    MyBubbleSort(arr);
}
void MyBubbleSort(int *arrToSort)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arrToSort[j] > arrToSort[j + 1])
            {
                temp = arrToSort[j];
                arrToSort[j] = arrToSort[j + 1];
                arrToSort[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrToSort[i]);
    }
}