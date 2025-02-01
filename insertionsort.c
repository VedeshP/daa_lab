#include <stdio.h>
#include <time.h>

void insertion_sort(int arr[], int len);

int main(void)
{
    clock_t start, end;
    double cpu_time_used;

    int arr[] = {7,6,5,2,1,3,4,9,8};
    int len = sizeof(arr) / sizeof(int);

    start = clock();

    insertion_sort(arr, len);

    end = clock();

    for (int i = 0; i < len; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f\n", cpu_time_used);

    return 0;
}

void insertion_sort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}