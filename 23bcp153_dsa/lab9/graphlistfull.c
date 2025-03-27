#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeNode {
    int dest;
    struct EdgeNode* next;
} EdgeNode;

typedef struct GraphNode {
    int info;
    EdgeNode* adjlist;
    struct GraphNode* next;
} GraphNode;

GraphNode* createGnode(int info);
EdgeNode* createEnode(int dest);
void addvertex(GraphNode* start, int info);
void addEdge(GraphNode* start, int src, EdgeNode* node);
void printneighbor(GraphNode* start, int src);

int main(void)
{
    int vertex = 0;
    GraphNode* start = NULL;
    printf("Enter first vertex: ");
    scanf("%d", &vertex);
    if (vertex != -1) 
    {
        start = createGnode(vertex);
    }
    if (start)
    {
        while (vertex != -1)
        {
            printf("Enter vertex: ");
            scanf("%d", &vertex);
            if (vertex != -1)
            {
                addvertex(start, vertex);
            }
        }
        int mysrc = 0;
        int mydest = 0;
        EdgeNode* node;
        while (mysrc != -1)
        {
            printf("Enter Source: ");
            scanf("%d", &mysrc);
            mydest = 0;
            while (mydest != -1)
            {
                printf("Enter Destination: ");
                scanf("%d", &mydest);
                if (mydest != -1)
                {
                    node = createEnode(mydest);
                    addEdge(start, mysrc, node);
                }
            }
        }

        printneighbor(start, 1);
        printneighbor(start, 2);
        printneighbor(start, 3);
        printneighbor(start, 4);
    }

    return 0;
}

EdgeNode* createEnode(int dest)
{
    EdgeNode* node = (EdgeNode *)malloc(sizeof(EdgeNode));
    node->dest = dest;
    node->next = NULL;

    return node;
}

GraphNode* createGnode(int info)
{
    GraphNode* node = (GraphNode *)malloc(sizeof(GraphNode));
    node->info = info;
    node->adjlist = NULL;
    node->next = NULL;

    return node;
}

void addvertex(GraphNode* start, int info)
{
    GraphNode* node = createGnode(info);
    GraphNode* current = start;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = node;

    return;
}

void addEdge(GraphNode* start, int src, EdgeNode* node)
{
    GraphNode* current = start;
    while (current != NULL && current->info != src)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        node->next = current->adjlist;
        current->adjlist = node;
    }

    return;
}

void printneighbor(GraphNode* start, int src)
{
    GraphNode* current = start;
    EdgeNode* temp;
    while (current != NULL && current->info != src)
    {
        current = current->next;
    }
    
    if (current != NULL)
    {
        printf("Adjacent edges for %d: ", src);
        temp = current->adjlist;
        while (temp != NULL)    
        {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
    else 
    {
        printf("Not found\n");
        return;
    }
}