//
// Created by Jianglai on 2026/10/16.
//

#include <stdio.h>

void ReverseArr(int arr[], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}


int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    m = m % n;  // 务必要考虑 m > n的情况进行取余，不然永远部分错误

    int arr[n];
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
    }

    ReverseArr(arr, 0, n - 1);
    ReverseArr(arr, 0, m - 1);
    ReverseArr(arr, m, n - 1);

    printf("%d", arr[0]);
    for (int i = 1;i < n;i++)
    {
            printf(" ");
            printf("%d", arr[i]);
    }

    return 0;
}
