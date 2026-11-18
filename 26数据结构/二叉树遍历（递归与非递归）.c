//
// Created by Jianglai on 2026/11/13.
//
#include<stdio.h>
#include<stdlib.h>

// 定义二叉链表结构（内部用到了自己）
typedef struct BiTNode
{
    char data;
    struct BiTNode *lson, *rson;
} BTN;


// 栈结构定义 （没有自引用，也即是没有用到指向自己类型的指针） -- 所以不需要在定义过程中有个名字来引用自己
#define MAX_SIZE 100
typedef struct
{
    BTN* data[MAX_SIZE];
    int top;
} Stack;  // 起别名为 Stack

void InitStack(Stack *s) {s -> top = -1;}  // 初始化栈
int IsStackEmpty(Stack *s) { return s -> top = -1;}  // 判断栈是否为空
void Push(Stack *s, BTN* node) { s -> data[++(s -> top)] = node;}  // 元素入栈
BTN* Pop(Stack *s) { return s -> data[(s -> top)--];}  // 元素出栈
BTN* GetTop(Stack *s) {return s -> data[(s -> top)];}   // 得到栈顶指针

// 队列结构定义（循环队列）
#define MAX_QUEUE 100
typedef struct
{
    BTN* data[MAX_QUEUE];
    int front, rear;  // front指向当前队头元素，rear指向下一个可以插入元素的位置
} Queue;

void InitQueue(Queue *q) { q -> front = q -> rear = 0; }  // 初始化队列
int IsQueueEmpty(Queue *q) {return q->front == q->rear;}  // 判断队列是否为空
void EnQueue(Queue *q, BTN* node)   // 入队函数
{
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % MAX_QUEUE;
}

BTN* DeQueue(Queue *q)  // 出队函数
{
    BTN* node = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE;
    return node;
}


// ======== 核心算法实现 ========

// 1.按照先序序列建立二叉树（递归建树） -- 利用系统调用栈（核心原理）
// 当读到 # 时，函数知道“这条路走到底了”，就返回 NULL 给上一层，上一层的函数马上接着去建它的右子树。
BTN* CreateTree()
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        return NULL;  // 碰到 #号说明是空子树，返回空指针
    } else
    {
        BTN* root = (BTN*)malloc(sizeof(BTN));  // 申请一个新节点
        root -> data = ch;  // 把读到的字母存进去
        root -> lson = CreateTree();   // 递归：建左子树
        root -> rson = CreateTree();  // 递归：建右子树
        return root;  // 返回建好的小树苗的根
    }
}

// 2.递归遍历
// 前序遍历（递归方法）
void PreOrder_Rec(BTN* root)
{
    if (root != NULL)
    {
        printf("%c", root -> data);
        PreOrder_Rec(root -> lson);
        PreOrder_Rec(root -> rson);
    }
}

// 中序遍历（递归方法）
void InOrder_Rec(BTN* root)
{
    if (root != NULL)
    {
        InOrder_Rec(root -> lson);
        printf("%c", root -> data);
        InOrder_Rec(root -> rson);
    }
}


// 后序遍历（递归方法）
void PostOrder_Rec(BTN* root)
{
    if (root != NULL)
    {
        PostOrder_Rec(root -> lson);
        PostOrder_Rec(root -> rson);
        printf("%c", root -> data);
    }
}

// 3.非递归遍历
// 前序遍历（非递归）
void PreOrder_NonRec(BTN* root)
{
    Stack s;
    InitStack(&s);
    if (root != NULL) Push(&s, root);

    while (!IsStackEmpty(&s))
    {
        BTN* p = Pop(&s);
        printf("%c", p->data);

        if (p -> rson != NULL) Push(&s, p -> rson);  // 注意栈结构是先进后出，所以先把右子树压入栈
        if (p -> lson != NULL) Push(&s, p -> lson);
    }
}


// 中序非递归
// 入栈时不打印（先存着），出栈时才打印 -- 栈的记忆功能 -- 时光机、存档器
void InOrder_NonRec(BTN* root)
{
    Stack s;
    InitStack(&s);
    BTN* p = root;

    while (p != NULL || !IsStackEmpty(&s))
    {
        if (p != NULL)
        {
            Push(&s, p);
            p = p -> lson;
        } else
        {
            p = Pop(&s);
            printf("%c", p->data);
            p = p -> rson;
        }
    }
}

// 后序非递归
void PostOrder_NonRec(BTN* root)
{
    if (root == NULL) return;

    Stack s1, s2;  // s1--工作栈 s2--收集栈
    InitStack(&s1); InitStack(&s2);
    Push(&s1, root);

    // 造出“根右左”序列
    while (!IsStackEmpty(&s1))
    {
        BTN* p = Pop(&s1);
        Push(&s2, p);
        if (p -> lson != NULL) Push(&s1, p -> lson);
        if (p -> rson != NULL) Push(&s1, p -> rson);
    }

    // 收尾打印（后进先出） -- “左右根”
    while (!IsStackEmpty(&s2))
    {
        printf("%c", Pop(&s2)->data);
    }
}

// 4.层序遍历
void LevelOrder(BTN* root)
{
    if (root == NULL) return;
    Queue q;
    InitQueue(&q);
    EnQueue(&q, root);

    while (!IsQueueEmpty(&q))
    {
        BTN* p = DeQueue(&q);  // 出队
        printf("%c", p -> data); // 打印
        if (p -> lson != NULL) EnQueue(&q, p -> lson);  // 左孩子入队（如果有）
        if (p -> rson != NULL) EnQueue(&q, p -> rson);  // 右孩子入队（如果有）
    }
}

int GetTreeHeight(BTN* root)
{
    if (root == NULL) return 0;
    int leftheight = GetTreeHeight(root -> lson);
    int rightheight = GetTreeHeight(root -> rson);
    return (leftheight > rightheight ? leftheight : rightheight) + 1;  // 三目运算符：条件表达式 ? 表达式1 : 表达式2
}

int main()
{
    printf("请输入先序序列(空节点用#表示):\n");
    // 测试用例：AB#DG###CE#H###F##

    BTN* root = CreateTree();
    printf("\n--- 遍历结果 ---\n");

    printf("先序遍历:\t递归: ");
    PreOrder_Rec(root);
    printf("\t非递归: ");
    PreOrder_NonRec(root);
    printf("\n");

    printf("中序遍历:\t递归: ");
    InOrder_Rec(root);
    printf("\t非递归: ");
    InOrder_NonRec(root);
    printf("\n");

    printf("后序遍历:\t递归: ");
    PostOrder_Rec(root);
    printf("\t非递归: ");
    PostOrder_NonRec(root);
    printf("\n");

    printf("层次遍历:\t");
    LevelOrder(root);
    printf("\n");

    printf("树高:\t\t%d\n", GetTreeHeight(root));

    return 0;
}