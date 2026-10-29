//
// Created by Jianglai on 2026/10/29.
//

#include <stdio.h>

int main() {
    char input;
    // 读取输入的大写字母
    scanf("%c", &input);

    // 外层循环：控制行数
    // 总行数为 input - 'A' + 1
    for (int i = 0; i <= input - 'A'; i++) {
        // 内层循环：控制每行输出的字母
        // 每行都从 input 开始递减，一共输出 i + 1 个字母
        for (int j = 0; j <= i; j++) {
            printf("%c", input - j);
        }
        printf("\n"); // 换行
    }

    return 0;
}
