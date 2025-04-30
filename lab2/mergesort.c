#include <stdio.h>
#include <time.h>

void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main(void)
{
    clock_t start, end;
    int arr[] = {7, 4, 8, 9, 0, 1, 2, 5, 3, 6};

    int len = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = len - 1;
    start = clock();
    merge_sort(arr, low, high);
    end = clock();

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken for execution: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}


void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int arrB[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            arrB[k] = arr[i];
            i++; k++;
        }
        else 
        {
            arrB[k] = arr[j];
            j++; k++;
        }
    }

    if (i > mid)
    {
        while (j <= high)
        {
            arrB[k] = arr[j]; 
            j++; k++;
        }
    }

    else if (j > high)
    {
        while (i <= mid)
        {
            arrB[k] = arr[i];
            i++; k++;
        }
    }

    for (int x = 0; x < (high - low + 1); x++)
        arr[low + x] = arrB[x];

    return;
}

// void merge(int arr[], int low, int mid, int high)
// {
//     int i = low, j = mid + 1, k = 0;
//     int size = high - low + 1;
//     int arrB[size];

//     while (i <= low && j <= high)
//     {
//         if (arr[i] < arr[j])
//         {
//             arrB[k] = arr[i];
//             i++; k++;
//         }
//         else
//         {
//             arrB[k] = arr[j];
//             j++; k++;
//         }
//     }

//     if (i > mid)
//     {
//         while (j <= high)
//         {
//             arrB[k] = arr[j];
//             j++; k++;
//         }
//     }
//     else if (j > high)
//     {
//         while (i <= mid)
//         {
//             arrB[k] = arr[k];
//             i++; k++;
//         }
//     }

//     for (int x = 0; x < size; x++)
//     {
//         arr[low + x] = arrB[x];
//     }
// }