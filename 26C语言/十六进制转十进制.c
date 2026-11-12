//
// Created by Jianglai on 2026/11/12.
//

#include <stdio.h>

int main() {
    char hexStr[100];
    unsigned long decimalNum = 0;
    int i = 0;

    printf("输入一个十六进制数: ");
    scanf("%99s", hexStr);

    while (hexStr[i] != '\0') {
        char c = hexStr[i];
        int value = 0;

        // 直接通过 ASCII 码范围判断
        if (c >= '0' && c <= '9') {
            value = c - '0';
        }
        // 处理大写字母 A-F
        else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        }
        // 处理小写字母 a-f
        else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        }
        else {
            printf("输入包含非法的十六进制字符！\n");
            return 1;
        }

        decimalNum = decimalNum * 16 + value;
        i++;
    }

    printf("转换为十进制数: %lu\n", decimalNum);

    return 0;
}