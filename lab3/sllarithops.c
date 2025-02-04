#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    int size;
    struct Node *next;
} Node;

Node *create_node(int data);
Node* create_num_list(int num);
void printlist(Node *head);
Node* add_padding(Node *head, int padding);
Node* lladd(Node *head1, Node *head2, int carry);
Node* lladditer(Node* head1, Node* head2, int carry);
Node* llsubiter(Node* head1, Node* head2, int borrow);
Node* llmuliter(Node* head1, Node* head2, int carry);
Node* add_padding_back(Node* head, int padding);
Node* llexpiter(Node* head, int power);

int main (void)
{
    int num1;
    int num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    Node* head1 = create_num_list(num1);
    Node* head2 = create_num_list(num2);

    printf("The first number is: ");
    printlist(head1);
    printf("num size: %d\n", head1->size);
    printf("The second number is: ");
    printlist(head2);
    printf("num size: %d\n", head2->size);

    // add back padding to the smaller number
    // head1 = add_padding_back(head1, 5);
    // printlist(head1);

    // if (head1->size > head2->size)
    // {
    //     head2 = add_padding(head2, head1->size - head2->size);
    // }
    // else if (head2->size > head1->size)
    // {
    //     head1 = add_padding(head1, head2->size - head1->size);
    // }

    // now add extra padding to both in case we have a case like this 999 + 999
    // head1 = add_padding(head1, 1);
    // head2 = add_padding(head2, 1);
    printlist(head1);
    printlist(head2);

    // failing at 999 + 999

    if (head1 == NULL)
    {
        printlist(head2);
        return 0;
    }
    else if (head2 == NULL)
    {
        printlist(head1);
        return 0;
    }

    // Node* head3 = lladditer(head1, head2, 0);
    // Node* head3 = llsubiter(head1, head2, 0);
    Node* head3 = llmuliter(head1, head2, 0);
    // Node* head3 = llexpiter(head1, 4);
    printlist(head3);

    return 0;
}

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->size = 0;
    new_node->next = NULL;
    return new_node;
}

Node* create_num_list(int num)
{
    if (num == 0) 
    {
        Node* newnode = create_node(0);
        newnode->size = 1;
        return newnode;
    }

    Node* head = NULL;
    // set size so that we can use it later
    int size = 0;
    while (num != 0)
    {
        Node* newnode = create_node(num % 10);
        newnode->next = head;
        head = newnode;
        num /= 10;

        // keep calculating size and add it to head node
        size++;
    }
    head->size = size;
    return head;
}

void printlist(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* add_padding(Node *head, int padding)
{
    while(padding--)
    {
        Node *newnode = create_node(0);
        newnode->next = head;
        head = newnode;
    }

    return head;
}

Node* add_padding_back(Node* head, int padding)
{
    Node* temp = head;
    if (!temp && padding > 0)
    {
        return create_node(0);
    }
    else if (!temp && (padding <= 0))
    {
        return NULL;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (padding--)
    {
        Node* newnode = create_node(0);
        temp->next = newnode;
        temp = newnode;
    }

    return head;
}

Node* reverselist(Node* head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node* lladditer(Node* head1, Node* head2, int carry)
{
    Node* revhead1 = reverselist(head1);
    // printlist(revhead1);
    Node* revhead2 = reverselist(head2);
    // printlist(revhead2);

    Node* result = NULL;

    int sum;

    while (revhead1 != NULL || revhead2 != NULL || carry)
    {
        sum = carry;

        if (revhead1)
        {
            sum += revhead1->data;
            revhead1 = revhead1->next;
        }

        if (revhead2)
        {
            sum += revhead2->data;
            revhead2 = revhead2->next;
        }

        carry = sum / 10;

        Node* newnode = create_node(sum % 10);

        newnode->next = result;
        result = newnode;
    }

    // printlist(result);

    if (result != NULL) 
    {
        int size = 0;
        Node* temp = result;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        result->size = size;
    }

    return result;
}

// Node* lladd(Node *head1, Node *head2, int carry)
// {
//     if (head1 == NULL && head2 == NULL)
//     {
//         return NULL;
//     }

//     int sum = carry; 
//     if (head1) sum += head1->data;
//     if (head2) sum += head2->data;

//     carry = sum / 10;

//     struct Node* newnode = create_node(sum % 10);

//     newnode->next = lladd(head1 ? head1->next : NULL, head2 ? head2->next : NULL, carry);

//     return newnode;
// }

Node* llsubiter(Node* head1, Node* head2, int borrow)
{
    Node* revhead1 = reverselist(head1);
    // printlist(revhead1);
    Node* revhead2 = reverselist(head2);
    // printlist(revhead2);

    Node* result = NULL;

    int diff;

    while (revhead1 || revhead2)
    {
        diff = borrow;
        if (revhead1)
        {
            diff += revhead1->data;
            revhead1 = revhead1->next;
        }

        if (revhead2)
        {
            if (diff >= revhead2->data)
            {
                diff -= revhead2->data;
            }
            else 
            {
                borrow = -1;
                int fordiff = 10 - revhead2->data;
                diff += fordiff;
            }
            revhead2 = revhead2->next;
        }

        Node* newnode = create_node(diff);

        newnode->next = result;
        result = newnode;
    }

    if (result != NULL) 
    {
        int size = 0;
        Node* temp = result;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        result->size = size;
    }

    return result;
}

Node* llmuliter(Node* head1, Node* head2, int carry)
{
    Node* revhead1 = reverselist(head1);
    // printlist(revhead1);
    Node* revhead2 = reverselist(head2);
    // printlist(revhead2);

    Node* final_result = NULL;

    int product;

    Node* trav1 = revhead1;
    Node* trav2 = revhead2;

    int pad_count = -1;

    while (trav2)
    {   
        Node* result = NULL;
        // since we are adding null - we need to change the if condition inside padding function
        // result = add_padding_back(result, ++pad_count);
        // so i just found out that the add padding back function was useless
        result = add_padding(result, ++pad_count);
        trav1 = revhead1;
        carry = 0;
        while (trav1)
        {   
            // printlist(result);
            // result = add_padding(result, ++pad_count);
            product = carry;
            product += trav1->data * trav2->data;
            carry = product / 10;

            Node* newnode = create_node(product % 10);

            newnode->next = result;
            result = newnode;

            trav1 = trav1->next;
        }

        // bhai carry to dekho
        if (carry > 0)
        {
            Node* newnode = create_node(carry);
            newnode->next = result;
            result = newnode;
        }

        // printlist(result);
        final_result = lladditer(final_result, result, 0);
        trav2 = trav2->next;
    }

    // somehow reverselist function is changing head1 and just keeping it to be its first node 
    // i.e. for 123 - it is making it 1
    // so i am retrieving head1 again with the reversed list 
    // although i don't think this is good practice - it is working
    // i suspect that this is due to the fact that in reverselist function we are taking current = head
    // which may be changing the head - unintentionally
    // another approach could be to first create a copy of the head and then reverse both the lists
    // also freelist function needs to be implemented: 22:34 04-02-2025
    head1 = reverselist(revhead1);
    head2 = reverselist(revhead2);
    
    return final_result;
}

Node* llexpiter(Node* head, int power)
{
    if (power < 0)
    {
        printf("Power less than 1 not supported");
        return NULL;
    }
    else if (power == 0)
    {
        return create_node(1);
    }

    Node* result = create_node(1);
    for (int i = 0; i < power; i++)
    {
        result = llmuliter(result, head, 0);
    }

    return result;
}
// you need to learn git and github very nicely actually it is very complex and not an easy task