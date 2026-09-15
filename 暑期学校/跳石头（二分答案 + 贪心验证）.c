//
// Created by Jianglai on 2026/9/15.
//

#include<stdio.h>

int L, N, M;
int d[50005];

int check(int mid)
{
    int cnt = 0;
    int last = 0;

    for (int i = 1; i <= N; i++)
    {
        if (d[i] - last < mid)
        {
            cnt ++;
        } else
        {
            last = d[i];
        }
    }

    if (L - last < mid)
    {
        cnt ++;
    }

    return cnt <= M;
}

int main()
{
    scanf("%d %d %d", &L, &N, &M);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &d[i]);
    }
    d[N + 1] = L;

    int left = 1, right = L;
    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (check(mid)) {
        ans = mid;
        left = mid + 1;
        } else
        {
            right = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}