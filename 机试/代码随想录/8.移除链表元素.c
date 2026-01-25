#include<stdio.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// 头结点中的数据也作数
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    // 设置虚拟头结点，便于遍历
    typedef struct ListNode ListNode;
    ListNode *shead;
    shead = (ListNode *)malloc(sizeof(ListNode));
    shead->next = head;
    
    // 遍历处理所有需要淘汰的结点
    ListNode *cur = shead;
    while(cur->next != NULL){
        // 淘汰
        if (cur->next->val == val){
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }
        // 进行下一个结点的处理
        else{
            cur = cur->next;
        }
    }

    head = shead->next;
    free(shead);
    return head;
}