//
// Created by Jianglai on 2026/10/22.
//

#include<stdio.h>

int main()
{

    int n, m, x, y;
    printf("分别输入m和n（以空格隔开）：");
    scanf("%d %d", &n, &m);

    x = 2 * n - m / 2;
    if (x > n)
    {
        printf("输出：No answer");
        return 0;
    }
    y = n - x;

    printf("输出：鸡 %d 兔 %d\n", x, y);
    return 0;
}