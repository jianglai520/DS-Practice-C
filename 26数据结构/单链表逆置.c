//
// Created by Jianglai on 2026/10/11.
//

#include<stdio.h>
#include<stdlib.h>

typedef int elementType;

typedef struct Inode{
    elementType data;
    struct Inode* next;
} Lnode, *LinkList;

void ReverseLinkList(LinkList L) {
    LinkList prev = NULL;
    LinkList cur = L->next;

    while (cur != NULL) {
        LinkList next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    L->next = prev;
}

int main() {
    int n;
    scanf("%d", &n);

    LinkList L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    LinkList tail = L;

    for (int i = 0;i < n;i++) {
        LinkList s = (LinkList)malloc(sizeof(Lnode));
        scanf("%d", &s->data);
        s->next = NULL;
        tail->next = s;
        tail = s;
    }

    ReverseLinkList(L);

    LinkList p = L->next;
    if (p) {
        printf("%d", p->data);
        p = p->next;
        while (p) {
            printf(" %d", p->data);
            p = p->next;
        }
    }

    return 0;
}