#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

// linked list struct
typedef struct node_i
{
    u16 data;
    struct node_i *next;
} node;

void addnode(node *head, u16 index, u16 data);

void main(void)
{

    // add nodes
    node *head = (node *)malloc(sizeof(node));
    node *node1 = (node *)malloc(sizeof(node));
    node *node2 = (node *)malloc(sizeof(node));
    // add data
    head->data = 5;
    node1->data = 20;
    node2->data = 15;
    // add next address
    head->next = node1;
    node1->next = node2;
    node2->next = NULL;

    node *ptr = head;

    addnode(head, 1, 55);

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void addnode(node *head, u16 index, u16 newdata)
{
    // create new node
    node *newNode = (node *)malloc(sizeof(node));
    // asign data to the node
    newNode->data = newdata;
    // if 0 place at start
    node *ptr = head;
    u16 count = 0;

    while (ptr != NULL)
    {
        if (count == index)
        {
            printf("%d\n\n", count);
            if (ptr->next != NULL)
            {
                ptr->next = newNode;
                newNode->next = ptr->next;
            }
            else if (ptr->next == NULL)
            {
                ptr->next = newNode;
                newNode->next = NULL;
            }
        }
        count++;
        ptr = ptr->next;
    }
}