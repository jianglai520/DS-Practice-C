//
// Created by Jianglai on 2026/9/28.
// 由比较三个数的大小并输出延伸到了冒泡排序

#include<stdio.h>

int main()
{
    int a[3];
    printf("请输入3个数字：");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 3 - i; j++)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}


