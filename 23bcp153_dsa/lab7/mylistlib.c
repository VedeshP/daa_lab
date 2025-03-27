// mylistlib.c
#include <stdio.h>
#include <stdlib.h>

#include "mylistlib.h"

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
        printf("removed %d from memory\t", current->info);
        free(node);
    }

    return;
}

List *deletebeg(List *start)
{
    if (start == NULL)
    {
        printf("List is Empty\n");
        return start;
    }
    // To Avoid Memory Leaks my friend
    List *temp = start;
    start = start->link;
    free(temp);
    return start;
}

List *deletenode(List *start, int info)
{
    if (start == NULL)
    {
        printf("List is Empty\n");
        return start;
    }
    List *current = start;

    if (current->info == info)
    {
        start = current->link;
        free(current);
        return start;
    }

    while (current->link->info != info && current->link != NULL)
    {
        current = current->link;
    }

    if (current->link == NULL)
    {
        printf("Node with value %d was not found!\n", info);
        return start;
    }

    List *temp = current->link;
    // Bypassing the node
    current->link = current->link->link;
    free(temp);

    return start;
}

List *deleteend(List *start)
{
    // If only one node 
    if (start->link == NULL)
    {
        free(start);
        return NULL;
    }

    List *current = start;

    while (current->link->link != NULL)
    {
        current = current->link;
    }
    // Freeing last node my friend - prevent memory leaks
    // always check for memory leaks
    free(current->link);
    current->link = NULL;

    return start;
}