#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// recursive implementation
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newHead = head->next;
    ListNode* p = swapPairs(newHead->next);
    head->next = p;
    newHead->next = head;
    return newHead;
}

// iterative implemention.
ListNode* swapPairsByIteration(ListNode* head){
	// add virtual nodes to unify subsequent operations.
	ListNode* fakeHead = (ListNode*)malloc(sizeof(ListNode));
	fakeHead->next = head;
	ListNode* left = fakeHead;
	ListNode* right = head;
	// switch using left, right, right->next.
	while(left && right && right->next){
		
	}
	return fakeHead->next;
}

ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    ListNode* newHead = swapPairs(head);
    printList(newHead);
}