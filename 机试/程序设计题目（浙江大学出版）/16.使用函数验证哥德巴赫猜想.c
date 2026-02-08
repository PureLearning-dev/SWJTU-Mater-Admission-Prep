#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );
    
int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}

// 判断是否为素数
int prime( int p ){
    // 将大部分元素排除
    if(p <= 1){
        return 0;
    }
    if(p == 2){
        return 1;
    }
    if(p % 2 == 0){
        return 0;
    }
    int times = (int)sqrt(p);
    for(int i = 3; i < times; i = i + 2){
        // 如果可以整除，则说明这是因数
        if(p % i == 0){
            return 0;
        }
    }
    return 1;
}
// 将n分解为两个奇数素数之和
void Goldbach( int n ){
    for(int i = 3; i < n; i += 2){
        int p = n - i;
        if(prime(i) && prime(p)){
            printf("%d = %d + %d", n, i, p);
            break;
        }
    }
}