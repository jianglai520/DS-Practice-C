//
// Created by Jianglai on 2026/11/19.
//

#include <stdio.h>

// 自定义函数：参数为数组和长度，返回偶数个数，通过指针修改和
int get_even_stats(int arr[], int len, int *sum) {
    int count = 0;
    *sum = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] % 2 == 0) {
            *sum += arr[i];
            count++;
        }
    }
    return count; // 直接返回个数
}

int main() {
    int arr[100];
    int n = 0;
    int sum = 0, count = 0;

    printf("请输入一组正整数：\n");
    // 输入处理
    while (scanf("%d", &arr[n]) != EOF) {
        n++;
        if (getchar() == '\n') break;
    }

    // 调用函数，count接收返回值，sum通过指针传递
    count = get_even_stats(arr, n, &sum);

    // 输出结果
    printf("和为%d个数%d\n", sum, count);

    return 0;
}