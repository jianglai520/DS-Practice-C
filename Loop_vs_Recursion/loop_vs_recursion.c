//
// Created by Jianglai on 2026/9/3.
//
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

#define DEPTH 10000    // 递归深度/循环次数
#define ITERATIONS 1000   // 重复测试次数

// 递归：计算 1 + 2 + ... + n
long long sum_recursion(int n)
{
    if (n == 0) return 0;
    return n + sum_recursion(n - 1);
}

// 循环，计算 1 + 2 + ... + n
long long sum_loop(int n)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    clock_t start, end;
    long long result;

    // -- 测试循环 --
    start = clock();
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        result = sum_loop(DEPTH);
    }
    end = clock();
    printf("循环耗时:%.3f ms\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);
    printf("结果:%lld\n",result);

    // -- 测试递归 --
    start = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        result = sum_recursion(DEPTH);
    }
    end = clock();
    printf("递归耗时:%.3f ms\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);
    printf("结果:%lld\n",result);

    return 0;
}