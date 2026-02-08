#include<stdio.h>

int search(int num[], int len, int target){
    int i = 0, j = len - 1;
    while(i <= j){
        int mid = i + (j - i) / 2;
        if(num[mid] == target){
            return mid;
        }
        else if(num[mid] < target){
            i = mid + 1;
        }
        else{
            j = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, target;
    printf("请输入数组长度和要查找的目标值 (例如: 5 10): ");
    while (scanf("%d %d", &n, &target) != EOF) {
        int num[n];
        printf("请输入 %d 个升序排列的数字: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }

        int res = search(num, n, target);
        
        if (res != -1) {
            printf("找到目标！下标为: %d\n", res);
        } else {
            printf("未找到目标值。\n");
        }
        
        printf("\n继续输入或按 Ctrl+C 退出:\n");
    }
    return 0;
}