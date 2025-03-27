#include <stdio.h>

// Get time here too for complexity

int binarySearch(int arr[], int start, int end, int target);
void insertionSort(int arr[], int n);

int main(void)
{
    int n = 0;
    printf("How many elements do you want to enter ?: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d number: ", i + 1);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("What element do you want to find? : ");
    scanf("%d", &target);

    int location = binarySearch(arr, 0, n - 1, target);
    if (location == -1)
    {
        printf("Element not found!");
        return -1;
    }

    printf("Location of your target is: %d", location);

    return 0;
}

int binarySearch(int arr[], int start, int end, int target)
{
    
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
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