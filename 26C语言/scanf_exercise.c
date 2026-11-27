//
// Created by Jianglai on 2026/11/27.
//

#include<stdio.h>

// int main()
// {
//     char s[5] = {"ABCDE"}; puts(s);  // 存在未定义行为，"ABCDE"需要6个字节（5个字符 + 1个\0结束符），可能会出现乱码情况
//
//     return 0;
// }

// int main()
// {
//     char *s; s = "ABCDE"; puts(s);
//
//     return 0;
// }

// int main()
// {
//     char s[5] = {'A', 'B', 'C', 'D', 'E'}; puts(s);
//
//     return 0;
// }

int main()
{
    char *s; scanf("%s", s); puts(s);

    return 0;
}