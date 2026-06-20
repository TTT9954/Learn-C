#ifndef STACK_H
#define STACK_H

#include "main.h"

#define MAX_CAPACITY 255
typedef struct stack
{
   uint8_t size;
   uint8_t capacity;
   uint8_t *item;
}Stack;

typedef Stack *mystack;

mystack stackInit(mystack Stack, uint8_t size);
mystack push(mystack Stack, uint8_t data);
mystack pop(mystack Stack, uint8_t *data);
mystack peek(mystack Stack, uint8_t *data);
mystack stackFree(mystack Stack);
bool stackIsFull(mystack  Stack);
bool stackIsEmpty(mystack Stack);
uint8_t stackGetCapacity(mystack Stack);
mystack printStack(mystack Stack);

#endif