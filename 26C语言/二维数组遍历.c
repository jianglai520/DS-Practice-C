//
// Created by Jianglai on 2026/11/27.
//

#include <stdio.h>
int main(){
    int matrix[3][3]={
        -1, +0, +0
        +0, -1, +0
        +0, +0, -1
    };
    for(int i=0;i<3;i++){
        if(i>0){printf(" ");}
        for(int j=0;j<3;j++){
            printf("%d",matrix[i][j]);
        }
    }
    printf("\n");
    return 0;
}

// 本题目别被初始化的数组骗了，其实没有9个，只有7个，另外两个只能初始化为0
