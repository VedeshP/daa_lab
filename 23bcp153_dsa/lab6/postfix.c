// Also always follow alphabetical order
#include <ctype.h>
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
int isFull(Stack *s);
char pop(Stack *s);
void push(Stack *s, int value);
char peek(Stack *s);
void removeSpaces(const char *input, char *output);
void infixToPostfix(char *infix, char *postfix);
int precedence(char ch);
int isOperator(char ch);

int main(void)
{
    char inputstr[100];
    char infix[100];
    char postfix[100];
    printf("Enter Your Operation String: ");
    fgets(inputstr, sizeof(inputstr), stdin);
    removeSpaces(inputstr, infix);
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }
    infixToPostfix(infix, postfix);

    printf("Your Postfix Expression:-\n%s", postfix);
   
    return 0;
}

Stack *createStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = n;
    s->top = -1;
    s->array = (char *)malloc(s->capacity * sizeof(int));
    return s;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        // Underflow
        printf("Stack is Empty\n");
        return '\0';
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

void removeSpaces(const char *input, char *output) 
{
    // Index for output string
    int j = 0; 
    for (int i = 0; input[i] != '\0'; i++) 
    {
        if (input[i] != ' ') 
        { 
            output[j++] = input[i];
        }
    }
    // Null terminating o/p string
    output[j] = '\0';
}

void infixToPostfix(char *infix, char *postfix)
{
    int strlength = strlen(infix);
    // printf("%d\n", strlength);
    // printf("%s", infix);
    Stack *mystack = createStack(strlength);

    int i, j = 0;

    push(mystack, '(');
    // Double quotes here in strcat are necessary becasue function takes string type argument only 
    strcat(infix, ")"); 

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        else if (ch == '(')
        {
            push(mystack, ch);
        }

        else if (isOperator(ch))
        {
            while (isOperator(peek(mystack)) && precedence(peek(mystack)) >= precedence(ch))
            {
                postfix[j++] = pop(mystack);
            }
            push(mystack, ch);
        }

        else if (ch == ')')
        {
            while (peek(mystack) != '(')
            {
                postfix[j++] = pop(mystack);
            }
            // Then pop '('
            pop(mystack);
        }
    }

    postfix[j] = '\0';

    free(mystack->array);
    free(mystack);
}

char peek(Stack *s)
{
    if (isEmpty(s)) 
    {
        return '\0';
    }
    return s->array[s->top];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }

    if (ch == '*' || ch == '/')
    {
        return 2;
    }

    if (ch == '^')
    {
        return 3;
    }

    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}