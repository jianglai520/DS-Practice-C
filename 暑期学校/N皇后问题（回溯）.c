//
// Created by Jianglai on 2026/9/17.
//

#include<stdio.h>

int n;
int total = 0;
int printed = 0;
int pos[15];

int col[15];
int diag1[30];
int diag2[30];

void dfs(int row)
{
    if (row > n)
    {
        total ++;
        if (printed < 3)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", pos[i]);
                if (i < n) printf(" ");
            }
            printf("\n");
            printed ++;
        }
        return;
    }

    for (int c = 1; c <= n; c++)
    {
        if (!col[c] && !diag1[row - c + n] && !diag2[row + c])
        {
            pos[row] = c;
            col[c] = 1;
            diag1[row - c + n] = 1;
            diag2[row + c] = 1;

            dfs(row + 1);

            col[c] = 0;
            diag1[row - c + n] = 0;
            diag2[row + c] = 0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    printf("%d\n", total);
    return 0;
}