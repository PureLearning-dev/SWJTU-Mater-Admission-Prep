#include<stdio.h>
#define MIN 0.000001

double abs(double a){
    return a >= 0 ? a : -a;
}

int main(){
    double a;
    printf("请输入一个大于0的实数:");
    scanf("%lf", &a);
    double x0, x1;
    if(a <= 0){
        printf("a is invalid\n");
        return 1;
    }
    x0 = a / 2;
    x1 = (x0 + a / x0) / 2;
    double e = abs(x1 - x0);
    while(e >= MIN){
        x0 = x1;
        x1 = (x0 + a / x0) / 2;
        e = abs(x1 - x0);
    }
    printf("得到%.6f的平方根为%.6f\n", a, x1);
    return 0;
}