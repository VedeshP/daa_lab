#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    int capacity;
    char *array;
} Stack;

Stack *createStack(int n);
int isEmpty(Stack *s);
void push(Stack *s, char value);
char pop(Stack *s);
char peek(Stack *s);
int isMatchingPair(char left, char right);
int isBalanced(char *exp);

int main(void)
{
    char exp[100];
    
    printf("Enter expression: ");
    fgets(exp, sizeof(exp), stdin);
    
    size_t len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') 
    {
        exp[len - 1] = '\0'; 
    }

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}

Stack *createStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = n;
    s->top = -1;
    s->array = (char *)malloc(s->capacity * sizeof(char));
    return s;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char value)
{
    s->array[++s->top] = value;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->array[s->top--];
}

char peek(Stack *s)
{
    if (isEmpty(s)) 
    {
        return '\0';
    }
    return s->array[s->top];
}

int isMatchingPair(char left, char right)
{
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

int isBalanced(char *exp)
{
    int n = strlen(exp);
    Stack *stack = createStack(n);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty(stack) || !isMatchingPair(pop(stack), ch))
            {
                free(stack->array);
                free(stack);
                return 0; // Not Balanced
            }
        }
    }

    int balanced = isEmpty(stack);
    free(stack->array);
    free(stack);
    return balanced;
}
