#ifndef MYTREELIB_H
#define MYTREELIB_H

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
void freetree(Tree *root);
void printInorder(Tree *root);
void printPreorder(Tree *root);
void printPostorder(Tree *root);
void printInorderiter(Tree *root);

// Stack functions holding tree node
Stacktree *createStackt(int n);
Tree *popt(Stacktree *s);
void pusht(Stacktree *s, Tree *node);
int isFullt(Stacktree *s);
int isEmptyt(Stacktree *s);
Tree *peekt(Stacktree *s);

#endif