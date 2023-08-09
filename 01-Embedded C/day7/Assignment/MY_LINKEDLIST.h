#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

// linked list struct
typedef struct node_i
{
    u16 data;
    struct node_i *next;
} Node;

int addnode(Node *head, u16 index, u16 nodeValue)
{

    if (index > (head->data) && index != 255)
    {
        printf("This index is out of suitable range\n");
    }
    else
    {
        Node *ptr = head;
        // create new node
        Node *newNode = (Node *)malloc(sizeof(Node));
        // asign data to the node
        newNode->data = nodeValue;

        // enter the value at start
        if (index == 0)
        {
            newNode->next = head->next;
            ptr->next = newNode;
            (head->data)++;
        }
        // enter the value at the end

        else if (index == 255)
        {
            newNode->next = NULL;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            (head->data)++;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            (head->data)++;
        }
        printf("Node Added Thank You\n\n");
    }
}
void removeNode(Node *head, u16 indexToRemove)
{
    if (indexToRemove > head->data)
    {
        printf("Invalid index to remove\n");
        return;
    }

    Node *ptr = head;

    // Find the node before the one to be removed
    for (int i = 0; i < indexToRemove - 1; i++)
    {
        ptr = ptr->next;
    }

    // Remove the node at the specified index
    Node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    (head->data)--;
}
void printLinkedList(Node *head)
{
    printf("\n------------------------\n");
    if (head->data == 0)
    {
        printf("List is Empty\n");
    }
    else
    {

        Node *ptr = head->next;
        int i = 1;
        while (ptr != NULL)
        {
            printf("Node Number %d = %d\n", i, ptr->data);
            ptr = ptr->next;
            i++;
        }
    }
    printf("------------------------\n\n");
}