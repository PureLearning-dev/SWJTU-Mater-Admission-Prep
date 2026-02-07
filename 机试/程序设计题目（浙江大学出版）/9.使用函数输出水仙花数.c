#include <stdio.h>
#include <math.h>
int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

int narcissistic( int number ){
    int e = 0;
    int val = number;
    while(val){
        val /= 10;
        e++;
    }
    val = number;
    int num = 0;
    while(val){
        int data = val % 10;
        num += pow(data, e);
        val /= 10;
    }
    if(num == number)   return 1;
    return 0;
}
void PrintN( int m, int n ){
    for(int i = m + 1; i < n; i++){
        if(narcissistic(i)){
            printf("%d\n", i);
        }
    }
}