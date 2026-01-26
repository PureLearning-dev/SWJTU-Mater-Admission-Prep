#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

// 判断两个链表是否相交，并返回相交的第一个结点
// 记录长链表的长度和短链表的长度，若长链表都遍历到NULL了，但与短链表仍然没有相交，则不可能再相交了，否则返回相交结点则可！
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
    int lenA = 0, lenB = 0;
    int gap;
    ListNode* l = NULL;
    ListNode* s = NULL;
    ListNode* temp;

    temp = headA;
    while(temp){
        lenA++;
        temp = temp->next;
    }

    temp = headB;
    while(temp){
        lenB++;
        temp = temp->next;
    }

    if(lenA > lenB){
        gap = lenA - lenB;
        l = headA;
        s = headB;
    }else{
        gap = lenB - lenA;
        l = headB;
        s = headA;
    }

    // 让长的链表到达与短的链表离最后一个结点相同的距离
    while(gap--){
        l = l->next;
    }

    while(l){
        if(l == s){
            return l;
        }
        l = l->next;
        s = s->next;
    }

    return NULL;
}