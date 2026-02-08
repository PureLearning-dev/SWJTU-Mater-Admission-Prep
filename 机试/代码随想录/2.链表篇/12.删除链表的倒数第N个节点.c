#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* s_head = (ListNode*)malloc(sizeof(ListNode));
    s_head->next = head;

    ListNode* p = s_head;
    ListNode* q = head;

    for(int i = 0; i < n; i++){
        p = p->next;
    }

    while(p){
        p = p->next;
        q = q->next;
    }

    ListNode* temp = p->next;
    p->next = temp->next;
    ListNode* result = s_head->next;

    free(temp);
    free(s_head);

    return result;
}