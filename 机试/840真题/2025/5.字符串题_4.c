#include<stdbool.h>
#include<stdio.h>
#define N 26
// s2中的字符种类以及个数要与s1中一样，则返回true，否则返回false
// 显然使用哈希表实现
bool checkIncclusion(char* s1, char* s2){
    int hash[N] = {0};
    for(int i = 0; s1[i] != '\0'; i++){
        hash[s1[i] - 'a']++;
    }
    for(int i = 0; s2[i] != '\0'; i++){
        hash[s2[i] - 'a']--;
    }
    for(int i = 0; i < N; i++){
        if(hash[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    char arr[7] = "baacc";
    char brr[7] = "aaccbb";
    if(checkIncclusion(arr, brr)){
        printf("s1可以排列组合成s2\n");
    }else{
        printf("s1不可以排列组合成s2\n");
    }
    return 0;
}