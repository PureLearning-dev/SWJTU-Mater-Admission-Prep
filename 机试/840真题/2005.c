/**
 * @file 2005.c
 * @author PureLearning
 *
 * Created on: 2026-1-13
 */

#include <stdio.h>
#include <stdlib.h>

// 题目规定只能是4位数，且输入7000，要输出0007，故只能用for循环输出每个位数字

void reverseInt(int num){
    for(int i = 0; i < 4; i++){
        printf("%d", num % 10);
        num /= 10;
    }
}

// 要将字符串中所有整数提出并存储到arr中，然后进行输出，数字前面带有“-”，则后面的数字为负数

void printfIntInString(char *str, int len){
    // 最多的情况就是一位数字一个字符，此时数组长度为len/2，不妨设为len
    int arr[len];
    int index = 0;
    // 遍历字符串，寻找数字，并存储到arr中
    for(int i = 0; i < len; i++){
        // 若str[i]不为数字字符，则跳过
        if(str[i] != '-' && (str[i] < '0' || str[i] > '9')){
            continue;
        }
        // 代码在这里都是处理数字字符的
        int sign = 1; 
        int num = 0;
        if(str[i] == '-'){
            sign = -1;
            i++;
        }
        // 提取完整数字
        while(i < len && str[i] >= '0' && str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
            i++;
        }
        arr[index++] = num * sign;
    }
    printf("Extracted integers:\n");
    for(int i = 0; i < index; i++){ 
        printf("%d\n", arr[i]);
    }
}

// 3.
typedef Employee{
    long eID;
    char eName[10];
    struct Employee *pNext;
};

struct Employee *eIDSequence(struct Employee *pHead){

}

// 4.
typedef struct HNode{
    int key;
    struct HNode *next;
} HNode;

void createHB(){

}

void deleteNode(HNode *headLink[], int key){

}

int main(){
    return 0;
}