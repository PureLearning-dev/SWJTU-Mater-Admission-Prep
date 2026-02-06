#include<stdio.h>

void fineMinMax(int* arr, int* size, int* min, int* max, int* minIndex, int* maxIndex){
    int MAX = arr[0];
    int MIN = arr[0]; 
    *minIndex = 0;
    *maxIndex = 0;
    for(int i = 1; i < *size; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
            *maxIndex = i;
        }
        if(arr[i] < MIN){
            MIN = arr[i];
            *minIndex = i;
        }
    }

    *min = MIN;
    *max = MAX;
}

int main(){
    printf("请输入数组的长度:");
    int len;
    scanf("%d", &len);
    int arr[len];
    printf("请输入%d个整数:", len);
    for(int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    int min, max, minIndex, maxIndex;
    fineMinMax(arr, &len, &min, &max, &minIndex, &maxIndex);
    printf("从arr中得到的最小值为%d，其索引为%d，最大值为%d，其索引为:%d\n", min, minIndex, max, maxIndex);
    return 0;
}