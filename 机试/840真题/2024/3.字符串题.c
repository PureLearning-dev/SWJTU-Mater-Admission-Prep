#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfMToNString(char* str, int m, int n){
    int strLen = strlen(str);
    if(m <= 0 || m > strLen || n > strLen || n + m - 1 > strLen){
        printf("参数不符合要求！\n");
        return ;
    }
    char* out = (char*)malloc(sizeof(char) * (n + 1));
    int i;
    for(i = 0; i < n; i++){
        out[i] = str[i + m - 1];
    }
    out[i] = '\0';
    printf("%s\n", out);
    free(out);
}

int main(){
    // char arr[8] = "abddedc";
    // printfMToNString(arr, 3, 5);
    char str[100];
    int m, n;
    printf("请输入字符串:");
    scanf("%s", str);
    printf("请输入m:");
    scanf("%d", &m);
    printf("请输入n:");
    scanf("%d", &n);
    int strLen = strlen(str);
    if(m > strLen || m < 1){
        printf("invalid parameter!\n");
        return 1;
    }
    // 第m个字符为str[m - 1]
    // 确定开始和最后一个字符的索引，如果n个字符已经超过字符串的长度，则将第m个字符以及后续所有字符输出
    int start = m - 1;
    int end;
    if(start + n - 1 < strLen){
        end = start + n - 1;
    }else{
        end = strLen - 1;
    }
    for(int i = start; i <= end; i++){
        printf("%c", str[i]);
    }
    return 0;
}