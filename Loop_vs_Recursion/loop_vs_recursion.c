//
// Created by Jianglai on 2026/9/3.
//
// 验证直接循环和秦九韶算法的耗时对比
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 100000

// 直接计算
double directEval(double coeff[], int n, double x)
{
    double result = 0.0;
    for (int i = 0; i <= n; i++)
    {
        double term = coeff[i];
        for (int j = 0; j < i; j++)
        {
            term *= x;
        }
        result += term;
    }
    return result;
}

// 秦九韶算法
double hornerEval(double coeff[], int n, double x)
{
    double result = coeff[n];
    for (int i = n - 1; i >= 0; i--)
    {
        result = result * x + coeff[i];
    }
    return result;
}

int main()
{
    int n = 10000;
    double *coeff = (double *)malloc((n+1) * sizeof(double));
    for (int i = 0; i <= n; i++)
    {
        coeff[i] = (double)(rand() % 100) / 10.0;
    }
    double x = 2.5;

    clock_t start, end;
    double result;

    // -- 测试直接循环 ---
    start = clock();
    for (int iter = 0; iter < 100; iter++)
    {
        result = directEval(coeff, n, x);
    }
    end = clock();
    printf("直接循环耗时: %.3f ms\n", (double)(end - start) / CLOCKS_PER_SEC / 100);
    printf("结果（前几位）:%f\n\n", result);

    // --测试秦九韶
    start = clock();
    for (int iter = 0; iter < 100; iter++)
    {
        result = hornerEval(coeff, n, x);
    }
    end = clock();
    printf("秦九韶算法耗时: %.3f ms\n", (double)(end - start) / CLOCKS_PER_SEC / 100);
    printf("结果（前几位）:%f\n", result);

    free(coeff);
    return 0;
}