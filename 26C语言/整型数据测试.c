//
// Created by Jianglai on 2026/10/19.
//

#include<stdio.h>

int main() {

    unsigned short price1 = 50;
    printf("%u\n", price1);

    unsigned short price2 = -1;   // 不会报错，但也不会输出 -1，在计算机中数据是以补码的形式存在的
    printf("%u\n", price2);

    unsigned short price3 = -1;
    printf("%d\n", price3);

    return 0;

}