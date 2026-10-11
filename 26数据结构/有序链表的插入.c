//
// Created by Jianglai on 2026/10/11.
//

#include<stdio.h>
#include<stdlib.h>

typedef int elementType;   // 给int起个别名elementType。如果以后想把链表元素改成float等，只需要修改一行

typedef struct Inode
{
    elementType data;   // 存数据
    struct Inode* next; // 指向下一个结点的指针
} Lnode, *LinkList;


/* 在带头结点的有序链表L中插入x,保持有序 */
void InsertOrder(LinkList L, elementType x)
{
    LinkList p = L;

    while (p->next != NULL && p->next->data < x)
    {
        p = p->next;
    }

    LinkList s = (LinkList)malloc(sizeof(Lnode));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

int main()
{
    int n;
    scanf("%d",&n);

    /* 创建头结点 */
    LinkList L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;

    LinkList tail = L;

    /* 读入 n 个递增整数，尾插建链表 */
    for (int i = 0;i < n;i++)
    {
        elementType v;
        scanf("%d",&v);

        LinkList s = (LinkList)malloc(sizeof(Lnode));
        s->data = v;
        s->next = NULL;
        tail->next = s;
        tail = s;
    }

    /* 读入待插入的元素 */
    elementType x;
    scanf("%d",&x);

    /* 插入并保持有序 */
    InsertOrder(L,x);

    /* 输出，每个元素前面加一个空格 */
    LinkList p = L->next;
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }

    /* 释放内存 */
    p = L;
    while (p != NULL)
    {
        LinkList tmp = p;
        p = p->next;
        free(tmp);
    }

    return 0;
}