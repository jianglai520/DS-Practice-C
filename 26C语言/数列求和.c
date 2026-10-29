//
// Created by Jianglai on 2026/10/29.
//

#include<stdio.h>

int main()
{
    float s = 0.0;
    int i = 1;
    double a_i = 0.0;

    // 第一项
    a_i = (2.0 * i + 1) / (2.0 * i * 2.0 * i);

    while (a_i > 0.001)
    {
        if (i % 2 != 0)
        {
            s += a_i;
        } else
        {
            s -= a_i;
        }

        i += 1;
        a_i = (2.0 * i + 1) / (2.0 * i * 2.0 * i);
    }

    printf("s=%f\n", s);

    return 0;
}
