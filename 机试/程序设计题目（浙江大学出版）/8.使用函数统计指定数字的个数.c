#include <stdio.h>

int CountDigit( int number, int digit );
int getZ(int number);    

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));
    
    return 0;
}
int getZ(int number){
    return number >= 0 ? number : -number;
}

int CountDigit( int number, int digit ){
    int zNumber = getZ(number);
    int val = zNumber;
    int times = 0;
    while(val){
        int tag = val % 10;
        val = val / 10;
        if(tag == digit){
            times++;
        }
    }
    return times;
}