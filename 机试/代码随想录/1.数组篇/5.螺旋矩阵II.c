#include<stdio.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    // 设置需要传递到外部的信息
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    // 申请result存储int *变量
    int **result = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        *result[i] = (int *)malloc(sizeof(int) * n);
        *returnColumnSizes[i] = n;
    }

    
}