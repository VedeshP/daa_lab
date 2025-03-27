#include <stdio.h>
#include <stdlib.h>

#include "mylistlib.h"
// compile command:
// gcc deletelist.c mylistlib.c -o deletelist

List *deletebegthis(List *start);
List *deletenodethis(List *start, int info);
List *deleteendthis(List *start);

int main(void)
{
    List *start = NULL;

    start = insertbeg(start, 10);
    start = insertbeg(start, 20);
    start = insertbeg(start, 30);
    start = insertafter(start, 20, 12);
    start = insertend(start, 45);
    start = insertend(start, 72);
    printlist(start);

    start = deletebegthis(start);
    printlist(start);
    start = deletenodethis(start, 45);
    printlist(start);

    start = deleteendthis(start);

    printlist(start);

    start = deleteend(start);

    printlist(start);

    freelist(start);

    return 0;
}

List *deletebegthis(List *start)
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

List *deletenodethis(List *start, int info)
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

List *deleteendthis(List *start)
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