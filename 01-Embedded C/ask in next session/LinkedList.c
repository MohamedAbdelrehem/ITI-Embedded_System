/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 7----------------------------------------------------*/

/*----------------------------------------------------Assignment 1----------------------------------------------------*/
/*Write a C code that allow the user to add a node to linked list by pressing 0 and to print the linked list by pressing 1.
  The software shall continue forever till the user enters 2.
  If the user enters any other numbers the software shall print incorrect entry.
  See the following scenarios for more details.
  //! ++ delete certain node ++ add a new node at a certain position
 */

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "MY_LINKEDLIST.h"

void instructionsPrint(void);

void main(void)
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;

    // print starting message
    instructionsPrint();
    u16 choice;

    do
    {
        printf("Your Choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 0:
            // add node anywhere even at end
            printf("Enter the index of the node you want to add new node after (-1 to add at the end): ");
            u16 indexnew, data;
            scanf(" %d", &indexnew);
            printf("Enter the new node data: ");
            scanf(" %d", &data);
            addnode(head, indexnew, data);
            break;
        case 1:
            printLinkedList(head);
            break;
        case 2:
            printf("%d\n", head->data);
            break;
        case 3:
            instructionsPrint();
            break;
        case 9:
            printf("Exitting.....\n");
            break;
        default:
            printf("Invalid Choice please try again\n");
            break;
        }
    } while (choice != 9);
}
void instructionsPrint(void)
{
    printf("To add node enter 0\nTo print the linked list enter 1\nTo print the count of linked list enter 2\nTo Repeat instructions press 3\nTo exit press to 9\n\n");
}