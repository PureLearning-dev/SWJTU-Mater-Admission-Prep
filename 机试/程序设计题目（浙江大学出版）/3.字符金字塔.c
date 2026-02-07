#include <stdio.h>

void CharPyramid( int n, char ch );

int main()
{    
    int n;
    char ch;

    scanf("%d %c", &n, &ch);
    CharPyramid(n, ch);
    
    return 0;
}

void CharPyramid( int n, char ch ){
    for(int i = 0; i < n; i++){
        // 输出空格
        for(int j = 0; j < n - 1 - i; j++){
            printf(" ");
        }
        // 输出金字塔组成字符
        for(int k = 0; k < i + 1; k++){
            printf("%c ", ch);
        }
        printf("\n");
    }
}
