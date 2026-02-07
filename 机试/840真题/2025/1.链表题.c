#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next; 
} ListNode;

ListNode** splitListToParts(ListNode* head, int k) {
    int list_len = 0;
    ListNode* curr = head;
    while (curr) {
        list_len++;
        curr = curr->next;
    }

    // 分配返回数组的空间
    ListNode** returnListArray = (ListNode**)malloc(sizeof(ListNode*) * k);
    
    int base_len = list_len / k;
    int remainder = list_len % k;

    curr = head;
    for (int i = 0; i < k; i++) {
        returnListArray[i] = curr; 
        
        // 计算当前段应该有多少个节点
        // 只可能在前部分分配最多一次，也就是索引小于remainder的节点
        int current_part_len = base_len + (i < remainder ? 1 : 0);
        
        if (curr != NULL) {
            // 找到当前段的尾节点（走 current_part_len - 1 步）
            for (int j = 0; j < current_part_len - 1; j++) {
                curr = curr->next;
            }
            // 斩断连接
            ListNode* nextHead = curr->next;
            curr->next = NULL;
            curr = nextHead;
        } else {
            // 如果链表已经空了，后面补 NULL
            returnListArray[i] = NULL;
        }
    }
    return returnListArray;
}

ListNode* creatList(int arr[], int len) {
    if (len == 0) return NULL;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];
    head->next = NULL;
    ListNode* curr = head;
    for (int i = 1; i < len; i++) {
        curr->next = (ListNode*)malloc(sizeof(ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

void printfList(ListNode** parts, int k) {
    for (int i = 0; i < k; i++) {
        printf("Part %d: ", i + 1);
        ListNode* p = parts[i];
        while (p) {
            printf("%d -> ", p->val);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head = creatList(nums, 10);
    int k = 3;

    ListNode** result = splitListToParts(head, k);
    printfList(result, k);

    free(result);
    return 0;
}