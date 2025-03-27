#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert an element into BST
Node *insertBST(Node *root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);

    return root;
}

// Search an element in BST
Node *searchBST(Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

// Delete an element from BST
Node *deleteBST(Node *root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteBST(root->left, key);
    else if (key > root->data)
        root->right = deleteBST(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

// Inorder traversal (sorted order for BST)
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 70);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 60);
    insertBST(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Deleting 20\n");
    root = deleteBST(root, 20);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    Node *found = searchBST(root, 40);
    if (found) printf("Element 40 found\n");
    else printf("Element 40 not found\n");

    return 0;
}
