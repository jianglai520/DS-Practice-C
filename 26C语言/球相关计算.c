//
// Created by Jianglai on 2026/10/15.
//

#include<stdio.h>

#define PI 3.14159265

int main()
{
    float r, h;
    printf("请输入r和h（空格隔开）:");
    scanf("%f %f", &r, &h);

    double circ, circleArea, sphereArea, squareVol, cylVol;  // 圆的周长、圆面积、圆球表面积、圆球提及、圆柱体积
    circ = 2 * PI * r;
    circleArea = PI * r * r;
    sphereArea = 4 * PI * r * r;
    squareVol = 4 * PI * r * r * r / 3;
    cylVol = PI * r * r * h;

    printf("圆的周长、圆面积、圆球表面积、圆球体积、圆柱体积分别为（空格隔开）：%.2f %.2f %.2f %.2f %.2f", circ, circleArea, sphereArea, squareVol, cylVol);
    return 0;

}