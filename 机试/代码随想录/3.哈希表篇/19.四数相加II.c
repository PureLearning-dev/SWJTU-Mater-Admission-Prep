#include<stdio.h>
#include<stdlib.h>

#define HASH_LEN 101

typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;

typedef struct HashMap{
    Node* buckets[HASH_LEN];
}HashMap;

int get_hash_index(int key){
    return (key % HASH_LEN + HASH_LEN) % HASH_LEN;
}

int get(HashMap* map, int key){
    int index = get_hash_index(key);
    Node* cur = map->buckets[index];

    while(cur){
        // 如果值和A、B中两个数之和相等，则返回组成的次数
        if(cur->key == key){
            return value;
        }
        cur = cur->next;
    }

    // 不存在则返回出现次数为0
    return 0;
}

// 若存在和相等的key，则value加一，否则将新的结点使用头插法插入桶中
void put(HashMap* map, int key){
    int index = get_hash_index(key);
    Node* cur = map->buckets[i];

    // 如果cur不为空，就将次数增加
    while(cur->next){
        cur = cur->next;
        if(cur->key == key){
            cur->value++;
            return ;
        }
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = cur->next;
    cur->next = newNode;
}

// 若使用遍历，则会使得时间复杂度为O(n^4)，需要想办法进行优化
// 怎样优化？
// 将其分组，无论A、B组合，还是A、C组合，反正两两进行组合，只要两个组合的值互为相反数，相加的值就为0！
// 这里也需要进行在集合中进行快速查找！使用map数据结构

// 将A和B中两数之和 和 出现的次数作为k和v，再计算C和D中的两数之和的负数，看在map中是否存在
int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    HashMap* map = (HashMap *)malloc(sizeof(HashMap));
    
    // map->buckets[i]里面存放虚拟头结点
    for(int i = 0; i < HASH_LEN; i++){
        Node* node = (Node*)malloc(sizeof(Node));
        node->next = NULL;
        map->buckets[i] = node;
    }
    
    // 首先得到map，key存放两数之和，value存放出现key的次数
    int num; // 把num的声明放到外部，可以不用在每次循环中重复声明！
    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            num = nums1[i] + nums2[j];
            put(map, num);
        }
    }

    int times = 0;
    // 遍历C、D之和，看是否在map中存在与之相反的数
    for(int i = 0; i < nums3Size; i++){
        for(int j = 0; j < nums4Size; j++){
            // 因为不存在返回0，所以只用将出现的次数全部相加则可！
            int data = get(map, -nums3[i] - nums4[j]);
            times += data;
        }
    }

    return times;
}




































