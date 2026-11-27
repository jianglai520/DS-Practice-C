//
// Created by Jianglai on 2026/11/27.
//
/*
邻接表就是每个顶点配一个链表，链表里面存它所有的邻居，是图的一种存储方式 -- 适合稀疏图，省空间，遍历邻居快
邻接矩阵 适合稠密图，查两点是否相连 O(1)
*/

#include<stdio.h>
#include<stdlib.h> // malloc用于动态分配内存

// 定义结构体（单链表结点结构体）每个结点存一个邻接顶点编号和指向下一个结点的指针next，并用 typedef 起了短名 Edge
typedef struct Edge
{
    int v;
    struct Edge *next;
} Edge;

int main()
{
    // 限度最大顶点数量，然后再读创建图的顶点数n和边数m，如果输入格式不对，就直接返回
    int kMaxVertex;
    if (scanf("%d", &kMaxVertex) != 1) return 0;
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // 读n个顶点标签，存入 label[] 数组
    char label[16];
    int i;
    for (i = 0; i < n; i++) if (scanf(" %c", &label[i]) != 1) return 0;

    static int has[16][16];  // 局部变量加 static 会自动初始化为0，初始时候所有 has[u][v] = 0,表示还没有任何边
    Edge *adj[16] = {0};  // 邻接表头指针数组

    // 得到无向图的邻接表（无重复边，头插顺序）
    for (int i = 0; i < m; i++)
    {
        int u, v, w;  // 两个端点的编号，边的权值（但边的权值在本题目中没啥用）
        if (scanf("%d %d %d", &u, &v, &w) != 3) break;  // 没读满三项直接跳出循环
        if (u < 0 || u >= 16 || v < 0 || v >= 16) continue;  // 越界检查
        if (has[u][v]) continue;  // 如果边 (u, v) 已经建过，直接跳过，不重复插入
        has[u][v] = has[v][u] = 1;  // 链式赋值，无向图 (u, v) (v, u)是同一条边，两个方向都要标记

        // 两次 malloc 建立无向边（头插法）
        Edge *e = (Edge *) malloc(sizeof(Edge));
        e->v = v;  // 邻居是 v
        e->next = adj[u];  // 指向原表头
        adj[u] = e;  // 表头改为新节点

        e = (Edge *) malloc(sizeof(Edge));
        e->v = u;
        e->next = adj[v];
        adj[v] = e;
    }

    int visited[16] = {0}; // 访问标记数组，全部初始化为0。访问过则置为1
    int queue[16];   // 用数组模拟队列
    int s;  // 连通分量的起点候选
    for (s = 0; s < n; s++)
    {
        // 如果s（它属于前面某个连通分量）已经访问，则跳过
        if (visited[s]) continue;

        // 初始化队列
        int head = 0, tail = 0;  // 出队指针、入队指针，初始为0
        visited[s] = 1;
        queue[tail++] = s;  // 入队就标记 visited，不是出队时候标记。这样同一顶点不会被重复入队

        while (head < tail) // 队列非空
        {
            // 出队 + 输出
            int u = queue[head++];
            putchar(label[u]);

            // 遍历邻居并入队
            Edge *p;
            for (p = adj[u]; p; p = p->next)
                if (!visited[p->v]) {visited[p->v] = 1; queue[tail++] = p->v;}
        }
        putchar('\n');
    }

    return 0;
}