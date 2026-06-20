#include "Stack.h"

mystack stackInit(mystack Stack, uint8_t size)
{
   Stack = (mystack)malloc(sizeof(mystack));

   if(Stack == NULL)
   {
      assert(Stack != NULL);
      return NULL;
   }

   size = (size >= 0) ? ((size <= MAX_CAPACITY) ? size : MAX_CAPACITY) : 0;

   Stack->size = size;

   Stack->capacity = 0;

   Stack->item = (uint8_t *)malloc(sizeof(uint8_t) * Stack->size);

   if(Stack->item == NULL)
   {
      assert(Stack->item != NULL);
      free(Stack);
      return NULL;
   }

   return (Stack);
}

mystack push(mystack Stack, uint8_t data)
{
   if(Stack == NULL)
   {
      printf("ERROR: Stack pointer is NULL!\n");
      return NULL;
   }
   if(stackIsFull(Stack))
   {
      printf("ERROR: Attempted to push data (%u) into a full stack! (size = %u)\n", data, Stack->size);
      return Stack;
   }

   Stack->item[Stack->capacity] = data;
   Stack->capacity++;
   
   
   return Stack;
}

mystack pop(mystack Stack, uint8_t *data)
{
   *data = Stack->item[Stack->capacity - 1];

   if(Stack == NULL)
   {
      printf("ERROR: Stack pointer is NULL!\n");
      return NULL;
   }

   if(stackIsEmpty(Stack))
   {
      printf("ERROR: Attempted to pop data from an empty stack!\n");
      return Stack;
   }

   Stack->capacity--;

   if(Stack->capacity < 0)
   {
      Stack->capacity = 0;
   }

   return Stack;
}

mystack peek(mystack Stack, uint8_t *data)
{
   *data = Stack->item[Stack->capacity - 1];
   return Stack;
}

mystack stackFree(mystack Stack)
{
   free(Stack->item);
   free(Stack);
   return NULL;
}

mystack stackClear(mystack Stack)
{
   Stack->capacity = 0;
   return Stack;
}

bool stackIsFull(mystack Stack)
{
   return (Stack->capacity >= (Stack->size));
}

bool stackIsEmpty(mystack Stack)
{
   return (Stack->capacity == 0);
}

uint8_t stackGetCapacity(mystack Stack)
{
   return Stack->capacity;
}

mystack printStack(mystack Stack)
{
   for(uint8_t i = 0; i < Stack->capacity; i++)
   {
      printf("%u ", Stack->item[i]);
   }
   printf("\n");
   return Stack;
}