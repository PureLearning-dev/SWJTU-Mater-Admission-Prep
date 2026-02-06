#include<stdlib.h>
#include<stdio.h>

// 定义链表节点结构体
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

// 创建一个节点
ListNode* createListNode(int val){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if(!node){
        printf("node is NULL!\n");
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}

// 通过输入数字确定链表
ListNode* createList(){
    int len;
    printf("请输入需要创建链表的节点个数:");
    scanf("%d", &len);
    printf("请输入%d个整数:", len);
    int val;
    ListNode* fakeHead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = fakeHead;
    for(int i = 0; i < len; i++){
        scanf("%d", &val);
        ListNode* node = createListNode(val);
        p->next = node;
        p = p->next;
    }
    return fakeHead->next;
}

// 反转链表
ListNode* reverseList(ListNode* head){
    ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
    newHead->next = NULL;
    ListNode* p = head;
    ListNode* q;
    while(p){
        q = p->next;
        p->next = newHead->next;
        newHead->next = p;
        p = q;
    }
    return newHead->next;
}

void printfList(ListNode* head){
    ListNode* p = head;
    while(p){
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

void freeList(ListNode* head){
    ListNode* p = head;
    ListNode* temp;
    while(p){
        temp = p->next;
        free(p);
        p = temp;
    }
}

int main(){
    // 创建一个链表
    ListNode* head = createList();
    printf("新创建的链表为:");
    printfList(head);
    printf("\n");
    ListNode* newHead = reverseList(head);
    printf("反转后的链表为:");
    printfList(newHead);
    printf("\n");
    freeList(head);
}