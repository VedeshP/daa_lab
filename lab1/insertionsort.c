#include <stdio.h>
#include <time.h>

void insertion_sort(int arr[], int len);

int main(void)
{
    clock_t start, end;
    int arr[] = {7,4,8,9,0,1,2,5,3,6};

    int len = sizeof(arr) / sizeof(int);

    start = clock();
    insertion_sort(arr, len);
    end = clock();

    for (int i = 0; i < len; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    printf("time taken for execution: ", (double) (end - start));

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

    return;
}