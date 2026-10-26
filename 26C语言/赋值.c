//
// Created by Jianglai on 2026/10/26.
//

#include<stdio.h>

int main()
{
    int a, b, c;
    a = (b = 5) + (c = 7);
    printf("%d %d %d\n", a, b, c);
    return 0;
}