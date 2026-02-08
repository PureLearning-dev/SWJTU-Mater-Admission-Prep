#include<stdio.h>
#define MAX_SIZE 100

// define the stack structures and it's operations.
typedef struct Stack{
	int top;
	int data[MAX_SIZE];
}Stack;

int stackIsEmpty(Stack* stack){
	if(stack->top == -1){
		return 1;
	}
	return 0;
}

int stackIsFull(Stack* stack){
	if(stack->top == MAX_SIZE - 1){
		return 1;
	}
	return 0;
}

// initialization is to set top to negative one.
void initStack(Stack* stack){
	stack->top = -1;
}

void stackPush(Stack* stack, int val){
	if(stack->top == MAX_SIZE - 1){
		printf("stack is full !\n");
		return ;
	}
	stack->data[++(stack->top)] = val;
}

int stackPop(Stack* stack, int* topElement){
	if(stack->top == -1){
		return 0;
	}
	*topElement = stack->data[(stack->top)--];
	return 1;	
}

// methods for implementing queues using stacks.
// the top pointer in each stack can represents the front and rear pointers of the queue.
typedef struct Queue{
	Stack* inStack, outStack;
}Queue;

void initQueue(Queue* queue){
	initStack(queue->inStack);
	initStack(queue->outStack);
}

void push(Queue* queue, int val){
	if(!stackIsFull(queue->inStack)){
		stackPush(queue->inStack, val);	
	}
	return ;
}

int pop(Queue* queue, int* returnVal){
	if(stackIsEmpty(queue->inStack) && stackIsEmpty(queue->outStack)){
		return 0;
	}
	if(!stackIsEmpty(queue->outStack)){
		stackPop(queue->outStack, returnVal);
		return 1;
	}
	// if the outStack is empty, move all inStack elements to the outStack, and then the outStack will be performed.
	int val;
	while(!stackIsEmpty(queue->inStack)){
		stackPop(queue->inStack, &val);
		stackPush(queue->outStack, val);
	}
	stackPop(queue->outStack, returnVal);
		return 1;
	return 0;
} 

int peek(Queue* queue){
	
}

int empty(Queue* queue){
	
} 