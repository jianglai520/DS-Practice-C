//
// Created by Jianglai on 2026/10/11.
//

#include<stdio.h>
#include<stdlib.h>

typedef int elementType;

typedef struct Inode {
    elementType data;
    struct Inode *next;
} Lnode, *LinkList;

LinkList CreateList() {
    LinkList head = (LinkList)malloc(sizeof(Lnode));
    head->next = NULL;
    LinkList tail = head;

    elementType x;
    while (scanf("%d",&x) && x != -1) {
        LinkList p = (LinkList)malloc(sizeof(Lnode));
        p->data = x;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return head;
}

LinkList MergeList(LinkList h1, LinkList h2) {
    LinkList h3 = (LinkList)malloc(sizeof(Lnode));
    h3->next = NULL;
    LinkList tail = h3;
    LinkList p = h1->next;
    LinkList q = h2->next;
    while (p && q) {
        if (p->data <= q->data) {
            tail->next = p;
            p = p->next;
        } else {
            tail->next = q;
            q = q->next;
        }
        tail = tail->next;
    }
    tail->next = p ? p : q;
    return h3;
}

int main() {
    LinkList h1 = CreateList();
    LinkList h2 = CreateList();
    LinkList h3 = MergeList(h1, h2);

    if (h3->next == NULL) {
        printf("NULL\n");
        return 0;
    }

    LinkList p = h3->next;
    int first = 1;
    while (p) {
        if (!first) printf(" ");
        printf("%d", p->data);
        first = 0;
        p = p->next;
    }

    return 0;
}