#include <stdio.h>
#include <stdlib.h>

typedef struct List 
{
    int info;
    struct List *link;
} List;

List *insertbeg(List *start, int info);
void printlist(List *start);
List *insertafter(List *start, int previnfo, int info);
List *insertend(List *start, int info);
void freelist(List *start);

int main(void)
{

    List *start = NULL;

    start = insertbeg(start, 10);
    printlist(start);
    start = insertbeg(start, 20);
    printlist(start);
    start = insertbeg(start, 30);
    printlist(start);
    start = insertafter(start, 20, 12);
    printlist(start);
    start = insertend(start, 45);
    printlist(start);
    start = insertend(start, 72);

    printlist(start);

    freelist(start);
    return 0;
}

List *insertbeg(List *start, int info)
{
    List *node = (List *)malloc(sizeof(List));
    
    if (node == NULL)
    {
        printf("Unable to allocate memory for new node\n");
        return start;
    }

    node->info = info;
    node->link = start;
    return node;
}

List *insertafter(List *start, int previnfo, int info)
{
    List *node = (List *)malloc(sizeof(List));
    if (node == NULL)
    {
        printf("Unable to allocate memory for new node\n");
        return start;
    }
    List *current = start;

    while (current->info != previnfo && current != NULL)
    {
        current = current->link;
    }
    if (current->info == previnfo)
    {
        node->info = info;
        node->link = current->link;
        current->link = node;
    }
    else 
    {
        printf("Node with value %d not found!\n", previnfo);
        return start;
    }

    return start;
}

List *insertend(List *start, int info)
{
    List *current = start;
    List *node = (List *)malloc(sizeof(List));
    if (node == NULL)
    {
        printf("Unable to allocate memory for new node\n");
        return start;
    }

    node->info = info;
    node->link = NULL;

    if (start == NULL)
    {
        return node;
    }

    while (current->link != NULL)
    {
        current = current->link;
    }

    current->link = node;

    return start;
}

void printlist(List *start)
{
    while (start != NULL)
    {
        printf("%d", start->info);
        start = start->link;

        if (start != NULL)
        {
            printf("->");
        }

    }
    printf("->NULL\n");
}

void freelist(List *start)
{
    List *current = start;

    if (start == NULL)
    {
        return;
    }

    while (current != NULL)
    {
        List *node = current;
        current = current->link;
        // printf("removed %d from memory\t", current->info);
        free(node);
    }

    return;
}