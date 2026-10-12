//
// Created by Jianglai on 2026/10/12.
//

#include <stdio.h>
#define PI 3.14159265

int main()
{
    const float pi = 3.14;   // 定义常变量,不能重新对常变量赋值 -- 报错

    printf("%f\n", pi);
    printf("%f\n", PI);

    return 0;
}