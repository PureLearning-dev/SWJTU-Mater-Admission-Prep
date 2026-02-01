#include<stdlib.h>
#define CAP 2000;

int compare(const void* a, const void* b){
    int a1 = *(const int*) a; 
    int b1 = *(const int*) b;
    return (a1 > b1) - (a1 < b1); 
}

// 使用双指针进行解决
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize < 3){
        return NULL;
    }

    int left, right, index = 0;
    int** resultSum = (int**)malloc(sizeof(int*) * CAP);
    // 排序，这一步是后续操作的基础！便于去重和统计
    qsort(nums, numsSize, sizeof(int), compare);

    // 要找3个数，所以用于遍历到索引为numsSize-3的位置则可
    for(int i = 0; i < numsSize - 2; i++){
        // 减枝
        // 1.已经从小到大排好序，如果nums[i] > 0则left，right都大于0，此时，无法使得这三个数相加为0
        if(nums[i] > 0){
            break;
        }
        // 2.相邻有重复元素，则转移到下一次循环:朝后比，往前移
        if(i > 0 && nums[i - 1] == nums[i]){
            continue;
        }

        left = i + 1;
        right = numsSize - 1;
        
        while(left < right){
            if(nums[i] + nums[left] + nums[right] > 0){
                right--;
            }else if(nums[i] + nums[left] + nums[right] < 0){
                left++;
            }else{
                // 将这三个值记录并去重:这里的去重和上面的不同，这里是为了防止多个相同的值使得三数之和为0
                int* arr = (int*)malloc(sizeof(int) * 3);
                arr[0] = nums[i];
                arr[1] = nums[left];
                arr[2] = nums[right];
                resultSum[index++] = arr;
                while(left < right && nums[right - 1] == nums[right]){
                    right--;
                }
                while(left < right && nums[left] == nums[left + 1]){
                    left++;
                }
                // 因为left和right都满足，所以需要同时移动！
                left++;
                right--;
            }
        }
    }

    *returnSize = index;
    // 只要是返回的二元数组，每个列都是三个
    // 如何理解这个内容操作呢？
    // 传入的是一个一维数组的地址，需要使用int**
    *returnColumnSizes = (int*)malloc(sizeof(int) * index);
    for(int i = 0; i < index; i++){
        (*returnColumnSizes)[i] = 3;
    }

    return resultSum;
}