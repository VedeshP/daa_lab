// status array 

// status 
// 1- ready 
// 2- waiting 
// 3 - processed

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

// int adj[MAX][MAX];
// int status[MAX];
int status[9];

bool isEmpty();
bool isFull();
void enqueue(int ele);
int dequeue();
void printQueue();

void bfs(int start, int n, int adj[9][9]);

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

    bfs(0, 9, adj);

    return 0;
}

void bfs(int start, int n, int adj[9][9])
{
    printf("BFS Traversal: ");

    enqueue(start);
    status[start] = 2;

    while (!isEmpty())
    {
        int v = dequeue();
        printf("%d ", v);
        status[v] = 3;

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && status[i] == 1)
            {
                enqueue(i);
                status[i] = 2; 
            }
        }
    }
    printf("\n");
    
}

bool isEmpty()
{
    return (front == -1);
}

bool isFull()
{
    return ((rear + 1) % MAX == front);
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
        rear = (rear + 1) % MAX;
    }
    queue[rear] = ele;
    // printf("Inserted: %d\n", ele);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is EMPTY!\n");
        return -1;
    }

    int dequeued = queue[front];
    // printf("Deleted: %d\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else 
    {
        front = (front + 1) % MAX;
    }

    return dequeued;
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
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}