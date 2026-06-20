#ifndef STACK_H
#define STACK_H

#include "main.h"

#define MAX_CAPACITY 255
typedef struct stack
{
   uint8_t capacity;
   uint8_t *item;
}Stack;

typedef Stack *p_stack;

p_stack stackInit(p_stack Stack, uint8_t capacity);
p_stack push(p_stack Stack, uint8_t data);
p_stack pop(p_stack Stack, uint8_t *data);
p_stack peek(p_stack Stack, uint8_t *data);
p_stack stackFree(p_stack Stack);
p_stack stackIsFull(p_stack Stack);
p_stack stackIsEmpty(p_stack Stack);
p_stack stackGetCapacity(p_stack Stack);
p_stack printStack(p_stack Stack);

#endif