#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

// linked list struct
typedef struct node_i
{
    u16 data;
    struct node_i *next;
} node;

int addnode(node *head, u16 index, u16 newdata)
{
    int cc = head->data;
    printf("%d %d %d", index, cc, newdata);
    if (index > 2)
    {
        printf("here");
        printf("%d", (head->data));
        printf("This index is out of suitable range\n");
    }
    // else
    // {
    //     // create new node
    //     node *newNode = (node *)malloc(sizeof(node));
    //     // asign data to the node
    //     newNode->data = newdata;
    //     // if 0 place at start
    //     node *ptr = head;
    //     u16 count = 0;

    //     while (ptr != NULL)
    //     {
    //         if (count == index)
    //         {
    //             printf("%d\n\n", count);
    //             if (ptr->next != NULL)
    //             {
    //                 ptr->next = newNode;
    //                 newNode->next = ptr->next;
    //             }
    //             else if (ptr->next == NULL)
    //             {
    //                 ptr->next = newNode;
    //                 newNode->next = NULL;
    //             }
    //         }
    //         count++;
    //         ptr = ptr->next;
    //     }
    // }
}

void printLinkedList(node *head)
{
    if (head->data == 0)
    {
        printf("List is Empty");
    }
    else
    {
        node *ptr = head->next;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}