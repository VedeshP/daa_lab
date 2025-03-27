#include <stdio.h>
#include <stdlib.h>

// left right root - Postorder

typedef struct Tree {
    int info;
    struct Tree *left;
    struct Tree *right;
} Tree;

typedef struct Stacktree 
{
    int top;
    int capacity;
    Tree **array;
} Stacktree;

Tree *makeTnode(int info);
void printPostorder(Tree *root);
void freetree(Tree *root);
void printPostorderiter(Tree *root);
Stacktree *createStackt(int n);
Tree *popt(Stacktree *s);
void pusht(Stacktree *s, Tree *node);
int isFullt(Stacktree *s);
int isEmptyt(Stacktree *s);
Tree *peekt(Stacktree *s);

int main(void)
{
    Tree *A = makeTnode(1);
    Tree *B = makeTnode(2);
    Tree *C = makeTnode(3);
    Tree *D = makeTnode(4);
    Tree *E = makeTnode(5);
    Tree *F = makeTnode(6);
    Tree *G = makeTnode(7);
    Tree *H = makeTnode(8);
    Tree *I = makeTnode(9);
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    D->left = G;
    D->right = H;
    G->left = I;

    printf("Postrder:\n");

    printPostorder(A);
    printf("\n");
    printf("Postorder Traversal Iterative:\n");
    printPostorderiter(A);
    printf("\n");
    freetree(A);
    
    return 0;
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

// Make these below type of dynamic functions later

// Tree *insert()
// {

// }

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