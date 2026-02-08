#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

void insertAtHead(ListNode* head, ListNode* node){
    node->next = head->next;
    head->next = node;
}

// 虚拟头结点实现-消耗额外的空间
ListNode* reverseList(ListNode* head){
    ListNode *s_head = (ListNode*)malloc(sizeof(ListNode));
    
    ListNode *p = head;
    while(p != NULL){
        insertAtHead(s_head, p);
        p = p->next;
    }

    return s_head->next;
}

// 双指针实现-原地反转
// 通过将cur->next修改为pre，pre指向cur，cur向后移动则可
ListNode* reverseList(ListNode* head){
    ListNode* pre = NULL;
    ListNode* cur;

    while(head){
        cur = head->next;
        head->next = pre;
        pre = head;
        head = cur;
    }

    return pre;
}