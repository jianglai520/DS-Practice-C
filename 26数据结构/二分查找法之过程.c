//
// Created by Jianglai on 2026/10/16.
//

#include<stdio.h>

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);

    int arr[n];
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0;i < n-1;i++)
    {
        if (arr[i] >= arr[i+1])
        {
            printf("Invalid Value\n");
            return 0;
        }
    }

    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        printf("[%d,%d][%d]\n", left, right, mid);

        if (arr[mid] == x)
        {
            printf("%d\n", mid);
            return 0;
        } else if (arr[mid] < x)
        {
            left = mid + 1;
        } else
        {
            right = mid - 1;
        }
    }
    printf("Not Found\n");

    return 0;
}