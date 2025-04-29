#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define fr(i, a, b) for (int i = a; i < b; i++)

typedef struct License {
    int id;
    int cost;
} License;

int comp_desc(const void *a, const void *b);

int main(void)
{
    int r[] = {7, 8 , 9, 2, 3, 4, 5, 10, 3, 11};
    int n = sizeof(r) / sizeof(r[0]);
    License arr[9];
    fr (i, 0, n)
    {
        arr[i].id = i;
        arr[i].cost = r[i];
    }

    qsort(arr, n, sizeof(License), comp_desc);
    int ans[n];
    fr (i, 0, n)
    {
        ans[i] = arr[i].id;
    }
    double final_cost = 0;
    fr (i, 0, n)
    {
        int t = i;
        int rate = arr[i].cost;
        printf("Month => %d, Job => %d\n", i + 1, ans[i]);
        // final_cost += (100 * rate * t);
        final_cost += (100 * pow(rate, t));
    }
    printf("Final Cost => %.2f\n", final_cost);
    return 0;
}

int comp_desc(const void *a, const void *b)
{
    return(((License *)b)->cost - ((License *)a)->cost);
}