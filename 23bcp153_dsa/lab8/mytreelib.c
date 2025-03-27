#include <stdio.h>
#include <stdlib.h>

#include "mytreelib.h"

Tree *makeTnode(int info)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    if (node == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }
    node->info = info;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void freetree(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    freetree(root->left);
    freetree(root->right);
    free(root);
}

// Implementation of recursive order traversal algorithms

void printInorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->info);
    printInorder(root->right);
}

void printPreorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->info);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->info);
}

// Implementation of iterative order traversal algorithms

void printInorderiter(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    Stacktree *mystack = createStackt(9);
    Tree *current = root;
    printf("Inorder Traversal iterative:\n");
    while (current != NULL || !isEmptyt(mystack))
    {
        while (current != NULL)
        {
            pusht(mystack, current);
            current = current->left;
        }

        current = popt(mystack);
        printf("%d ", current->info);
        current = current->right;
    }


    free(mystack->array);
    free(mystack);
}

void printPreorderiter(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    
    Stacktree *mystack = createStackt(9);
    Tree *current = root;
    printf("Preorder Traversal Iterative:\n");
    pusht(mystack, root);
    while (!isEmptyt(mystack))
    {
        Tree *current = popt(mystack);

        printf("%d ", current->info);

        if (current->right != NULL)
        {
            pusht(mystack, current->right);
        }
        if (current->left != NULL)
        {
            pusht(mystack, current->left);
        }
    }
    printf("\n");

    free(mystack->array);
    free(mystack);
}

void printPostorderiter(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    Stacktree *mainstack = createStackt(9);
    Stacktree *outputstack = createStackt(9);

    pusht(mainstack, root);

    while (!isEmptyt(mainstack))
    {
        Tree *current = popt(mainstack);
        pusht(outputstack, current);

        if (current->left != NULL)
        {
            pusht(mainstack, current->left);
        }
        if (current->right != NULL)
        {
            pusht(mainstack, current->right);
        }
    }

    while (!isEmptyt(outputstack))
    {
        Tree *current = popt(outputstack);
        printf("%d ", current->info);
    }

    free(mainstack->array);
    free(mainstack);
    free(outputstack->array);
    free(outputstack);
}

// Implementaion of Stack that holds tree nodes

Stacktree *createStackt(int n)
{
    Stacktree *s = (Stacktree *)malloc(sizeof(Stacktree));
    s->capacity = n;
    s->top = -1;
    s->array = (Tree **)malloc(s->capacity * sizeof(Tree *));
    return s;
}

Tree *popt(Stacktree *s)
{
    if (isEmptyt(s))
    {
        // Underflow
        printf("Stack is Empty\n");
        return NULL;
    }
    Tree *popped = s->array[s->top];
    s->top--;
    return popped;
}

void pusht(Stacktree *s, Tree *node)
{
    // Overflow (as we do in algo in class)
    if (isFullt(s))
    {
        printf("Stack is Full!\n");
        return;
    }

    s->top++;
    s->array[s->top] = node;
    return;
}

int isFullt(Stacktree *s)
{
    return s->top == s->capacity - 1;
}

int isEmptyt(Stacktree *s)
{
    return s->top == -1;
}

Tree *peekt(Stacktree *s)
{
    if (isEmptyt(s)) 
    {
        return NULL;
    }

    return s->array[s->top];
}