#include <stdio.h>

// * - "value at" operator
// & - "address of" operator

int main(void)
{
    int arr[10] = {11,23,32,45,54,63,72,81,90,10};

    int *ptrtoarr = &arr[0];
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrlen; i++)
    {
        printf("%d element: %d\n", i + 1, *(ptrtoarr + i));
    }

    printf("\n");

    int a = 112;
    int b = 123;
    int c = 34;
    int d = 234;
    int e = 123;

    int *arrofptr[5] = {&a, &b, &c, &d, &e};
    int aoplen = sizeof(arrofptr) / sizeof(arrofptr[0]);
    for (int i = 0; i < aoplen; i++)
    {
        printf("%d element: %d\n", i + 1, *arrofptr[i]);
    }
}