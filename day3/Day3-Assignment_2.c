/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 3----------------------------------------------------*/

/*----------------------------------------------------Assignment 2----------------------------------------------------*/
/*Write a C program to act as simple calculator, first it will ask the user to enter the
operation ID, depending on the operation, the program will ask the user either to
enter 1 operand or 2 operands and the program will execute the operation and print
the result. Each operation should be implemented in a stand a long function.*/

#include <stdio.h>
#include "./MY_MATH.h"

void main(void)
{
    // show the instructions
    PrintInstructions();
    // read the id input
    int id, op1, op2;
    float ans;
    printf("enter Operation ID: ");
    scanf("%d", &id);
    // inf loop untill id = 0
    while (id != 0)
    {

        // check if id for 1 or 2 operant
        if (id == 7 || id == 10 || id == 11)
        {
            // scan operants
            printf("Please enter one operant: ");
            scanf(" %d", &op1);
        }
        else
        {
            // scan operants
            printf("Please enter operant one and two: ");
            scanf(" %d %d", &op1, &op2);
        }
        // switch-case to solve it in O(1)
        switch (id)
        {
        case 1:
            ans = addFunc(op1, op2);
            break;
        case 2:
            ans = subtractFunc(op1, op2);
            break;
        case 3:
            ans = multiplyFunc(op1, op2);
            break;
        case 4:
            // divition work to one decimal place 0.x
            ans = divideFunc(op1, op2);
            break;
        case 5:
            ans = andFunc(op1, op2);
            break;
        case 6:
            ans = orFunc(op1, op2);
            break;
        case 7:
            ans = notFunc(op1);
            break;
        case 8:
            ans = xorFunc(op1, op2);
            break;
        case 9:
            ans = reminderFunc(op1, op2);
            break;
        case 10:
            ans = incrementFunc(op1);
            break;
        case 11:
            ans = decrementFunc(op1);
            break;
        case 12:
            PrintInstructions();
            break;
        }

        // output the answer
        printf("The Answer is: %0.1f\n\n", ans);
        printf("enter another Operation ID: ");
        scanf("%d", &id);
    }
}