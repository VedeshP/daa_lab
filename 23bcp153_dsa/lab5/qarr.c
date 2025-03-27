#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

bool isEmpty();
bool isFull();
void enqueue(int ele);
void dequeue();
void printQueue();

int main(void)
{
    printQueue();
    enqueue(18);
    enqueue(27);
    enqueue(36);
    enqueue(45);
    printQueue();
    enqueue(54);
    enqueue(63);
    enqueue(72);
    enqueue(81);
    enqueue(90);
    enqueue(99);
    enqueue(99);
    printQueue();
    dequeue();
    dequeue();
    dequeue();
    printQueue();
    enqueue(999);
    enqueue(153);
    // Roll no. above
    printQueue();

    return 0;
}

bool isEmpty()
{
    return (front == -1);
}

bool isFull()
{
    return ((rear + 1) % SIZE == front);
}

void enqueue(int ele)
{
    if (isFull())
    {
        printf("Queue is FULL!\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else 
    {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = ele;
    printf("Inserted: %d\n", ele);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else 
    {
        front = (front + 1) % SIZE;
    }
}

void printQueue()
{
    if (isEmpty())
    {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue[rear]);
}