//
// Created by Jianglai on 2026/11/18.
//

/*
输入格式:
请在这里写输入格式。例如：输入两个正整数m 、n，要求 m <= n  <=10000。
*/


#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    for (int num = m; num <= n; num++) {
        if (num <= 1) continue;  // 1 不是完数

        int factors[10000];
        int cnt = 0;
        int sum = 0;

        // 找因子（不包括自身）
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                factors[cnt++] = i;
                sum += i;
            }
        }

        if (sum == num) {
            // 按格式输出
            printf("%d = %d", num, factors[0]);
            for (int i = 1; i < cnt; i++) {
                printf(" + %d", factors[i]);
            }
            printf("\n");
        }
    }
    return 0;
}