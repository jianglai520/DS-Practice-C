//
// Created by Jianglai on 2026/11/4.
// while 要先满足条件才能执行 do...while至少执行一次


#include<stdio.h>

// int main()
// {
//     int i;
//     scanf("%d",&i);
//     int sum = 0;
//
//     while (i <= 10)
//     {
//         sum += i;
//         i += 1;
//     }
//
//     printf("%d\n",sum);
//
//     return 0;
// }


int main()
{
    int i;
    scanf("%d",&i);
    int sum = 0;

    do
    {
        sum += i;
        i += 1;
    } while (i <= 10);


    printf("%d",sum);

    return 0;
}