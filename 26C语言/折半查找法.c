//
// Created by Jianglai on 2026/11/12.
//


#include<stdio.h>

int main()
{
    int num;
    printf("请输入您要查找的数字：");
    scanf("%d", &num);

    int arr[15] = {1, 5, 13, 19, 26, 27, 56, 64, 75, 80, 88, 89, 105, 106, 120};
    int n = sizeof(arr) / sizeof(arr[0]);

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
        {
            printf("%d\n", mid + 1);
            return 0;
        } else if (arr[mid] < num)
        {
            left = mid + 1;
        } else
        {
            right = mid - 1;
        }
    }

    printf("无此数\n");

    return 0;
}