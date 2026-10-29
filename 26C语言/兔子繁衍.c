//
// Created by Jianglai on 2026/10/29.
// 斐波那契数列问题（本质）

#include <stdio.h>

int main()
{
    int month = 10;
    int a = 1, b = 1;   // 第一个月和第二个月都为1对
    int temp;

    if (month > 2)
    {
        for (int i = 3; i <= month; i++)
        {
            temp = a + b;
            a = b;
            b = temp;
        }
    }

    printf("%d\n", month);
    printf("%d\n", b);

    return 0;
}

