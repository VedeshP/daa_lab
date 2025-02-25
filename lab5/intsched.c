#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int start;
    int finish;
    int duration;
} Process;

int comp_fin(const void* a, const void* b);
int comp_st(const void* a, const void* b);
int comp_dur(const void* a, const void* b);
void earl_st(Process processes[], int n);
void sjf(Process processes[], int n);
void earl_fin(Process processes[], int n);

int main(void)
{
    Process processes1[] = {
        {1, 1, 4, 4 - 1},
        {2, 3, 5, 5 - 3},
        {3, 0, 6, 6 - 0},
        {4, 5, 7, 7 - 5},
        {5, 3, 9, 9 - 3},
        {6, 5, 9, 9 - 5},
        {7, 6, 10, 10 - 6},
        {8, 8, 11, 11 - 8},
        {9, 8, 12, 12 - 8},
        {10, 2, 14, 14 - 2}
    };

    int n = sizeof(processes1) / sizeof(processes1[0]);

    earl_fin(processes1, n);
    earl_st(processes1, n);
    sjf(processes1, n);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    // As per Cormen example
    Process processes2[] = {
        {1, 1, 4, 4 - 1},
        {2, 3, 5, 5 - 3},
        {3, 0, 6, 6 - 0},
        {4, 5, 7, 7 - 5},
        {5, 3, 9, 9 - 3},
        {6, 5, 9, 9 - 5},
        {7, 6, 10, 10 - 6},
        {8, 8, 11, 11 - 8},
        {9, 8, 12, 12 - 8},
        {10, 2, 14, 14 - 2},
        {11, 12, 16, 16 - 12}
    };

    int n2 = sizeof(processes2) / sizeof(processes2[0]);

    earl_fin(processes2, n2);
    earl_st(processes2, n2);
    sjf(processes2, n2);

    return 0;    
}

// Greedy activity selection - cormen pg. 424 - pdf pg. 446
void earl_fin(Process processes[], int n)
{
    qsort(processes, n, sizeof(Process), comp_fin);

    printf("Selected processes -> Earliest Finish Time\n(printed instead of added in set)\n");
    printf("As per Cormen Greedy Approach\n");
    int last_fin_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].start >= last_fin_time)
        {
            printf("Process %d -> Start: %d, Finish: %d, Duration: %d\n", processes[i].id, processes[i].start, processes[i].finish, processes[i].duration);
            last_fin_time = processes[i].finish;
        }
    }
    return;
}

void earl_st(Process processes[], int n)
{
    qsort(processes, n, sizeof(Process), comp_st);

    printf("Selected processes -> Earliest Start Time\n(printed instead of added in set)\n");
    printf("As per Cormen Greedy Approach\n");
    int last_fin_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].start >= last_fin_time)
        {
            printf("Process %d -> Start: %d, Finish: %d, Duration: %d\n", processes[i].id, processes[i].start, processes[i].finish, processes[i].duration);
            last_fin_time = processes[i].finish;
        }
    }
    return;
}

void sjf(Process processes[], int n)
{
    qsort(processes, n, sizeof(Process), comp_dur);

    printf("Selected processes -> Shortest Job first\n(printed instead of added in set)\n");
    printf("As per Cormen Greedy Approach\n");
    int last_fin_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].start >= last_fin_time)
        {
            printf("Process %d -> Start: %d, Finish: %d, Duration: %d\n", processes[i].id, processes[i].start, processes[i].finish, processes[i].duration);
            last_fin_time = processes[i].finish;
        }
    }
    return;
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

// Details for qsort function
// https://www.w3schools.com/c/ref_stdlib_qsort.php#:~:text=The%20qsort()%20function%20sorts,h%3E%20header%20file.