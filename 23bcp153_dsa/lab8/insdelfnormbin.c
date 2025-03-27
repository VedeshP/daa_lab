#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node *data;
    struct Queue *next;
} Queue;

Queue *createQueue(Node *data) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = data;
    q->next = NULL;
    return q;
}

// Add a node to the queue
void enqueue(Queue **front, Queue **rear, Node *data) {
    Queue *newNode = createQueue(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

// Remove a node from the queue
Node *dequeue(Queue **front) {
    if (*front == NULL) return NULL;

    Queue *temp = *front;
    *front = (*front)->next;
    Node *node = temp->data;
    free(temp);

    return node;
}

int isQueueEmpty(Queue *front) {
    return front == NULL;
}

// Create a new tree node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into binary tree level-wise
void insertBT(Node **root, int data) {
    Node *newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, *root);

    while (!isQueueEmpty(front)) {
        Node *temp = dequeue(&front);

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->right);
        }
    }
}

// Search in Binary Tree
int searchBT(Node *root, int key) {
    if (root == NULL) return 0;

    if (root->data == key)
        return 1;

    return searchBT(root->left, key) || searchBT(root->right, key);
}

// Delete in Binary Tree
void deleteBT(Node **root, int key) {
    if (*root == NULL) return;

    Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, *root);

    Node *keyNode = NULL, *temp = NULL;

    while (!isQueueEmpty(front)) {
        temp = dequeue(&front);

        if (temp->data == key)
            keyNode = temp;

        if (temp->left)
            enqueue(&front, &rear, temp->left);
        if (temp->right)
            enqueue(&front, &rear, temp->right);
    }

    if (keyNode != NULL) {
        int x = temp->data;
        free(temp);
        keyNode->data = x;
    }
}

// Inorder traversal
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    insertBT(&root, 1);
    insertBT(&root, 2);
    insertBT(&root, 3);
    insertBT(&root, 4);
    insertBT(&root, 5);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Deleting node 3\n");
    deleteBT(&root, 3);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    if (searchBT(root, 4))
        printf("Element 4 found\n");
    else
        printf("Element 4 not found\n");

    return 0;
}
