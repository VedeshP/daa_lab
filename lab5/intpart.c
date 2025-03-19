#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int start;
    int finish;
    int duration;
} Process;

typedef struct  Node {
    Process process;
    struct Node* next;
} Node;

typedef struct TT {
    Node** classes;
    int n;
    int filled;
} TT;


int comp_fin(const void* a, const void* b);
int comp_st(const void* a, const void* b);
int comp_dur(const void* a, const void* b);
TT* init_tt(int n);
void add_proc_to_class(Node** head, Process p);
void earl_st(Process processes[], int n, TT* mytt);
void earl_fin(Process processes[], int n, TT* mytt);
void sjf(Process processes[], int n, TT* mytt);
void print_tt(TT* mytt);

int main(void)
{
    Process processes1[] = {
        {1, 1, 2, 2 - 1},
        {2, 1, 3, 3 - 1},
        {3, 1, 4, 4 - 1},
        {4, 2, 4, 4 - 2},
        {5, 3, 5, 5 - 3},
        {6, 4, 6, 6 - 4},
        {7, 4, 6, 6 - 4},
        {8, 6 , 7, 7 - 6},
        {9, 6, 8, 8 - 6},
        {10, 6, 8, 8 - 6}
    };

    int n = sizeof(processes1) / sizeof(processes1[0]);
    TT* mytt;

    printf("Earliest Finish Time Partitioning:\n");
    mytt = init_tt(n);
    earl_fin(processes1, n, mytt);
    print_tt(mytt);
    free(mytt->classes);
    free(mytt);

    printf("\nEarliest Start Time Partitioning:\n");
    mytt = init_tt(n);
    earl_st(processes1, n, mytt);
    print_tt(mytt);
    free(mytt->classes);
    free(mytt);

    printf("\nShortest Job First Partitioning:\n");
    mytt = init_tt(n);
    sjf(processes1, n, mytt);
    print_tt(mytt);
    free(mytt->classes);
    free(mytt);

    return 0;
}

TT* init_tt(int n)
{
    TT* mytt = (TT *)malloc(sizeof(TT));
    mytt->classes = (Node**)malloc(sizeof(Node *) * n);
    mytt->n = n;
    mytt->filled = 0;
    for (int i = 0; i < n; i++)
    {
        mytt->classes[i] = NULL;
    }

    return mytt;
}

void add_proc_to_class(Node** head, Process p)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->process = p;
    new_node->next = *head;
    *head = new_node;
    return;
}

int can_place_in_class(Node* head, Process p)
{
    Node* curr = head;
    while(curr)
    {
        if (p.start < curr->process.finish && p.finish > curr->process.start)
        {
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}

void earl_st(Process processes[], int n, TT* mytt)
{
    qsort(processes, n, sizeof(Process), comp_st);
    for (int i = 0; i < n; i++)
    {
        int placed = 0;
        for (int j = 0; j < mytt->filled; j++)
        {
            if (can_place_in_class(mytt->classes[j], processes[i]))
            {
                add_proc_to_class(&mytt->classes[j], processes[i]);
                placed = 1;
                break;
            }
        }
        if(!placed)
        {
            add_proc_to_class(&mytt->classes[mytt->filled], processes[i]);
            mytt->filled++;
        }
    }
    return;
}

void earl_fin(Process processes[], int n, TT* mytt)
{
    qsort(processes, n, sizeof(Process), comp_fin);
    for (int i = 0; i < n; i++)
    {
        int placed = 0;
        for (int j = 0; j < mytt->filled; j++)
        {
            if (can_place_in_class(mytt->classes[j], processes[i]))
            {
                add_proc_to_class(&mytt->classes[j], processes[i]);
                placed = 1;
                break;
            }
        }
        if(!placed)
        {
            add_proc_to_class(&mytt->classes[mytt->filled], processes[i]);
            mytt->filled++;
        }
    }
    return;
}

void sjf(Process processes[], int n, TT* mytt)
{
    qsort(processes, n, sizeof(Process), comp_dur);
    for (int i = 0; i < n; i++)
    {
        int placed = 0;
        for (int j = 0; j < mytt->filled; j++)
        {
            if (can_place_in_class(mytt->classes[j], processes[i]))
            {
                add_proc_to_class(&mytt->classes[j], processes[i]);
                placed = 1;
                break;
            }
        }
        if(!placed)
        {
            add_proc_to_class(&mytt->classes[mytt->filled], processes[i]);
            mytt->filled++;
        }
    }
    return;
}

void print_tt(TT* mytt)
{
    for (int i = 0; i < mytt->filled; i++)
    {
        printf("Class no.: %d\n\t", i);
        Node* curr = mytt->classes[i];
        while (curr)
        {
            printf("P%d - (%d-%d)   ", curr->process.id, curr->process.start, curr->process.finish);
            curr = curr->next;
        }
        printf("\n");
    }
    printf("\nTotal number of classes used: %d\n", mytt->filled);
}

int comp_fin(const void* a, const void* b)
{
    return (((Process *)a)->finish - ((Process *)b)->finish);
}

int comp_st(const void* a, const void* b)
{
    return (((Process *)a)->start - ((Process *)b)->start);
}

int comp_dur(const void* a, const void* b)
{
    return (((Process *)a)->duration - ((Process *)b)->duration);
}

// can implement using the below strategy
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/editorial/