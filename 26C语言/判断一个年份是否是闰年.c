//
// Created by Jianglai on 2026/10/15.
//

#include<stdio.h>

int main()
{
    int year;
    printf("输入：");
    scanf("%d",&year);

    if ((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0))
    {
        printf("输出：闰年\n");
    } else
    {
        printf("输出：平年\n");
    }
}