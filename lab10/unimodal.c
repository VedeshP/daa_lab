#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ans[] = {144, 206, 282, 576, 580, 1395, 1096, 1081, 694, 623};
    int n = sizeof(ans) / sizeof(ans[0]);

    int i = 0, j = n - 1;
    
    int idx = 0;
    int iter = 0;
    while (i < j)
    {
        iter++;
        int mid = (i + j) / 2;
        printf("%d\t", iter);
        if (ans[mid] > ans[mid + 1] && ans[mid] > ans[mid - 1])
        {
            idx = mid;
            break;
        }
        else if (ans[mid] < ans[mid + 1])
        {
            i = mid + 1;
        }
        else 
        {
            j = mid - 1;
        }
    }

    printf("\nUnimodal peak found at index %d with value %d\n", idx, ans[idx]);
    return 0;
}