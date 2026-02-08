#include<stdlib.h>
#define NODE_SIZE 16381
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109


// 暴力循环
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int *)malloc(sizeof(int) * 2);
    
    for(int i = 0; i < numsSize; i++){
        int n = target - nums[i];
        for(int j = i + 1; j < numsSize; j++){
            if(nums[j] == n){
                result[0] = i;
                result[1] = j;
            }
        }
    }

    return NULL;
}

// 拉链法实现哈希表
// k:数值
// v:索引
typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;

typedef struct HashMap{
    Node* buckets[NODE_SIZE];
}HashMap;

int get_hash_index(int key){
    // 使用无符号整数运算防止溢出，并处理负数
    unsigned int h = (unsigned int)key;
    // 经典的扰动算法，让高位也参与运算
    h ^= (h >> 16);
    return h % SIZE;
}

void put(HashMap* map, int key, int value){
    int index = get_hash_index(key);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = map->buckets[i]->next;
    map->buckets[index]->next = node;
}

int get(HashMap* map, int key){
    int index = get_hash_index(key);
    Node* cur = map->buckets[index];
    
    while(cur){
        if(cur->key == key){
            return cur->value;
        }
        cur = cur->next;
    }

    return -1;
}

void free_hashmap(HashMap *map){
    for(int i = 0; i < NODE_SIZE; i++){
        Node* cur = map->buckets[i];
        while(cur){
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}

// 哈希表实现:map中的 k 为数值，v 为对应下标。
// 查找target-nums[i]的数值是否存在在map中，若存在且下标不为i，则可，否则，遍历下一个数组元素
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // 声明一个存储体
    HashMap* hashMap = (HashMap*)calloc(1, sizeof(HashMap));
    int* result = (int*)malloc(sizeof(int));
    // 查找并进行一定操作
    for(int i = 0; i < numsSize; i++){
        int com = target - nums[i];
        if(get(hashMap, com) != -1){
            result[0] = i;
            result[1] = get(hashMap, com);
            return result;
        }
        put(hashMap, com, i);
    }

    free(hashMap);
    free(result);

    return NULL;
}