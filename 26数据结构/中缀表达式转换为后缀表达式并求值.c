//
// Created by Jianglai on 2026/10/23.
//

#include<stdio.h>

// 返回运算符的优先级
int priority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

// 中缀表达式转后缀表达式
void infixToPost(char *s, char *post) {  // post输出的后缀字符串， s为输入的中缀字符串
    char op[64];  // 运算符栈
    int top = -1;  // 栈顶指针，-1表示空栈
    int k = 0;
    int i;

    for (i = 0;s[i] != '\0';i++) {
        char c = s[i];

        if (c >= '1' && c <= '9') {
            post[k++] = c;   // 数字直接输出
        } else if (c == '(') {
            op[++top] = c;  // 左括号入栈
        } else if (c == ')') {
            while (top >= 0 && op[top] != '(') {
                post[k++] = op[top--];  // 弹出并输出括号内的运算符
            }
            top--; // 弹出 '('丢弃
        } else {
            // 弹出所有优先级 >= 当前运算符的栈顶元素
            while (top >= 0 && op[top] != '(' && priority(op[top]) >= priority(c)) {
                post[k++] = op[top--];
            }
            op[++top] = c;  // 当前运算符入栈
        }
    }

    // 剩余运算符全部输出
    while (top >= 0) {
        post[k++] = op[top--];
    }
    post[k] = '\0';
}

/* 后缀表达式求值整体思路：
 * 用 int 栈保存操作数：
 * 数字 -> 入栈
 * 运算符 -> 弹两个数 b（后弹/右操作数），a（先弹/左操作数），计算 a op b，结果入栈
 * 最终栈中的唯一元素就是结果
 */
int evalPost(char *post) {
    int num[64];  // 操作数栈
    int top = -1;
    int i;

    for (i = 0;post[i] != '\0'; i++) {  // '\0'字符串中的结束标志
        char c = post[i];

        if (c >= '1' && c <= '9') {
            num[++top] = c - '0';   // 单个数字字符入栈（仅支持一位数字）
        } else {
            int b = num[top--];  // 右操作数
            int a = num[top--];  // 左操作数
            int r;

            if (c == '+') r = a + b;
            else if (c == '-') r = a - b;
            else if (c == '*') r = a * b;
            else r = a / b;

            num[++top] = r;  // 结果入栈
        }
    }
    return num[top];  // 栈顶即结果
}

int main() {
    int N;
    char s[64];
    char post[64];

    scanf("%d", &N);  // 读入的表达式个数

    while (N--) {
        scanf("%s", s);
        infixToPost(s, post);
        printf("%s %d\n", post, evalPost(post));
    }

    return 0;
}