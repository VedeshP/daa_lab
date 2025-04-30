#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

bool findMajority(int arr[], int n, int target);
int leftmost(int arr[], int low, int high, int target);
int rightmost(int arr[], int low, int high, int target);

int main(void)
{
    int arr1[] = {1,2,3,3,3,3,10};
    int arr2[] = {1,1,2,4,4,4,6,6};

    int target1 = 3;
    int target2 = 4;

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    bool ans1 = findMajority(arr1, n1, target1);
    bool ans2 = findMajority(arr2, n2, target2);

    if (ans1)
    {
        printf("%d exists more than or equal to half\n", target1);
    }
    else
    {
        printf("%d does not exist more than or equal to half\n", target1);
    }

    if (ans2)
    {
        printf("%d exists more than or equal to half\n", target2);
    }
    else
    {
        printf("%d does not exist more than or equal to half\n", target2);
    }

    return 0;
}

bool findMajority(int arr[], int n, int target)
{
    // Assuming a sorted array
    int low = 0, high = n - 1;
    int mid = (low + high) / 2;
    if (arr[mid] != target)
    {
        return false;
    }

    int left = INT_MAX, right = INT_MIN;
    
    left = min(left, leftmost(arr, low, mid, target));
    right = max(right, rightmost(arr, mid + 1, high, target));

    if ((right - left + 1) > n / 2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int leftmost(int arr[], int low, int high, int target)
{
    int left = arr[high];
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target) 
        {
            left = mid;
            high = mid - 1; // Move left to find the leftmost occurrence
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    return left;
}

int rightmost(int arr[], int low, int high, int target)
{
    int right = arr[low];
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target) 
        {
            right = mid;
            low = mid + 1; // Move right to find the rightmost occurrence
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    return right;
}