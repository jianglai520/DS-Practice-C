//
// Created by Jianglai on 2026/9/15.
//

#include<stdio.h>

unsigned long long mask[1000001];

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    for (int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);

        unsigned long long cur = 0;
        for (int j = 0; j < m; j++)
        {
            int a;
            unsigned int b;
            scanf("%d %u", &a, &b);

            if (b & 1U)
            {
                cur ^= (1ULL << (a - 1));
            }
        }
        mask[i] = cur;
    }

    int k;
    scanf("%d", &k);

    unsigned long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        ans ^= mask[x];
    }

    for (int i = 1; i <= t; i++)
    {
        if (ans & (1ULL << (i - 1)))
        {
            printf("1\n");
        } else
        {
            printf("0\n");
        }
    }

    return 0;
}