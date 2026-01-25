#include<stdio.h>

void removeElement(int nums[], int *len, int val){
    int left = 0, right = 0;
    while(right < *len){
        if(nums[right] != val){
            nums[left] = nums[right];
            left++;
        }
        right++;
    }
    *len = left;
}

int main(){
    int times;
    while(scanf("%d", &times) != EOF){
        for(int t = 0; t < times; t++){
            int n, val;
            scanf("%d %d", &n, &val);
            int nums[n];
            for(int i = 0; i < n; i++){
                scanf("%d", &nums[i]);
            }
            removeElement(nums, &n, val);
            printf("After removing %d, the array is:\n", val);
            for(int i = 0; i < n; i++){
                printf("%d ", nums[i]);
            }
            printf("\n");
        }
    }
}