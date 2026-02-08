#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );
    
int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

// 递归实现效率太低，使用迭代
int fib( int n ){
    if(n <= 1){
        return n;
    }
    int a = 0, b = 1;
    int val;
    for(int i = 0; i < n - 1; i++){
        val = a + b;
        a = b;
        b = val;
    }
    return val;
}

// 斐波那契数列：0 1 1 2 3 5...
// 一边判断一边打印
void PrintFN( int m, int n ){
    int indx = 0;
    int found = 1;
    while(fib(indx) <= n){
        if(m <= fib(indx) && fib(indx) <= n){
            found = 0;
            printf("%d ", fib(indx));
        }
        indx++;
    }
    if(found){
        printf("No Fibonacci number");
    }
    printf("\n");
}