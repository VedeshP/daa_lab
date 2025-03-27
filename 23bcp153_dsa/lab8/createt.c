#include <stdio.h>
#include <stdlib.h>

#include "mytreelib.h"

Tree *createtreethis();

int main(void)
{
    printf("Creation of tree test\n");

    Tree *A = makeTnode(1);
    A->left = createtreethis(A->left);
    A->right = createtreethis(A->right);

    printInorder(A);

    freetree(A);

    return 0;
}

Tree *createtreethis()
{
    int info = 0;
    printf("Enter Data to add in Node: ");
    scanf("%d", &info);

    if (info == -1)
    {
        return NULL;
    }

    Tree *current = makeTnode(info);
    printf("Creating left child of %d\n", current->info);
    current->left = createtreethis();
    printf("Creating right child of %d\n", current->info);
    current->right = createtreethis();

    return current;
}