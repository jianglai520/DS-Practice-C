//
// Created by Jianglai on 2026/11/12.
//

#include<stdio.h>

int main()
{
    int n = 6;
    int arr[6][6] = {0};

    // 矩阵形式行和列按照要求赋值（杨辉三角）
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    // 遍历打印输出（每行）
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
