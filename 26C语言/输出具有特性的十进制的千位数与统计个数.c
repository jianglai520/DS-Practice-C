//
// Created by Jianglai on 2026/11/19.
//

// int func(int n)
// {
//
// }
//
//
// int main()
// {
//     return 0;
// }


#include <stdio.h>

// 自定义函数：计算一个十进制数在指定进制下的各位数字之和
int digitSum(int n, int base) {
    int sum = 0;
    while (n > 0) {
        sum += n % base; // 取当前最低位的数字
        n /= base;       // 去掉最低位
    }
    return sum;
}

int main() {
    int count = 0; // 用于统计符合条件的个数

    // 遍历所有的四位数
    for (int i = 1000; i <= 9999; i++) {
        // 分别计算十进制、十二进制、十六进制的各位数字之和
        int sum10 = digitSum(i, 10);
        int sum12 = digitSum(i, 12);
        int sum16 = digitSum(i, 16);

        // 判断三个和是否相等
        if (sum10 == sum12 && sum10 == sum16) {
            // 按照参考答案的格式输出：每个数字占8个字符宽度，左对齐
            printf("%-8d", i);
            count++;

            // 每输出10个数换一行
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }

    // 如果最后一行没有满10个，补一个换行符
    if (count % 10 != 0) {
        printf("\n");
    }

    // 输出总数
    printf("共有%d个\n", count);

    return 0;
}