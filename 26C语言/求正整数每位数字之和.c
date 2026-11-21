//
// Created by Jianglai on 2026/11/19.
// 求正整数每位数字之和

#include <stdio.h>

int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", digitSum(n));

    return 0;
}