#include <stdio.h>
#include <time.h>

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main(void)
{
    clock_t start, end;
    // int arr[] = {7, 4, 8, 9, 0, 1, 2, 5, 3, 6};
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    int len = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = len - 1;
    start = clock();
    quick_sort(arr, low, high);
    end = clock();

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken for execution: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;    
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int location = partition(arr, low, high);
        quick_sort(arr, low, location - 1);
        quick_sort(arr, location + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low; // i is start in lab algo 
    int j = high; // j is end in lab algo

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high)
            i++;
        while (arr[j] > pivot && j >= low)
            j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}