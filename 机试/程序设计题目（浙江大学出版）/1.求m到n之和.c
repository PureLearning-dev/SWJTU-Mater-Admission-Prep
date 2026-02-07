#include <stdio.h>

int sum(int m, int n);

int main()
{    
    int m, n;
    printf("请输入两个整数:");
    scanf("%d %d", &m, &n);
    printf("sum = %d\n", sum(m, n));
    
    return 0;
}

int sum(int m, int n){
    if(m == n){
        return n; 
    }
    return m + sum(m + 1, n);
}