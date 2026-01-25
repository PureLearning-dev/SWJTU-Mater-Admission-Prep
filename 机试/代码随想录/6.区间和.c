#include<stdio.h>
#include<stdlib.h>

// TODO: 可以优化为一个数组空间

int main(){
    int len;
    scanf("%d", &len);
    
    int *num = (int *)malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++){
        scanf("%d", &num[i]);
    }

    int *pre_num = (int *)malloc(sizeof(int) * len);
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += num[i];
        pre_num[i] = sum;
    }

    int start, end;
    scanf("%d %d", &start, &end);
    int result = start == 0 ? pre_num[end] : pre_num[end] - pre_num[start - 1];

    printf("start:%d到end:%d的区间和为:%d", start, end, result);

    free(num);
    free(pre_num);

    return 0;
}