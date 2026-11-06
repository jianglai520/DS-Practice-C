//
// Created by Jianglai on 2026/10/30.
//
#include <stdio.h>
#include <stdlib.h>   // 内存管理
#include <string.h>  // 字符串处理
#include <ctype.h>  // 字符分类与转换

// 宏定义
#define MAX_WORD_LEN 64  // 一个单次的最大长度
#define MAX_LINE_LEN 1024  // 一行文本的最大上限

/* 行号链表节点 */
// 多个串起来表示某个关键字出现过的所有行号
typedef struct LineNode {
    int lineNo;  // 存行号
    struct LineNode *next;   // 一个指针，指向同类型的下一个节点
} LineNode;

/* 关键字节点 */
// 多个穿起来表示程序要统计的所有关键字的总表
typedef struct WordNode {
    char word[MAX_WORD_LEN];
    int count;
    LineNode *lines;          /* 行号链表头指针 */
    struct WordNode *next;
} WordNode;


/* ---------- 关键字链表操作 ---------- */

/* 创建关键字链表（从文件读入），返回头指针 -- 从磁盘中读取一批关键字，转小写、去重、建成单链表，以便后续统计使用 */
WordNode *loadKeywords(const char *filename) {    // 关键字文件名
    FILE *fp = fopen(filename, "r");  // 只读模式打开文件， 返回文件指针
    // 错误处理
    if (!fp) {
        printf("无法打开关键字文件: %s\n", filename);
        return NULL;
    }
    WordNode *head = NULL, *tail = NULL;  // 初始化头尾指针
    char buf[MAX_WORD_LEN];

    // 循环读字
    while (fscanf(fp, "%63s", buf) == 1) {   // %s 读一个非空白字符序列（遇到空格 、\n等就停），63是最大字段宽度
        /* 转小写，保证大小写不敏感 */
        for (int i = 0; buf[i]; i++) buf[i] = tolower((unsigned char)buf[i]);

        /* 去重：已存在则跳过 */
        int dup = 0;
        for (WordNode *p = head; p; p = p->next)
            if (strcmp(p->word, buf) == 0) { dup = 1; break; }   // strcmp() 逐个字符比较，相等就返回0
        if (dup) continue;

        // 创建新节点并初始化
        WordNode *node = (WordNode *)malloc(sizeof(WordNode));  // 分配内存空间
        strcpy(node->word, buf);   // 把buf里的词复制到word数组
        node->count = 0;
        node->lines = NULL;
        node->next = NULL;

        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    fclose(fp);  // 关闭文件，否侧造成泄露
    return head;    // 返回关键字链表的头指针
}

/* 在关键字链表中查找单词，返回节点指针，找不到返回 NULL */
WordNode *findWord(WordNode *head, const char *w) {
    // 循环遍历单链表
    for (WordNode *p = head; p; p = p->next)
        if (strcmp(p->word, w) == 0) return p;
    return NULL;
}

/* 向某关键字的行号链表追加行号（尾插，去重） */
void addLine(WordNode *node, int lineNo) {

    /* 已经记录过该行则跳过 */
    for (LineNode *p = node->lines; p; p = p->next)
        if (p->lineNo == lineNo) return;

    // 分配并初始化新节点
    LineNode *ln = (LineNode *)malloc(sizeof(LineNode));
    ln->lineNo = lineNo;
    ln->next = NULL;

    if (node -> lines == NULL) {
        node->lines = ln;
    } else {
        LineNode *p = node->lines;
        while (p->next) p = p->next;
        p->next = ln;
    }
}

/* ---------- 小说统计 ---------- */
void countNovel(WordNode *head, const char *novelFile) {
    FILE *fp = fopen(novelFile, "r");

    // 错误处理
    if (!fp) {
        printf("无法打开小说文件: %s\n", novelFile);
        return;
    }
    char line[MAX_LINE_LEN];
    int lineNo = 0;

    while (fgets(line, sizeof(line), fp)) {   // 读到文件末尾返回NULL 循环结束
        lineNo++;
        /* 逐字符扫描分词：只保留字母，其它视为分隔符 */
        char word[MAX_WORD_LEN];
        int wlen = 0;
        for (int i = 0; ; i++) {
            char c = line[i];
            if (isalpha((unsigned char)c)) {   // isalpha(c) 返回非0 表示是英文字母
                if (wlen < MAX_WORD_LEN - 1)
                    word[wlen++] = tolower((unsigned char)c);
            } else {
                /* 遇到分隔符，结束当前词 */
                if (wlen > 0) {
                    word[wlen] = '\0';
                    WordNode *node = findWord(head, word);
                    if (node) {
                        node->count++;
                        addLine(node, lineNo);
                    }
                    wlen = 0;
                }
                if (c == '\0') break;   /* 行结束 */
            }
        }
    }
    fclose(fp);
}

/* ---------- 输出结果 ---------- */
void outputResult(WordNode *head, const char *outFile) {
    FILE *fp = fopen(outFile, "w");
    if (!fp) {
        printf("无法创建输出文件: %s\n", outFile);
        return;
    }
    /* 表头 */
    fprintf(fp, "%-20s %-8s %s\n", "word", "times", "position");
    fprintf(fp, "------------------------------------------------\n");

    for (WordNode *p = head; p; p = p->next) {
        fprintf(fp, "%-20s %-8d ", p->word, p->count);
        if (!p->lines) {
            fprintf(fp, "(none)");
        } else {
            for (LineNode *ln = p->lines; ln; ln = ln->next) {
                fprintf(fp, "%d", ln->lineNo);
                if (ln->next) fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("统计完成，结果已写入 %s\n", outFile);
}

/* ---------- 释放内存 ---------- */
// 释放两个链表占用的堆内存 因为一开始每个节点都是 malloc 来的，也就是动态分配的堆内存 所以最后必须 free 防止内存泄漏
void freeAll(WordNode *head) {
    while (head) {
        WordNode *nxt = head->next;
        LineNode *ln = head->lines;
        while (ln) {
            LineNode *t = ln->next;
            free(ln);
            ln = t;
        }
        free(head);
        head = nxt;
    }
}

/* ---------- 主函数 ---------- */
int main(void) {
    /* 1. 载入关键字集 */
    WordNode *head = loadKeywords("keywords.txt");

    /* 2. 统计小说 */
    countNovel(head, "文本单词统计.c");

    /* 3. 输出结果 */
    outputResult(head, "result.txt");

    /* 4. 释放内存 */
    freeAll(head);

    return 0;
}