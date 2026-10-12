//
// Created by Jianglai on 2026/10/12.
//

#include<stdio.h>

#define PRICE 30

int main()
{
    int num, total;
    scanf("%d", &num);

    total = PRICE * num;
    printf("%d\n", total);

    return 0;
}