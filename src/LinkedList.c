#include "../inc/LinkedList.h"

List_t* createNewNode(List_t **headNode, uint8_t data)
{
    List_t* newNode = (List_t*)(malloc(sizeof(List_t)));

    if(newNode != NULL)
    {
        (newNode)->data = data;
        (newNode)->next = NULL;
    }

    *headNode = newNode;
    return *headNode;
}

void AppendNode(List_t *Node, uint8_t data)
{
  List_t *newNode = (List_t*)(malloc(sizeof(List_t)));

  
  while(Node != NULL)
  {

  }
}

void displayLinkedList1(List_t* p)
{
   if(p != NULL)
   {
      while((p) != NULL)
      {       
        printf("%u, ", (p)->data);
        (p) = (p)->next;
      }  
   }
   else printf("List is empty !");
}

pList_t insertAtEnd(pList_t *headNode, int value)
{
   pList_t newNode = (pList_t)(malloc(sizeof(pList_t)));
   pList_t tranverseNode = (pList_t)(malloc(sizeof(pList_t)));

   newNode->data = value;
   newNode->next = NULL;
   tranverseNode = *headNode;
   if(isEmpty(*headNode) != 1)
   {
      while(tranverseNode->next != NULL)
      {
         tranverseNode = tranverseNode->next;
      }
      tranverseNode->next = newNode;
      newNode->next = NULL;
      tranverseNode = newNode;
   }
   else *headNode = tranverseNode = newNode;
   
   return *headNode;
}

pList_t insertWithUser(pList_t *headNode, int size)
{
   int i = 0;
   int value;
   while (i < size)
   {
      printf("Input element: ");
      scanf("%d", &value);
      *headNode = insertAtEnd(headNode, value);
      printf("List: ");
      displayLinkedList(*headNode);
      printf("\n");
      i++;
   }

   return *headNode;
}

pList_t insertAtBegin(pList_t *headNode, int value)
{
   pList_t newNode = (pList_t)(malloc(sizeof(pList_t)));
   newNode->data = value;
   newNode->next = NULL;
   if(isEmpty(*headNode) != 1) newNode->next = *headNode;

   *headNode = newNode;

   free(newNode);

   return *headNode;
}

void displayLinkedList(pList_t p)
{
   if(p != NULL)
   {
      while((p) != NULL)
      {
         if(isEmpty(p->next)) 
         {
            printf("%d", (p)->data);
            break;
         }
         printf("%d, ", (p)->data);
         (p) = (p)->next;

      }  
   }
   else printf("List is empty !");
}

int countElement(pList_t p)
{
   int x= 0;
   while((p) != NULL)
   {
      ++x;
      (p) = (p)->next;
   }

   return x;
}

int isEmpty(pList_t head)
{
   if(!head) return 1;
   else return 0;
}

int SumList(pList_t head)
{
   int sum = 0;
   if(isEmpty(head) == 1) sum = 0;
   else
   {
      while(isEmpty(head) == 0)
      {
         sum += head->data;
         head = head->next;
      }
   }

   free(head);

   return sum;
}

int SearchKey(pList_t head, int key)
{
   int isFind = 0;
   pList_t tranverseNode = (pList_t)(malloc(sizeof(pList_t)));

   tranverseNode = head;

   if(isEmpty(tranverseNode) == 1) isFind = -1;
   else
   {
      while (isEmpty(tranverseNode) != 1)
      {
         isFind = 0;
         if(tranverseNode->data == key)
         {
            isFind = 1;
            break;
         }
         tranverseNode = tranverseNode->next;
      }
   }

   return isFind;
}
