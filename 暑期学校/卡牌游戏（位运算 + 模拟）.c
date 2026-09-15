//
// Created by Jianglai on 2026/9/15.
//

#include<stdio.h>

int start[1000005];
int cnt[1000005];
int ca[200005];
int cb[200005];
char chosen[1000005];

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);

    int pos = 0;

    for (int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);

        start[i] = pos;
        cnt[i] = m;

        for (int j = 0; j < m; j++)
        {
            scanf("%d%d", &ca[pos], &cb[pos]);
            pos++;
        }
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int p;
        scanf("%d", &p);
        chosen[p] = 1;
    }

    int ans[65] = {0};

    for (int i = 1; i <= n; i++)
    {
        if (!chosen[i]) continue;

        for (int j = 0; j < cnt[i]; j++)
        {
            int idx = start[i] + j;
            int card = ca[idx];
            int num = cb[idx];

            ans[card] ^= (num & 1);
        }
    }

    for (int i = 1; i <= t; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}
