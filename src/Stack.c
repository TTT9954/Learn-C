#include "Stack.h"

p_stack stackInit(p_stack Stack, uint8_t capacity)
{
   Stack->capacity = capacity;
   Stack->item = (uint8_t *)malloc(sizeof(uint8_t) * Stack->capacity);
   return Stack;
}

p_stack push(p_stack Stack, uint8_t data)
{
   if(Stack == NULL)
   {
      return NULL;
   }

   if(stackIsFull(Stack))
   {
      return Stack;
   }

   Stack->item[Stack->capacity] = data;
   Stack->capacity++;
   
   return Stack;
}

p_stack pop(p_stack Stack, uint8_t *data)
{
   *data = Stack->item[Stack->capacity - 1];
   Stack->capacity--;

   if(Stack->capacity < 0)
   {
      Stack->capacity = 0;
   }

   return Stack;
}

p_stack peek(p_stack Stack, uint8_t *data)
{
   *data = Stack->item[Stack->capacity - 1];
   return Stack;
}

p_stack stackFree(p_stack Stack)
{
   free(Stack->item);
   free(Stack);
   return NULL;
}

p_stack stackClear(p_stack Stack)
{
   Stack->capacity = 0;
   return Stack;
}

p_stack stackIsFull(p_stack Stack)
{
   return (Stack->capacity == MAX_CAPACITY);
}

p_stack stackIsEmpty(p_stack Stack)
{
   return (Stack->capacity == 0);
}

p_stack stackGetCapacity(p_stack Stack)
{
   return Stack->capacity;
}

p_stack printStack(p_stack Stack)
{
   for(int i = 0; i < Stack->capacity; i++)
   {
      printf("%d ", Stack->item[i]);
   }
   printf("\n");
   return Stack;
}