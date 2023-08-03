/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 2----------------------------------------------------*/

/*----------------------------------------------------Assignment 1----------------------------------------------------*/
/*Write a C code that ask the user to enter 10 numbers, then ask him to enter another number to search on it in the 10 numbers and print its
    location in case it is found. In case the number is not found, it will print number no exist*/
#include <stdio.h>

#define size 10

void main(void)
{

    /*--------------------------------------------- Using only If Condition ---------------------------------------------*/

    //! this is the start of answer1 comment

    // int number1, number2, number3, number4, number5, number6, number7, number8, number9, number10;
    // int searchVal;

    // printf("Enter Number 1: ");
    // scanf("%d", &number1);

    // printf("Enter Number 2: ");
    // scanf("%d", &number2);

    // printf("Enter Number 3: ");
    // scanf("%d", &number3);

    // printf("Enter Number 4: ");
    // scanf("%d", &number4);

    // printf("Enter Number 5: ");
    // scanf("%d", &number5);

    // printf("Enter Number 6: ");
    // scanf("%d", &number6);

    // printf("Enter Number 7: ");
    // scanf("%d", &number7);

    // printf("Enter Number 8: ");
    // scanf("%d", &number8);

    // printf("Enter Number 9: ");
    // scanf("%d", &number9);

    // printf("Enter Number 10: ");
    // scanf("%d", &number10);

    // printf("Enter the value to search: ");
    // scanf("%d", &searchVal);

    // char flag = 0;
    // printf("Value is ");
    // if (searchVal == number1)
    // {
    //     printf("\nat location 1");
    //     flag = 1;
    // }
    // if (searchVal == number2)
    // {
    //     printf("\nat location 2");
    //     flag = 1;
    // }
    // if (searchVal == number3)
    // {
    //     printf("\nat location 3");
    //     flag = 1;
    // }
    // if (searchVal == number4)
    // {
    //     printf("\nat location 4");
    //     flag = 1;
    // }
    // if (searchVal == number5)
    // {
    //     printf("\nat location 5");
    //     flag = 1;
    // }
    // if (searchVal == number6)
    // {
    //     printf("\nat location 6");
    //     flag = 1;
    // }
    // if (searchVal == number7)
    // {
    //     printf("\nat location 7");
    //     flag = 1;
    // }
    // if (searchVal == number8)
    // {
    //     printf("\nat location 8");
    //     flag = 1;
    // }
    // if (searchVal == number9)
    // {
    //     printf("\nat location 9");
    //     flag = 1;
    // }
    // if (searchVal == number10)
    // {
    //     printf("\nat location 10");
    //     flag = 1;
    // }

    // if (flag == 0)
    // {
    //     printf("not exist");
    // }

    //! this is the end of answer1 comment

    /*------------------------------------------ Using array, loops and if condition ------------------------------------------*/

    //! this is the start of answer2 comment
    int number[size], searchVal;

    for (int i = 0; i < size; i++)
    {
        printf("Enter Number %d : ", i + 1);
        scanf("%d", &number[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &searchVal);

    char flag = 0;
    printf("Ualue is ");
    for (int i = 0; i < size; i++)
    {
        if (searchVal == number[i])
        {
            printf("\nat location %d", i + 1);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("not exist");
    }

    //! this is the end of answer2 comment
}
