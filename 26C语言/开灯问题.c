//
// Created by Jianglai on 2026/11/12.
//


#include<stdio.h>

int main()
{
    int n, k;
    printf("输入灯的数量n=");
    scanf("%d", &n);
    printf("输入人的数量k=");
    scanf("%d", &k);

    // 题目说明 n <= 100，直接开 105 大小的数组更安全
    int arr[105] = {0};  // 0表示关着，1表示开着

    // 外层循环：i 代表第 i 个人（从1到k）
    for (int i = 1; i <= k; i++)
    {
        // 内层循环：j 代表灯的编号（从1到n）
        for (int j = 1; j <= n; j++)
        {
            // 如果灯的编号是人的编号的倍数
            if (j % i == 0)
            {
                // 状态反转：0变1，1变0
                arr[j] = !arr[j];
            }
        }
    }

    printf("最后亮灯的编号是");
    // 遍历输出，注意灯的编号是 1 到 n
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            printf(" %d", i); // 输出实际的灯编号
        }
    }
    printf("\n");

    return 0;
}