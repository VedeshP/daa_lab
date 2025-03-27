#include <stdio.h>

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

    printf("Minumum element is %d\n", arr[0]);
    printf("Maximum element is %d\n", arr[n - 1]);
    printf("Second Minimum element is %d\n", arr[1]);
    printf("Second Maximum element is %d\n", arr[n - 2]);


    return 0;
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