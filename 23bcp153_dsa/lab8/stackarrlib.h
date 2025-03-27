#ifndef STACKARRLIB_H
#define STACKARRLIB_H

typedef struct Stack 
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack *createStack(int n);
char pop(Stack *s);
void push(Stack *s, int value);
int isFull(Stack *s);
int isEmpty(Stack *s);
int peek(Stack *s);

#endif