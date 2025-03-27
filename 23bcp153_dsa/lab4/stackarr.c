#include <stdio.h>
#include <stdbool.h>

bool isEmpty();
bool isFull(int n);
void insert(int arr[], int ele);
void delete(int arr[]);
void printStack(int arr[]);
void printTop(int arr[]);
int top = -1;


int main(void)
{
    int n;
    printf("What is the Maximum number of elements you want in your stack: ");
    scanf("%d", &n);

    int arr[n]; 
    int ele;

    while(true)
    {
        int operation;
        printf("Press 1 to insert\nPress 2 to delete\nPress 3 to Print top element\nPress 0 to stop the program\n");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            printf("Enter the element to insert in the stack: ");
            scanf("%d", &ele);

            insert(arr, ele);
            break;
        case 2:
            delete(arr);
            break;
        case 3:
            printTop(arr);
            break;
        default:
            return 0;
            break;
        }
        
    }

    return 0;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool isFull(int n)
{
    if (top == n - 1)
    {
        return true;
    }

    return false;
}

void insert(int arr[], int ele)
{
    if (isFull(top))
    {
        printf("Array is Full!\n");
        printStack(arr);
        
        return;
    }

    top++;

    arr[top] = ele;
    printStack(arr);

    return;
}

void delete(int arr[])
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }

    int popped = arr[top];
    top--;
    printf("Popped value: %d\n", popped);
    printStack(arr);
    return;
}

void printStack(int arr[])
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return; 
}

void printTop(int arr[])
{
    printf("Top Element: %d\n", arr[top]);
}