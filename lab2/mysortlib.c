#include <stdio.h>
#include <stdlib.h>

#include "mysortlib.h"

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

    int x = high - low + 1;
    int arrB[x];

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