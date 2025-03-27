#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack *createStack(int n);
int isEmpty(Stack *s);
int isFull(Stack *s);
int pop(Stack *s);
void push(Stack *s, int value);
int evaluatePostfix(char *postfix);
int performOperation(int a, int b, char op);

int main(void)
{
    char postfix[100];
    printf("Enter Postfix Expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    
    size_t len = strlen(postfix);
    if (len > 0 && postfix[len - 1] == '\n') 
    {
        postfix[len - 1] = '\0';
    }

    int result = evaluatePostfix(postfix);
    printf("The result is: %d\n", result);

    return 0;
}

Stack *createStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = n;
    s->top = -1;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    return s;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == s->capacity - 1;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->array[s->top--];
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->array[++s->top] = value;
}

int evaluatePostfix(char *postfix)
{
    int strlength = strlen(postfix);
    Stack *mystack = createStack(strlength);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            push(mystack, ch - '0'); 
            // value of 0 in ASCII is 48
        }
        else if (ch == ' ')
        {
            continue;
        }
        else
        {
            int val2 = pop(mystack);
            int val1 = pop(mystack);
            int result = performOperation(val1, val2, ch);
            push(mystack, result);
        }
    }

    int finalResult = pop(mystack);
    free(mystack->array);
    free(mystack);

    return finalResult;
}

int performOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        printf("Invalid operator encountered: %c\n", op);
        return 0;
    }
}
