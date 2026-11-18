//
// Created by Jianglai on 2026/11/18.
//
#include<stdio.h>

int fac(int n) {
    if (n == 1)  return 1;
    if (n > 1) {
        return n * fac(n - 1);
    }
}

int main() {
    printf("%d", fac(5));
}