#include<stdio.h>
#include<stdio.h>
#include<math.h>

int main(){
    
    // 城市被划分为n×m个小方格，每个方格的权值不同
    // A、B只能分配行或者列的方格（划分为两个子区域）
    int n, m;
    scanf("%d %d", &n, &m);

    // 只要将行、列方向上的前缀和得到，就可以遍历得到两个方向上的最小值
    int *pre_sum_h = (int *)malloc(sizeof(int) * n);
    int *pre_sum_l = (int *)malloc(sizeof(int) * m);
    for(int i = 0; i < n; i++){
        pre_sum_h[i] = 0;
    }
    for(int i = 0; i < m; i++){
        pre_sum_l[i] = 0;
    }

    // 从输入中得到行、列权值之和
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int data;
            scanf("%d", &data);
            // pre_sum_h[i]表示第i行的所有权值之和 
            pre_sum_h[i] += data;
            // pre_sum_l[j]表示第j列的所有权值之和 
            pre_sum_l[j] += data;
        }
    }

    // 得到前缀和
    for(int i = 1; i < n; i++){
        pre_sum_h[i] += pre_sum_h[i - 1];
    }
    for(int i = 1; i < m; i++){
        pre_sum_l[i] += pre_sum_l[i - 1];
    }

    // 分别得到行差、列差最小
    int min_h = pre_sum_h[n - 1];
    int min_l = pre_sum_l[m - 1];
    for(int i = 0; i < n; i++){
        if(min_h > abs(pre_sum_h[n - 1] - 2 * pre_sum_h[i])){
            min_h = abs(pre_sum_h[n - 1] - 2 * pre_sum_h[i]);
        }
    }
    for(int i = 0; i < m; i++){
        if(min_l > abs(pre_sum_l[m - 1] - 2 * pre_sum_l[i])){
            min_l = abs(pre_sum_l[m - 1] - 2 * pre_sum_l[i]);
        }
    }

    printf("A、B区域权值相差最小值为:%d", min_h > min_l ? min_l : min_h);

    return 0;
}