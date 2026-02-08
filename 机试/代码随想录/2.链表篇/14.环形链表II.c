#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

// 快慢指针可以判断出是否存在环！
// 在慢指针进入环时，快指针可能已经走了很多圈了，而慢指针只可能在第一圈时与快指针相遇！
// 如何理解慢指针只可能在第一圈时与快指针相遇呢？慢指针在进入环时，快指针必然已经入环了，而快指针走2步，慢指针走1步，必然可以在一圈内追上。
ListNode* detectCycle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* meet;

    while(fast){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            meet = fast;
            break;
        }
    }

    if(fast == NULL){
        return NULL;
    }

    ListNode* p = head;

    while(p != meet){
        p = p->next;
        meet = meet->next;
    }

    return p;
}