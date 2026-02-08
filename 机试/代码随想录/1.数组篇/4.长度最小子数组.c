#include<stdio.h>
#include<limits.h>

int minSubArrayLen(int target, int* nums, int numsSize){
    int left = 0, right = 0;
    int sum = 0;
    int len = INT_MAX;

    for(; right < numsSize; right++){
        sum += nums[right];

        while(sum >= target){
            // 记录此时的数组长度并与len比较，得到较小的一个
            int min = right - left + 1;
            len = len > min ? min : len;
            sum -= nums[left++];
        }
    }

    // 若没有修改len，则返回0
    return len == INT_MAX ? 0 : len;
}