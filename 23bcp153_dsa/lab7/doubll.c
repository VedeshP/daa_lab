#include <stdio.h>
#include <stdlib.h>

typedef struct DoubListthis {
    int info;
    struct DoubListthis *prev;
    struct DoubListthis *next;
} DoubListthis;

DoubListthis *insertendDoubthis(DoubListthis *start, int info);
DoubListthis *deletebegDoubthis(DoubListthis *start);
void printlistDoubthis(DoubListthis *start);

int main(void)
{
    DoubListthis *start = NULL;

    start = insertendDoubthis(start, 45);
    printlistDoubthis(start);
    start = insertendDoubthis(start, 63);
    printlistDoubthis(start);
    start = insertendDoubthis(start, 81);
    printlistDoubthis(start);
    start = insertendDoubthis(start, 90);
    printlistDoubthis(start);
    start = deletebegDoubthis(start);
    printlistDoubthis(start);
    start = deletebegDoubthis(start);
    printlistDoubthis(start);
    start = deletebegDoubthis(start);
    printlistDoubthis(start);

    return 0;
}

DoubListthis *insertendDoubthis(DoubListthis *start, int info)
{
    DoubListthis *node = (DoubListthis *)malloc(sizeof(DoubListthis));
    if (node == NULL)
    {
        printf("Unable to allocate memory for new node\n");
        return start;
    }

    node->info = info;
    node->prev = NULL;
    node->next = NULL;

    if (start == NULL)
    {
        return node;
    }

    DoubListthis *current = start;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
    node->prev = current;

    return start;
}

DoubListthis *deletebegDoubthis(DoubListthis *start)
{
    if (start == NULL)
    {
        printf("List is Empty\n");
        return start;
    }

    DoubListthis *temp = start;

    if (start->next == NULL)
    {
        free(start);
        return NULL;
    }

    start = start->next;
    start->prev = NULL;

    free(temp);

    return start;
}

void printlistDoubthis(DoubListthis *start)
{
    DoubListthis *current = start;

    while (current != NULL)
    {
        printf("%d", current->info);
        current = current->next;
        if (current != NULL)
        {
            printf("<->");
        }
    }

    printf("\n");
}
