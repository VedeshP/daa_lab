#include <stdio.h>
#include <time.h>

void selection_sort(int arr[], int len);

int main(void)
{
    clock_t start, end;
    int arr[] = {7,4,8,9,0,1,2,5,3,6};

    int len = sizeof(arr) / sizeof(int);

    start = clock();
    selection_sort(arr, len);
    end = clock();

    for (int i = 0; i < len; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    printf("time taken for execution: %f", (double) (end - start));

    return 0;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }    
    }

    return;
}