#include <stdio.h>
#include <stdlib.h>

// left root right - inorder

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
void printInorder(Tree *root);
void freetree(Tree *root);
void printInorderiter(Tree *root);
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

    printf("Inorder:\n");
    printInorder(A);
    printf("\n");
    printInorderiter(A);
    freetree(A);
    
    return 0;
}

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

void printInorderiter(Tree *root)
{
    // use array based stack here for simplicity - remove this comment - don't use libraires - straight away ds and implementation
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