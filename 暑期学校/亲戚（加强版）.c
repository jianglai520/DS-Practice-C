//
// Created by Jianglai on 2026/9/17.
//

// 这道题目本质就是考察并查集（合并 + 查询）
// 并查集用一个森林（多棵树）来表示所有集合：每个集合是一棵树；树根是这个集合的代表元；判断两个元素是否在同一个集合 == 判断它们的根是否相同
//用啥来存这棵树？用数组父指针

#include<stdio.h>

#define MAXN 1000005
int parent[MAXN];
int rank_[MAXN];

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);  // 路径压缩
    }
    return parent[x];
}

void union_(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (rank_[rx] < rank_[ry])
    {
        parent[rx] = ry;
    } else if (rank_[rx] > rank_[ry])
    {
        parent[ry] = rx;
    } else
    {
        parent[ry] = rx;
        rank_[rx]++;
    }
}

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank_[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        union_(a, b);
    }

    for (int i = 0; i < p; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (find(a) == find(b))
        {
            printf("Yes\n");
        } else
        {
            printf("No\n");
        }
    }

    return 0;
}


