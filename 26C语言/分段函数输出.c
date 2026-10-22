//
// Created by Jianglai on 2026/10/22.
//

#include<stdio.h>

int fun(int x)
{
    int y;
    if (x < 1)
    {
        y = x;
    } else if (x >= 1 && x < 10)
    {
        y = 2 * x + 1;
    } else
    {
        y = 3 * x - 8;
    }

    return y;
}

int main()
{
    int x1, x2, x3, x4;
    printf("输入x数据分别为：     ");
    scanf("%d、%d、%d、%d", &x1, &x2, &x3, &x4);

    printf("输出函数运算对应结果：%d、%d、%d、%d", fun(x1), fun(x2), fun(x3), fun(x4));

    return 0;
}
