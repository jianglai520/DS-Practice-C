//
// Created by Jianglai on 2026/10/10.
//

#include<stdio.h>

int main()
{
    int num;
    printf("请输入一个数字：");
    scanf("%d", &num);

    if (num <= 1)
    {
        printf("%d不是素数", num);
        return 0;
    }

    int flag = 1;
    for (int i = 2; i * i < num; i++)
    {

        if (num % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("%d是素数", num);
    } else
    {
        printf("%d不是素数", num);
    }

    return 0;
}