//
// Created by Jianglai on 2026/11/12.
//

#include <stdio.h>

// 定义交换函数
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    char bubble_arr[] = {'q','w','e','r','t','y','u','M','o','p','e', '\0'};
    char select_arr[] = {'q','w','e','r','t','y','u','M','o','p','e', '\0'};
    int n = 11;

    // 冒泡排序
    int com1 = 0;
    int swap1 = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            com1 += 1;
            if (bubble_arr[j] > bubble_arr[j + 1])
            {
                swap(&bubble_arr[j], &bubble_arr[j + 1]);
                swap1 += 1;
            }
        }
    }

    // 选择排序
    int com2 = 0;
    int swap2 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            com2 += 1;
            if (select_arr[j] < select_arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            char t = select_arr[i];
            select_arr[i] = select_arr[min];
            select_arr[min] = t;
            swap2 += 1;
        }
    }

    // 打印输出
    printf("冒泡法:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c", bubble_arr[i]);
    }
    printf("\n");
    printf("Times of compare: %d\n", com1);
    printf("Times of exchange: %d\n", swap1);

    printf("选择法:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c", select_arr[i]);
    }
    printf("\n");
    printf("Times of compare: %d\n", com2);
    printf("Times of exchange: %d\n", swap2);

    return 0;

}