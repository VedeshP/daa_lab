#include <stdio.h>
#include <stdlib.h>

#include "mylistlib.h"

List *insertbegcircthis(List *start, int info);
List *insertendcircthis(List *start, int info);
void printlistcircthis(List *start);
void freelistcircthis(List *start);

int main(void)
{
    List *start = NULL;

    start = insertbegcircthis(start, 10);
    printlistcircthis(start);
    start = insertendcircthis(start, 30);
    printlistcircthis(start);
    start = insertendcircthis(start, 20);
    printlistcircthis(start);
    start = insertbegcircthis(start, 45);
    printlistcircthis(start);

    freelistcircthis(start);

    return 0;
}

List *insertbegcircthis(List *start, int info)
{
    List *node = (List *)malloc(sizeof(List));
    if (node == NULL)
    {
        printf("Unable to allocate memory for new node\n");
        return start;
    }

    node->info = info;

    if (start == NULL)
    {
        node->link = node;
        return node;
    }

    List *current = start;
    while (current->link != start)
    {
        current = current->link;
    }

    current->link = node;
    node->link = start;

    return node;
}

List *insertendcircthis(List *start, int info)
{
    List *node = (List *)malloc(sizeof(List));
    if (node == NULL)
    {
        printf("Unable to allocate memory for new node\n");
        return start;
    }

    node->info = info;

    if (start == NULL)
    {
        node->link = node;
        return node;
    }    
    
    List *current = start;
    while (current->link != start)
    {
        current = current->link;
    }

    current->link = node;
    node->link = start;

    return start;

}

void printlistcircthis(List *start)
{
    if (start == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }

    List *current = start;

    do 
    {
        printf("%d->", current->info);
        current = current->link;
    }
    while (current != start);

    printf("(back to %d)\n", start->info);
}

void freelistcircthis(List *start)
{
    if (start == NULL)
    {
        return;
    }

    List *current = start;
    List *node;

    do 
    {
        node = current->link;
        printf("Removing %d from memory\t", current->info);
        free(current);
        current = node;
    }
    while (current != start);

    return;
}

