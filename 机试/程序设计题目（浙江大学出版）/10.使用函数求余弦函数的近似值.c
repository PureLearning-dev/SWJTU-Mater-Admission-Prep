#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    
    return 0;
}

double funcos(double e, double x) {
    double cosx = 0;   // 累加和
    double item = 1;   // 当前项的值，第一项是 x^0 / 0! = 1
    int n = 0;         // 计数器

    // 只要当前项的绝对值大于等于 e，就继续累加
    // 只要是+、-、+、...的形式，直接每次乘上-则可！！！
    while (fabs(item) >= e) {
        cosx += item;
        n++;
        // 核心优化：利用前一项推导后一项
        // 下一项 = 前一项 * (-x * x) / ((2*n-1) * (2*n))
        item = item * (-1.0 * x * x) / ((2 * n - 1) * (2 * n));
    }
    
    // 别忘了加上最后一项（因为那一项的绝对值小于 e 时停止，但那一项本身通常也要加进去）
    // 不过根据一般题目要求，加到第一项小于 e 为止即可
    return cosx;
}