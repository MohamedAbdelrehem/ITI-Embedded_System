/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*------------------------------------------------------------ DAY 7 ------------------------------------------------------------*/

/*----------------------------------------------------Assignment 1 & 2 & lab2----------------------------------------------------*/
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
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;

    // print starting message
    instructionsPrint();
    u16 choice;

    do
    {
        printf("Your Choice: ");
        scanf(" %hd", &choice);
        switch (choice)
        {
        case 0:
            // add node anywhere even at end or start
            u16 indexnew, data;
            printf("Enter the index of the node you want to add new node after (255 to add at the end): ");
            scanf("%hd", &indexnew);
            printf("Enter the new node data: ");
            scanf("%hd", &data);
            addnode(head, indexnew, data);
            break;
        case 1:
            // print the whole linked list
            printLinkedList(head);
            break;
        case 2:
            // print the count of linked list enter
            //(i used head as just pointer to the start and sotred the lenth of linked list in it's data)
            printf("%d\n", head->data);
            break;
        case 3:
            u16 indexToRemove;
            printf("enter the node number you want to remove: ");
            scanf("%hd", &indexToRemove);
            removeNode(head, indexToRemove);
            break;
        case 4:
            instructionsPrint();
            break;
        case 9:
            printf("Exitting.....\nThank you from all my heart <3\n");
            break;
        default:
            printf("Invalid Choice please try again\n");
            break;
        }
    } while (choice != 9);
}
void instructionsPrint(void)
{
    printf("To add node enter 0\nTo print the linked list enter 1\nTo print the count of linked list enter 2\nTo remove node press  3\nTo Repeat instructions press 4\nTo exit press to 9\n\n");
}