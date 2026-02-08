#include<stdio.h>
#include<stdlib.h>

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000
int* intersection1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int hash[1001] = { 0 };
    
    // 把nums1中出现过的数字记录到hash表中
    for(int i = 0; i < nums1Size; i++){
        if(hash[nums1[i]] == 0){
            hash[nums1[i]] = 1;
        }
    }

    // 将nums2出现的数字也记录到hash表中
    for(int i = 0; i < nums2Size; i++){
        if(hash[nums2[i]] == 1){
            hash[nums2[i]] = 2;
        }
    }

    // 统计nums1和nums2都出现过的数字
    int total = 0, index = 0;
    int* result = (int *)malloc(sizeof(int) * (nums1Size > nums2Size ? nums2Size : nums1Size));

    for(int i = 0; i < 1001; i++){
        if(hash[i] == 2){
            total++;
            result[index++] = i;
        }
    }

    *returnSize = total;
    return result;
}