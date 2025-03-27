#include <stdlib.h>

#include "stackarrlib.h"

// Always Free your stack in the function you use it or at the end of your program
// Here is how you can free it 
// free(mystack->array);
// free(mystack);

Stack *createStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = n;
    s->top = -1;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    return s;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        // Underflow
        printf("Stack is Empty\n");
        return -1;
    }
    char popped = s->array[s->top];
    s->top--;
    return popped;
}

void push(Stack *s, int value)
{
    // Overflow (as we do in algo in class)
    if (isFull(s))
    {
        printf("Stack is Full!\n");
        return;
    }

    s->top++;
    s->array[s->top] = value;
    return;
}

int isFull(Stack *s)
{
    return s->top == s->capacity - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int peek(Stack *s)
{
    if (isEmpty(s)) 
    {
        return -1;
    }
    return s->array[s->top];
}