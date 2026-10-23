//
// Created by Jianglai on 2026/10/23.
//

#include<stdio.h>

int priority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

void infixToPost(char *s, char *post) {
    char op[64];
    int top = -1;
    int k = 0;
    int i;

    for (i = 0;s[i] != '\0';i++) {
        char c = s[i];

        if (c >= '1' && c <= '9') {
            post[k++] = c;
        } else if (c == '(') {
            op[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && op[top] != '(') {
                post[k++] = op[top--];
            }
            top--;
        } else {
            while (top >= 0 && op[top] != '(' && priority(op[top]) >= priority(c)) {
                post[k++] = op[top--];
            }
            op[++top] = c;
        }
    }

    while (top >= 0) {
        post[k++] = op[top--];
    }
    post[k] = '\0';
}

int evalPost(char *post) {
    int num[64];
    int top = -1;
    int i;

    for (i = 0;post[i] != '\0'; i++) {
        char c = post[i];

        if (c >= '1' && c <= '9') {
            num[++top] = c - '0';
        } else {
            int b = num[top--];
            int a = num[top--];
            int r;

            if (c == '+') r = a + b;
            else if (c == '-') r = a - b;
            else if (c == '*') r = a * b;
            else r = a / b;

            num[++top] = r;
        }
    }
    return num[top];
}


int main() {
    int N;
    char s[64];
    char post[64];

    scanf("%d", &N);

    while (N--) {
        scanf("%s", s);
        infixToPost(s, post);
        printf("%s %d\n", post, evalPost(post));
    }

    return 0;
}

