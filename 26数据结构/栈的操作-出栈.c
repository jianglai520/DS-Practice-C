//
// Created by Jianglai on 2026/10/16.
//

#include<stdio.h>

#define MAXN 1005

int stack[MAXN];

int check(int m, int n, int seq[])
{
    int top = -1;
    int curr = 1;

    for (int i = 0; i < n; i++)
    {
        int target = seq[i];

        while (top < 0 || stack[top] != target)
        {
            if (curr > n) return 0;
            if (top + 1 >= m) return 0;
            stack[++top] = curr++;
        }
        top --;
    }
    return 1;
}

int main()
{
    int m, n, k;
    int seq[MAXN];
    scanf("%d %d %d", &m, &n, &k);

    for (int i = 0; i < k;i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &seq[j]);
        }
        if (check(m, n, seq))
        {
            printf("YES\n");
        } else
        {
            printf("NO\n");
        }
    }


    return 0;

}