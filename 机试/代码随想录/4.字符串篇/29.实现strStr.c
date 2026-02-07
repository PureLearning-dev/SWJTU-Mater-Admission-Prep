#include <string.h>
#include<stdlib.h>
#include <stdio.h>

// 朴素匹配算法 (Brute Force)
int stringMatching(char* s, char* a) {
    int sLen = strlen(s);
    int aLen = strlen(a);
    
    if (aLen == 0) return 0; 
    if (aLen > sLen) return -1;

    // i <= sLen - aLen 保证了剩余字符足够匹配 a
    for (int i = 0; i < sLen - aLen + 1; i++) {
        int j;
        for (j = 0; j < aLen; j++) {
            if (s[i + j] != a[j]) { 
                break;
            }
        }
        if (j == aLen) {
            return i;
        }
    }
    return -1;
}

// 对于上述朴素算法还可以进行优化，优化为不一次只移动一个字符，而是多个，此时需要next数组的帮助，next数组通过前缀表得到
// next数组可以通过前一个值推到下一个值
// next数组的索引对应的值表示字符串在此索引不能匹配的下次匹配的索引值，所以可以通过前面得到的next数组值和此位置的匹配结果得到next的此索引的值
void getNext(char* s, int *next){
    int len = strlen(s);
    // 若第一个字符就不匹配，必然需要将主字符串向后移，使用-1表示
    next[0] = -1;
    // i是要填入next中的值，j指向为需要判断的字符
    int i = -1, j = 0;
    // 因为next[0]已经确定，所以只用循环得到len-1个next值则可
    // 在这种情况下，next[1]必然为0
    while(j < len - 1){
        // 如果前缀的最后一个字符和最后的字符相等，则将最后一个字符的next值+1
        if(i == -1 || s[j] == s[i]){
            j++;
            i++;
            next[j] = i; 
        }else{
            // 否则找前一个前后缀相等的位置
            i = next[i];
        }
    }
}

int KMP(char* s, char* a){
    int sLen = strlen(s);
    int aLen = strlen(a);
    if (aLen == 0) return 0;

    int* next = (int*)malloc(sizeof(int) * aLen);
    getNext(a, next); // 注意：next 数组是根据模式串 a 生成的

    int i = 0; // 主串指针
    int j = 0; // 模式串指针

    while (i < sLen && j < aLen) {
        // j == -1 表示第一个字符就匹配失败，主串和模式串指针都要前进一步
        // 或者当前字符匹配成功
        if (j == -1 || s[i] == a[j]) {
            i++;
            j++;
        } else {
            // 匹配失败，i 不动，j 跳到 next 指定的位置
            j = next[j];
        }
    }

    free(next);

    if (j == aLen) {
        return i - aLen; // 匹配成功
    }
    return -1; // 匹配失败
}

int main() {
    char arr[] = "abbaas";
    char brr[] = "baas";
    
    // 测试 KMP
    int res = KMP(arr, brr);
    printf("匹配下标: %d\n", res);

    // 观察 next 数组（针对模式串 brr "baas"）
    int bLen = strlen(brr);
    int* next = (int*)malloc(sizeof(int) * bLen);
    getNext(brr, next);
    
    printf("模式串 %s 的 next 数组: [", brr);
    for(int i = 0; i < bLen; i++){
        printf("%d%s", next[i], (i == bLen - 1 ? "" : ", "));
    }
    printf("]\n");
    
    free(next);
    return 0;
}