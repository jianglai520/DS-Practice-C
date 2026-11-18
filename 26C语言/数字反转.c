//
// Created by Jianglai on 2026/11/18.
//

#include<stdio.h>

int reverseNumber(int n)
{
    int sign = (n < 0) ? -1 : 1;  // 三元运算符，记录正负号
    if (n < 0) n = -n;

    int rev = 0;
    while (n > 0)
    {
        // 去末位拼到rev后面 + 砍掉末位
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return sign * rev;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n",reverseNumber(n));
}