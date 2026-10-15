//
// Created by Jianglai on 2026/10/15.
//

#include<stdio.h>

int main()
{
    int a, b, c;
    float x, y, z;
    long u;
    long long n;
    char c1, c2;
    a = 3, b = 4, c = 5;
    x = 1.2, y = 2.4, z = -3.6;
    u = 51274, n = 128765;
    c1 = 'a', c2 = 'b';

    printf("a= %d b=%d c= %d\n", a, b, c);
    printf("x=%.6f y=%.6f z=%.6f\n", x, y, z);
    printf("x+y= %.2f y+z=%.2f z+x=%.2f\n", x+y, y+z, z+x);
    printf("u=%ld n=%lld\n", u, n);
    printf("c1=%c or %d\n", c1, c1);
    printf("c2=%c or %d\n", c2, c2);

    return 0;
}