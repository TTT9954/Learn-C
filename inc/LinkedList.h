#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../inc/main.h"

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;   
}List_t;

typedef List_t *pList_t;


List_t* createNewNode(List_t **headNode, uint8_t data);
pList_t createList(List_t **headNode, uint8_t *size);
void AppendNode(List_t *Node, uint8_t data);
void displayLinkedList1(List_t* p);
void displayLinkedList(pList_t p);
pList_t insertAtEnd(pList_t *headNode, int value);
pList_t insertWithUser(pList_t *headNode, int size);
pList_t insertAtBegin(pList_t *headNode, int value);
int countElement(pList_t p);
int isEmpty(pList_t head);
int SumList(pList_t head);
int SearchKey(pList_t head, int key);

#endif