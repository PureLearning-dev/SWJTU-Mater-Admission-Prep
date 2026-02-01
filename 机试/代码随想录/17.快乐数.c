#include<stdio.h>
#include<stdbool.h>

// 一个数对应的下一个数是一定的，所以可以抽象地认为是一个链表，判断链表是否有环！
// 1 <= n <= 2^31 - 1
int get_next(int num){
    int result = 0;
    int m = 0, n = num;

    while(n){
        m = n % 10；
        result += m * m;
        n = n / 10;
    }

    return result;
}

bool isHappy(int n){
    int fast = n, slow = n;

    // 不论是重复转圈还是到达1，fast和slow一定会有相同之时！
    do{
        fast = get_next(get_next(fast));
        slow = get_next(slow);
    }while(fast != slow);

    return fast == 1;
}