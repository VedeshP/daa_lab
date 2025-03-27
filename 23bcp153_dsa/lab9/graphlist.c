#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeNode {
    int dest;
    struct EdgeNode* next;
} EdgeNode;

typedef struct GraphNode {
    int node;
    EdgeNode* adjList;
    struct GraphNode* next;
} GraphNode;

EdgeNode* createEdgeNode(int dest) ;
GraphNode* createGraphNode(int node);
void addEdge(GraphNode *graph, int src, int dest);
void printGraph(GraphNode *graph);

int main(void) 
{

    GraphNode *graph = createGraphNode(1);
    graph->next = createGraphNode(2);
    graph->next->next = createGraphNode(3);
    graph->next->next->next = createGraphNode(4);


    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 3);


    printf("Graph adjacency list representation:\n");
    printGraph(graph);

    return 0;
}

EdgeNode* createEdgeNode(int dest) 
{
    EdgeNode *newEdgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
    newEdgeNode->dest = dest;
    newEdgeNode->next = NULL;
    
    return newEdgeNode;
}

GraphNode* createGraphNode(int node) 
{
    GraphNode *newGraphNode = (GraphNode *)malloc(sizeof(GraphNode));
    newGraphNode->node = node;
    newGraphNode->adjList = NULL;
    newGraphNode->next = NULL;
    
    return newGraphNode;
}

void addEdge(GraphNode *graph, int src, int dest) 
{
    GraphNode *temp = graph;
    
    while (temp != NULL && temp->node != src) 
    {
        temp = temp->next;
    }
    
    if (temp != NULL) 
    {
        EdgeNode *newEdge = createEdgeNode(dest);
        newEdge->next = temp->adjList;
        temp->adjList = newEdge;
    }
}

void printGraph(GraphNode *graph) 
{
    GraphNode *tempNode = graph;
    while (tempNode != NULL) 
    {
        printf("%d -> ", tempNode->node);
        EdgeNode *tempEdge = tempNode->adjList;
        
        while (tempEdge != NULL) 
        {
            printf("%d -> ", tempEdge->dest);
            tempEdge = tempEdge->next;
        }
        printf("NULL\n");
        tempNode = tempNode->next;
    }
}

