//
// Created by Jianglai on 2026/11/27.
//

#include<stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int reverseNum(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int flag = 0;
    for (int i = M; i <= N; i++) {
        if (isPrime(reverseNum(i)) && isPrime(i)) {
            if (flag) printf(",");
            printf("%d", i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No");
    }
    return 0;
}