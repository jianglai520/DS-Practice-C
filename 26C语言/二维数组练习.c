//
// Created by Jianglai on 2026/11/27.
//

#include <stdio.h>

int main(void)
{
    /* 正确写法 D */
    char a[][3] = {"a", "1"};

    /*
     * 下面三种写法是错误的，编译会报错，不能直接放在代码里：
     *
     * A. char a1[3][] = {'abc', '1'};
     *    错误：二维数组第二维不能省略；'abc' 是多字符常量，不是字符串。
     *
     * B. char a2[][3] = {'abc', '1'};
     *    错误：'abc' 是多字符常量，不能用来初始化 char[3]。
     *
     * C. char a3[3][] = {'a', "1"};
     *    错误：第二维不能省略；'a' 不能初始化一个 char 数组元素。
     */

    printf("a[0] = \"%s\"\n", a[0]);  
    printf("a[1] = \"%s\"\n", a[1]);

    printf("a[0][0] = '%c'\n", a[0][0]);
    printf("a[0][1] = '\\0'? %d\n", a[0][1] == '\0');
    printf("a[1][0] = '%c'\n", a[1][0]);
    printf("a[1][1] = '\\0'? %d\n", a[1][1] == '\0');

    printf("sizeof(a) = %zu\n", sizeof(a));       /* 2 * 3 = 6 */
    printf("sizeof(a[0]) = %zu\n", sizeof(a[0])); /* 3 */
    printf("数组行数 = %zu\n", sizeof(a) / sizeof(a[0])); /* 2 */

    return 0;
}