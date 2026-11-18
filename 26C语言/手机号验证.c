//
// Created by Jianglai on 2026/11/18.
//

/*
某系统在新用户注册时必须输入手机号，为了提高系统效率，防止输错手机号，需要对手机号进行验证。
验证规则为：
（1）长度为11位
（2）由数字0~9组成
（3）必须是1开头
以上3个条件同时满足，则验证通过，否则为不通过。
*/

/*
格式符%s	读的是一串字符（字符串）	char s[25]; scanf("%s", s);	读到空格或换行为止，自动补 '\0'
*/

#include<stdio.h>

int main()
{
    char arr[25];
    scanf("%s", arr);

    int len = 0;
    while (arr[len] != '\0')
    {
        len++;
    }

    int ok = 1;
    if (len != 11)
    {
        ok = 0;
    } else
    {
        if (arr[0] != '1') ok = 0;
        for (int i = 1; i < 11; i ++)
        {
            if (arr[i] < '0' || arr[i] > '9')
            {
                ok = 0;
                break;
            }

        }
    }

    if (ok) printf("yes\n");
    else    printf("no\n");


    return 0;
}
