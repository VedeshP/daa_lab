#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// stack functions are included in stackarrlib.c/.h

#define MAX 10

typedef struct Stack 
{
    int top;
    int capacity;
    int *array;
} Stack;


void dfs(int start, int n, int adj[9][9]);

// int adj[MAX][MAX];
// int status[MAX];

int status[9];

Stack *createStack(int n);
char pop(Stack *s);
void push(Stack *s, int value);
int isFull(Stack *s);
int isEmpty(Stack *s);
int peek(Stack *s);

int main(void)
{
    int adj[9][9] = {
        {0,1,1,1,0,0,0,0,0},
        {1,0,1,0,1,0,0,0,0},
        {1,1,0,1,1,1,1,0,0},
        {1,0,1,0,0,0,1,0,0},
        {0,1,1,0,0,0,0,0,1},
        {0,0,1,0,0,0,1,1,1},
        {0,0,1,1,0,1,0,1,0},
        {0,0,0,0,0,1,1,0,1},
        {0,0,0,0,1,1,0,1,0}
    };

    for (int i = 0; i < 9; i++)
    {
        status[i] = 1;
    }

    dfs(0, 9, adj);
    
    return 0;
}

void dfs(int start, int n, int adj[9][9])
{
    Stack *mystack = createStack(9);

    printf("DFS Traversal: ");
    push(mystack, start);
    status[start] = 2;

    while(!isEmpty(mystack))
    {
        int v = pop(mystack);
        printf("%d ", v);
        status[v] = 3;

        for (int i = n - 1; i >= 0; i--)
        {
            if (adj[v][i] == 1 && status[i] == 1)
            {
                push(mystack, i);
                status[i] = 2;
            }
        }
    }
    printf("\n");
}

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