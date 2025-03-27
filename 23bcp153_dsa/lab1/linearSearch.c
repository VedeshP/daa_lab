#include <stdio.h>

int linearSearch(int item, int size, int arr[]);

int main()
{
    //VedeshP
    // Linear search
    int item;
    int arr[] = {3,4,1,2,9,7,0,5,8,6};
    printf("Enter the number you want to search: ");
    scanf("%d", &item);
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = linearSearch(item, size, arr);
    // printf("%d", size);

    if (index == -1)
    {
        printf("Number not found");
        return -1;
    }
    else
    {
        printf("Index is %d", index);
        return 0;
    }
}

int linearSearch(int item, int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            return i;
        }
    }

    return -1;
}