//
// Created by Jianglai on 2026/10/29.
//

#include <stdio.h>

// 定义方程 f(x) = x^3 + 2x - 5
double f(double x) {
    return x * x * x + 2 * x - 5;
}

int main() {
    double left = -1.0;   // 左边界
    double right = 2.0;   // 右边界
    double mid;           // 中点

    // 循环条件：左右边界距离 > 0.0001 时继续找
    while (right - left > 0.0001) {
        mid = (left + right) / 2.0; // 计算中点

        // 如果中点的函数值与左边界同号，说明根在右半边
        if (f(mid) * f(left) > 0) {
            left = mid; // 移动左边界
        }
        // 否则根在左半边
        else {
            right = mid; // 移动右边界
        }
    }

    // 循环结束后，mid 就是近似根。题目要求保留4位小数
    printf("%.4f\n", mid);

    return 0;
}
