//
// Created by Jianglai on 2026/9/28.
//
#include<stdio.h>

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    } else {return y;}
}

int min(int x, int y)
{
    if (x < y)
    {
        return x;
    } else {return y;}
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int min_num = min(a, min(b, c));
    int max_num = max(a, max(b, c));

    printf("%d %d %d", min_num, a + b + c - min_num - max_num, max_num);

    return 0;
}