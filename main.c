//#include "inc/main.h"
#include "inc/LinkedList.h"
#include "inc/Common_Func.h"
#include "inc/String.h"

typedef struct stack
{
   uint8_t capacity;
   uint8_t *item;
}Stack;

typedef Stack *p_stack;

p_stack stackInit(p_stack Stack)
{
   Stack->item = (malloc(sizeof(Stack)));
   
}
// MAIN
int main(int argc, char *argv[]) 
{
   pList_t list_1;

   uint8_t size = 10;

   list_1 = createNewNode(&list_1, 1);
   insertWithUser(&list_1, size);

   displayLinkedList(list_1);
   return 0;
}



 
