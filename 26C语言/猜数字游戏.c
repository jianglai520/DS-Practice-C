//
// Created by Jianglai on 2026/10/22.
// 题目：用计算机产生一个100以内的随机数，游戏者有6次猜数的机会，猜中即胜，猜不中，提示是猜大了还是猜小了，继续猜，直至猜满6次为止。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()

{

    int number,ask,times=1;

    long t;


    srand((unsigned)time(NULL));   /*产生一个与时间有关的随机数*/


    number = rand() % 100 + 1;       /*使随机数在1~100之间*/

    printf("请输入您猜的数字（1~100）：");

    scanf(" %d", &ask);


    t = time(NULL);    /*记时开始*/

    while (ask!=number && times < 6)    /* 增加次数限制 */

    {

        if (ask>number)printf("\n您猜的数字大了。请重新输入：");

        if (ask<number)printf("\n您猜的数字小了。请重新输入：");

        scanf("%d",&ask);

        times++;

    }

    t=time(NULL)-t;

    if (ask != number)
    {
        printf("\n您已经猜了%d次，用时%ld秒，没有猜中，正确答案是%d，回答错误！", times, t, number);  // t是long型，注意是ld
    } else
    {
        printf("\n恭喜您！回答正确。您猜了%d次，用时%dd秒。\n",times, t);
    }

}