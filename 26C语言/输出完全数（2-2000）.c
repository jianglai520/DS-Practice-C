//
// Created by Jianglai on 2026/10/29.
//完全数的标准定义是：若正整数 n 的所有真因数（即除 n 本身以外的正因数）之和等于 n，则称 n 为完全数。

#include <stdio.h>

int is_perfect(int n)
{
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum == n;
}

int main()
{
    for (int i = 2; i <= 2000; i++)  // 遍历 2~2000
    {
        if (is_perfect(i))
            printf("%d    ", i);
    }
    printf("\n");
    return 0;
}