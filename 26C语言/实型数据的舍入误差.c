//
// Created by Jianglai on 2026/10/19.
//

#include<stdio.h>

int main()
{

    float a, b;
    a = 123456.789e5;
    b = a + 20;

    printf("%f\n", b);  // 实型数据是用有限的存储单元存储的，能提供的有效数字有限，有效位以外的数字将被舍去

    return 0;
}