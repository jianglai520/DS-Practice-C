//
// Created by Jianglai on 2026/11/20.
//

#include<stdio.h>
#include<stdlib.h>


// 定义哈夫曼树结点结构体
typedef struct
{
    int weight, parent, lson, rson;
} HufNode;

int heap[200005], heap_size = 0;
HufNode tree[200005];

// 交换两个整数的值
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// 入堆操作
void push(int idx)
{
    heap[++heap_size] = idx;
    for (int i = heap_size; i > 1 && tree[heap[i].weight] < tree[heap[i / 2]].weight; i /= 2)
    {
        swap(&heap[i], &heap[i / 2]);
    }
}


// 出堆操作
int pop()
{
    int top = heap[1];
    heap[1] = heap[heap_size--];

    for (int i = 1; i * 2 <= heap_size; )
    {
        int child = i * 2;

        if (child + 1 <= heap_size && tree[heap[child + 1]].weight < tree[heap[child]].weight)
        {
            child++;
        }

        if (tree[heap[i]].weight <= tree[heap[child]].weight)
        {
            break;
        }

        swap(&heap[i], &heap[child]);
        i = child;
    }
    return top;
}

// 主函数
int main() {
    int n;
    // 读取单词总数
    if (scanf("%d", &n) != 1) return 0;

    char temp_word[100]; // 临时存放单词的字符数组，题目不要求输出单词本身

    // 读取 N 个单词及其频度
    for (int i = 1; i <= n; i++) {
        scanf("%s %d", temp_word, &tree[i].weight); // 直接读取频度存入 tree 数组的前 N 个位置
        tree[i].parent = 0; // 初始化：叶子节点暂时没有父节点
        tree[i].lson = 0;   // 初始化：叶子节点没有孩子
        tree[i].rson = 0;

        push(i); // 【关键】将叶子节点的下标塞进小根堆里，为后续找最小值做准备
    }

    // 特判：如果只有一个单词，它不需要编码，平均码长为 0
    if (n == 1) {
        printf("0.00000\n");
        return 0;
    }

    int total_nodes = n; // 记录当前树中节点的总数。新合并的节点将从 n+1 开始编号

    // 构建哈夫曼树：只要堆里还有2个及以上的节点，就说明还没合并完
    while (heap_size > 1) {
        int a = pop(); // 弹出当前权值最小的节点（对应幻灯片里的最小值）
        int b = pop(); // 弹出当前权值次小的节点

        total_nodes++; // 准备创建新节点

        // 创建新节点（即两个最小节点的合并）
        tree[total_nodes].weight = tree[a].weight + tree[b].weight; // 新权值 = 两者之和
        tree[total_nodes].parent = 0; // 新节点暂未作为别人的孩子
        tree[total_nodes].lson = a;   // 记录左孩子
        tree[total_nodes].rson = b;   // 记录右孩子

        // 【关键】更新被合并节点的父节点指针！这是幻灯片里 parent 数组的核心意义
        tree[a].parent = total_nodes;
        tree[b].parent = total_nodes;

        // 将合并后的新节点重新入堆，参与下一轮选最小值的竞争
        push(total_nodes);
    }

    /* ==================== 第四部分：计算平均码长 ==================== */
    double total_wpl = 0;    // 记录加权路径长度 (Weighted Path Length)
    double total_weight = 0; // 记录所有单词的总频度

    // 只需要遍历原本的 N 个叶子节点（因为它们才代表真实的单词）
    for (int i = 1; i <= n; i++) {
        int depth = 0; // 记录当前节点的深度（即编码长度）
        int curr = i;

        // 顺着 parent 指针往上找，一直找到根节点（parent == 0）
        // 走几步，深度就是几
        while (tree[curr].parent != 0) {
            depth++;
            curr = tree[curr].parent;
        }

        // 累加每个单词的 (频度 × 编码长度)
        total_wpl += (double)tree[i].weight * depth;
        // 累加总频度
        total_weight += tree[i].weight;
    }

    // 计算平均码长 = 总加权路径长度 / 总频度
    double avg_length = total_wpl / total_weight;

    // 按照题目要求，保留 5 位小数输出
    printf("%.5lf\n", avg_length);

    return 0;
}