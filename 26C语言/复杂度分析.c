//
// Created by Jianglai on 2026/10/12.
//

#include<stdio.h>

int main()
{
    int i = 1;
    int n;
    scanf("%d", &n);

    while (i <= n)
    {
        i *= 2;
    }

    printf("%d\n", i);

    return 0;
}