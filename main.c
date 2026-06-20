#include "LinkedList.h"
#include "Common_Func.h"
#include "String.h"
#include "Stack.h"


mystack myStack;

// MAIN
int main(int argc, char *argv[]) 
{
   // Force both standard out and standard error to print instantly
    setvbuf(stdout, NULL, _IONBF, 0); 
    setvbuf(stderr, NULL, _IONBF, 0); // <--- ADD THIS LINE

   uint8_t size = 5;
   uint8_t data_pop = 0;
   myStack = stackInit(myStack, size);
   for(uint8_t i = 0; i < size; i++)
   {
      myStack = push(myStack, i);
   }
   myStack = push(myStack, 100);
   printStack(myStack);
   myStack = pop(myStack, &data_pop);
   printStack(myStack);
   return 0; 
}
