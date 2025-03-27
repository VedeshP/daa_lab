#include <stdio.h>
#include <stdlib.h>

#include "mylistlib.h"

List *mergeSortedlist(List *A, List *B);

int main(void)
{
    List *A = NULL;

    List *B = NULL;

    A = insertend(A, 5);
    A = insertend(A, 10);
    A = insertend(A, 15);

    B = insertend(B, 2);
    B = insertend(B, 3);
    B = insertend(B, 20);

    printlist(A);
    printlist(B);
    
    List *merged = NULL;

    merged = mergeSortedlist(A, B);

    printlist(merged);

    freelist(merged);
    freelist(A);
    freelist(B);

    return 0;
}

List *mergeSortedlist(List *A, List *B)
{
    if (A == NULL)
    {
        return B;
    }

    if (B == NULL)
    {
        return A;
    }

    List *dummy = (List *)malloc(sizeof(List));
    if (dummy == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    dummy->link = NULL;
    List *current = dummy;

    while (A != NULL && B != NULL)
    {
        if (A->info <= B->info)
        {
            current->link = A;
            A = A->link;
        }
        else
        {
            current->link = B;
            B = B->link;
        }

        current = current->link;
    }

    if (A != NULL)
    {
        current->link = A;
    }

    if (B != NULL)
    {
        current->link = B;
    }
    
    List *merged = dummy->link;
    free(dummy);

    return merged;
}