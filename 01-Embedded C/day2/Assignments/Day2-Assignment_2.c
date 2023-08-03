/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

    /*---------------------------------------------------- DAY 2----------------------------------------------------*/

/*----------------------------------------------------Assignment 2----------------------------------------------------*/

/*Write a C code that ask the user to enter his ID, if the ID is valid it will ask the user to enter his password, if the password is correct the
program will print the user name, if the password is incorrect the program will print Incorrect Password.
In case of not existing ID, the program will print Incorrect ID*/

#include <stdio.h>

void main(void)
{
    // user to enter his ID
    int id, pass;

    printf("Enter the ID : ");
    scanf("%d", &id);

    switch (id)
    {
    case 1234:
        // Check if the password (ID is the same as ID for TESTING)
        printf("Enter the password : ");
        scanf("%d", &pass);
        if (1234 == pass)
        {
            printf("Welcome Ahmed");
        }
        else
        {
            printf("Incorrect Password");
        }
        break;
    case 5678:
        // Check if the password (ID is the same as ID for TESTING)
        printf("Enter the password : ");
        scanf("%d", &pass);
        if (5678 == pass)
        {
            printf("Welcome Youssef");
        }
        else
        {
            printf("Incorrect Password");
        }
        break;
    case 1145:
        // Check if the password (ID is the same as ID for TESTING)
        printf("Enter the password : ");
        scanf("%d", &pass);
        if (1145 == pass)
        {
            printf("Welcome Mina");
        }
        else
        {
            printf("Incorrect Password");
        }
        break;
    default:
        printf("Incorrect ID");
    }
}
