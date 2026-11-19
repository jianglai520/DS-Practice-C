//
// Created by Jianglai on 2026/11/19.
//

#include <stdio.h>

long long factorial(int n)
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main()
{
    int m, n;
    long long result;
    printf("请输入m 和 n的值：");
    scanf("%d %d", &m, &n);

    if ((m > 0 && m <= n) && (n <= 20))
    {
        result = factorial(n) / (factorial(m) * factorial(n - m));
        printf("%lld", result);
    } else
    {
        printf("输入数据不符合条件，输入值应满足0<m<=n<=20\n");
    }

    return 0;
}