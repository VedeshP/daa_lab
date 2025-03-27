#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
    int a = 1;
    int b = 2;

    printf("Value of a is %d and value of b is %d\n", a, b);

    swap(&a, &b);

    printf("Value of a is %d and value of b is %d\n", a, b);
    return 0;
}

void swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;

   return;
}