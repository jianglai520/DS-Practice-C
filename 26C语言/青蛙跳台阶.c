//
// Created by Jianglai on 2026/11/19.
//

#include<stdio.h>

int fun_rec(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n > 1) return fun_rec(n - 1) + fun_rec(n - 2);
}

int fun_nonrec(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;

    int a = 1;
    int b= 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",fun_rec(n));
    // printf("%d\n",fun_nonrec(n));

    return 0;
}


