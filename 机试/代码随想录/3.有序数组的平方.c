#include<stdio.h>
#include<stdlib.h>

int* sortedSquares(int *nums, int len){
    int left = 0, index = len - 1, right = len - 1;
    int *result = (int *)malloc(sizeof(int) * len);
    
    while(left <= right){
        if(nums[left] * nums[left] <= nums[right] * nums[right]){
            result[index--] = nums[right] * nums[right];
            right--; 
        }else{
            result[index--] = nums[left] * nums[left];
            left++; 
        }
    }

    return result;
}

int main(){
    int n;
    while(scanf("数组长度：%d", &n) != EOF){
        int nums[n];
        printf("请输入n个数字！");
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        int *result = sortedSquares(result, n);
        for(int i = 0; i < n; i++){
            printf("%d ", result[i]);
        }
    }
    return 0;
}