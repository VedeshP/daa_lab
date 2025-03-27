#include <stdio.h>
#include <stdlib.h>

// root left right - Preorder

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
void printPreorder(Tree *root);
void freetree(Tree *root);
void printPreorderiter(Tree *root);
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

    printf("Preorder:\n");
    printPreorder(A);
    printf("\n");
    printPreorderiter(A);
    freetree(A);
    
    return 0;
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