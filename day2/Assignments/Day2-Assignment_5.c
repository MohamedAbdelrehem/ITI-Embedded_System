/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

    /*---------------------------------------------------- DAY 2----------------------------------------------------*/

/*----------------------------------------------------Assignment 5----------------------------------------------------*/

/*Write a login program in C that ask the user to enter his ID and his password, if the ID is correct the system will ask the
 user to enter his password up to 3 times, if he enters the password right the systems welcomes him,
 if the three times are incorrect, the system print No more tries.
 If the user ID is incorrect the system print You are not registered*/

#include <stdio.h>

void main(void)
{
    // user to enter his ID
    int id, pass, tries = 3;
    char wrong = 0;

    printf("Please Enter Your ID : ");
    scanf("%d", &id);

    switch (id)
    {
    case 1234:
        // Check if the password right
        printf("Enter the password : ");
        scanf("%d", &pass);

        do
        {
            if (wrong == 1)
            {
                printf("Try Again : ");
                scanf("%d", &pass);
            }

            if (7788 != pass)
            {
                if (tries >= 1)
                {
                    printf("Incorrect password, %d tries remaining\n", tries);
                    wrong = 1;
                }
                else
                {
                    printf("Sorry you entered the password wrong 3 times");
                }
            }
            else
            {
                printf("Welcome Ahmed");
                break;
            }
            tries--;

        } while (tries >= 0);
        break;
    case 5678:
        // Check if the password right
        printf("Enter the password : ");
        scanf("%d", &pass);

        do
        {
            if (wrong == 1)
            {
                printf("Try Again : ");
                scanf("%d", &pass);
            }

            if (5566 != pass)
            {
                if (tries >= 1)
                {
                    printf("Incorrect password, %d tries remaining\n", tries);
                    wrong = 1;
                }
                else
                {
                    printf("Sorry you entered the password wrong 3 times");
                }
            }
            else
            {
                printf("Welcome Amr");
                break;
            }
            tries--;

        } while (tries >= 0);
        break;
    case 9870:
        // Check if the password right
        printf("Enter the password : ");
        scanf("%d", &pass);

        do
        {
            if (wrong == 1)
            {
                printf("Try Again : ");
                scanf("%d", &pass);
            }

            if (1122 != pass)
            {
                if (tries >= 1)
                {
                    printf("Incorrect password, %d tries remaining\n", tries);
                    wrong = 1;
                }
                else
                {
                    printf("Sorry you entered the password wrong 3 times");
                }
            }
            else
            {
                printf("Welcome Wael");
                break;
            }
            tries--;

        } while (tries >= 0);
        break;
    default:
        printf("You are not registered");
    }
}
