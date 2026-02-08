#include <stdio.h>
#include <math.h>

int factorsum( int number );
void PrintPN( int m, int n );
    
int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);
    // printf("%d %d\n", factorsum(m), factorsum(n));
    return 0;
}

// 返回因子和
int factorsum( int number ){
    if(number == 1) return 0;
    // 此后，1必然是因数
    int sum = 1;
    int len = (int)sqrt(number);

    for(int i = 2; i < len + 1; i++){
        if(number % i == 0){
            sum += i;
            if(i * i < number){
                sum += (number / i);
            }
        }
    }

    return sum;
}
void PrintPN( int m, int n ){
    int notFound = 1;
    
    // 遍历判断是否为完数
    for(int i = m; i < n + 1; i++){
        // 若是完数，则输出因数之和表达式
        if(factorsum(i) == i){
            notFound = 0;
            printf("%d = 1", i);
            for(int j = 2; j < i / 2 + 1; j++){
                if(i % j == 0){
                    printf(" + %d", j);
                }
            }
            printf("\n");
        }
    }

    if(notFound){
        printf("No perfect number");
    }
    printf("\n");
}
