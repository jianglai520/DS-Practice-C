//
// Created by Jianglai on 2026/11/18.
//

#include<stdio.h>

// 判断一个数字是否是素数
int isPrime(int n) {
    int flag = 0;
    for (int i = 2; i < n; i ++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        return 1;
    }
    return 0;
}

// 输出一个区间范围的所有素数
int printPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    return 0;
}

int main() {
    printPrime(20);
    return 0;
}