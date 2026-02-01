#include<stlib.h>
#define CAP 100

int compare(const void* a, const void* b){
    int a1 = *(const int*) a; 
    int b1 = *(const int*) b;
    return (a1 > b1) - (a1 < b1); 
}

// 使用四层for循环会导致时间复杂度很高，使用双指针进行优化
// 因为是双指针，所以要固定两个数，将剩余两个数进行移动
 int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    if(numsSize < 4){
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    // 申请CAP个int*类型的空间，并返回第一个int*空间的内存地址
    int** result = (int**)malloc(sizeof(int*) * CAP);
    int left, right, index = 0;
    
    // 固定第一个数
    for(int i = 0; i < numsSize - 3; i++){
        // 减枝
        // 此时nums[i]是4个数中的第一个数，若此时都大于target，则相加必然大于target
        if(nums[i] > target && nums[i] > 0){
            break;
        }
        // 有重复元素的话，跳过（去重）
        if(i > 0 && (nums[i] == nums[i - 1])){
            continue;
        }

        // 固定第二个数
        for(int j = i + 1; j < numsSize - 2; j++){
            // 减枝
            if(nums[j] + nums[i] > target && nums[j] >= 0){
                break;
            }
            // 每个指针只去重自己指针所需要判断的元素
            if(nums[j] == nums[j - 1] && j > (i + 1)){
                continue;
            }
            left = j + 1;
            right = numsSize - 1; 
            while(left < right){
                int num = nums[i] + nums[j] + nums[left] + nums[right];
                // 如果相加之和大于target，则right右缩
                if(num > target){
                    right--;
                }else if(num < target){
                    left++
                }else{
                    result[index][0] = nums[i];
                    result[index][1] = nums[j];
                    result[index][2] = nums[left];
                    result[index][3] = nums[right];
                    index++;
                }
            }
        }
    }

    *returnSize = index;
    // 需要进行分配空间，每个位置上分配一个int，分配index个
    *returnColumnSizes = (int*)malloc(sizeof(int) * index); 
    for(int i = 0; i < index; i++){
        (*returnColumnSizes)[i] = 4;
    }

    return result;
}
