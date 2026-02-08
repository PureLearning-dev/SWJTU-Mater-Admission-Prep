#include <stdio.h>

void hollowPyramid ( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    hollowPyramid ( n );

    return 0;
}

void hollowPyramid ( int n ){
    int num = 1;
    // 处理n-1行内容
    for(int i = 1; i < n; i++){
        // 处理空格
        for(int j = 0; j < n - i; j++){
            printf(" ");
        }
        printf("%d", i);
        // 处理空格以及后续数字
        if(i != 1){
            for(int i = 0; i < num; i++){
                printf(" ");
            }
            num += 2;
            printf("%d", i);
        }
        printf("\n");
    }
    for(int i = 0; i < num + 2; i++){
        printf("%d", n);
    }
    printf("\n");
}