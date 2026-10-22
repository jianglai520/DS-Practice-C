//
// Created by Jianglai on 2026/10/22.
//

#include<stdio.h>

int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    } else
    {
        return num2;
    }
}

int min(int num1, int num2)
{
    if (num1 > num2)
    {
        return num2;
    } else
    {
        return num1;
    }
}

int main()
{
    int a, b, c;
    printf("ÊäÈë£º");
    scanf("%d %d %d", &a, &b, &c);

    int sum;
    sum = a + b + c;
    printf("Êä³ö£º%d %d %d",min(a, (min(b, c))),sum - max(a, max(b, c)) - min(a, (b, c)) , max(a, max(b, c)));

    return 0;
}
