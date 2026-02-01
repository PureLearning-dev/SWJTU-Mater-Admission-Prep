#include<string.h>

// 给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。

// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。


// 将string中从索引为start到end的字符串进行反转
void reverseString(char* string, int start, int end){
    int right = end;
    int left = start;
    
    while(left < right){
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;
        left++;
        right--;
    }
}

// 始终需要将剩余字符的前k个字符进行反转
char* reverseStr(char* s, int k){
    int len = strlen(s);

    for(int i = 0; i < len; i = i + 2 * k){
        // 计算需要反转的最后一个索引
        // 若(i + k - 1) < len的话，说明剩余的元素个数大于k个，否则就是小于等于
        int end = (i + k - 1) < len ? i + k - 1 : len - 1;
        reverseString(s, i, end);
    }

    return s;
}