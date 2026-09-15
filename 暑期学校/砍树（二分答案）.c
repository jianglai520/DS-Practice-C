//
// Created by Jianglai on 2026/9/15.
//

#include <stdio.h>
#include<stdio.h>
#define MAXN 1000005

int heights[MAXN];

int main()
{
    int N;   // int 够用
    long long M;    // 需要的木材总量用long long
    scanf("%d %lld", &N, &M);

    int maxH = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &heights[i]);
        if (heights[i] > maxH)
        {
            maxH = heights[i];
        }
    }

    int lo = 0;
    int hi = maxH;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        long long total = 0;
        for (int i = 0; i < N;i++)
        {
            if (heights[i] > mid)
            {
                total += heights[i] - mid;
            }
        }
        if (total >= M)
        {
            lo = mid;   // 注意不是 lo = mid + 1
        } else
        {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
    return 0;
}
