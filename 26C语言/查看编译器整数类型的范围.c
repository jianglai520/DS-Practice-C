//
// Created by Jianglai on 2026/10/19.
//

#include <stdio.h>

int main(void) {
    printf("char      : %zu 字节\n", sizeof(char));
    printf("short     : %zu 字节\n", sizeof(short));
    printf("int       : %zu 字节\n", sizeof(int));
    printf("long      : %zu 字节\n", sizeof(long));
    printf("long long : %zu 字节\n", sizeof(long long));
    printf("void*     : %zu 字节 (指针宽度, 可判断32/64位)\n", sizeof(void*));
    return 0;
}