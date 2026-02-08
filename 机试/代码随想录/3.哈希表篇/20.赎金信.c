#include<stdlib.h>
#include<stdbool.h>
#define ALP_LEN 26

// 使用哈希表统计magazine中每个字符出现的次数，然后用ransomNote去消
bool canConstruct(char* ransomNote, char* magazine){
    int map[ALP_LEN] = { 0 };

    // 统计magazine中出现字符的个数
    for(int i = 0; magazine[i] != '\0'; i++){
        map[magazine[i] - 'a']++;
    }

    for(int i = 0; ransomNote[i] != '\0'; i++){
        if(map[ransomNote[i] - 'a'] == 0){
            return false;
        }
        map[ransomNote[i] - 'a']--;
    } 

    return true;
} 