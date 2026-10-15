//
// Created by Jianglai on 2026/10/15.
//

#include<stdio.h>

int main()
{
    int num;
    scanf("%d",&num);

    if (1000 <= num && num <= 10000)
    {
        int num1, num2, num3, num4;
        num1 = num / 1000;
        num2 = num % 1000 / 100;
        num3 = num % 1000 % 100 / 10;
        num4 = num % 1000 % 100 % 10;
        printf("%d%d%d%d\n",num4,num3,num2,num1);
    }
    return 0;
}