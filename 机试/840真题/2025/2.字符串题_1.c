#include <stdio.h>
#include <string.h>

int main() {
    char arr[100];
    printf("请输入一个以 @ 结尾的字符串: \n");
    int i = 0;
    // 使用一个字符作为输入的暂存器，方便后续使用
    char ch;
    while (scanf("%c", &ch) == 1 && ch != '@') {
        arr[i] = ch;
        i++;
    }
    arr[i] = '\0';
    // 得到了输入的字符串了，判断是否为回文
    int start = 0;
    int end = strlen(arr) - 1;
    // 处理空字符串或只有一个字符的情况（可选）
    if (i == 0) {
        printf("空字符串，默认回文。\n");
        return 0;
    }
    while (start < end) {
        if (arr[start] != arr[end]) {
            printf("该字符串不满足回文\n");
            return 0;
        }
        start++;
        end--;
    }
    printf("该字符串满足回文\n");
    return 0;
}