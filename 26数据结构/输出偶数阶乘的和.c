//
// Created by Jianglai on 2026/11/19.
//

#include <stdio.h>

int factorial(int n)
{
    int i, j, k, sum = 0;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 1, k = 1; j <= i; j++)
            {
                k = k * j;
            }
            sum += k;
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = factorial(n);

    printf("%d", sum);

    return 0;
}