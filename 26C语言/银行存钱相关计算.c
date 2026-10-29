//
// Created by Jianglai on 2026/10/29.
//

#include <stdio.h>

int main()
{
    int year = 0;
    double money = 100.0; // 建议用 double 提高精度，float 可能会在最后几毛钱产生误差
    double sum = 0.0;

    while (money > 0.0)
    {
        year++; // 年份增加

        // 第一年不取款，从第二年开始取
        if (year > 1)
        {
            if (money >= 10.0)
            {
                money -= 10.0;
                sum += 10.0;
            }
            else
            {
                // 余额不足10美元，全部取出，结束循环
                sum += money;
                money = 0.0;
                break;
            }
        }

        // 取款后计算当年的利息
        if (money > 0.0)
        {
            money = money * 1.08;
        }
    }

    // 按照题目要求的格式输出
    printf("After %d year, Jack has no money!\n", year);
    printf("Jack took out %.2f $ altogether\n", sum);

    return 0;
}