#include<stdio.h>
#include<stdbool.h>
#define N 26

// 字母异位词（Anagram） 是指由相同字母按照不同顺序组成的单词
bool isAnagram(char* s, char* t){
    int hash[N];
    for(int i = 0; i < N; i++){
        hash[i] = 0;
    }

    for(int i = 0; s[i] != '\0'; i++){
        hash[s[i] - 'a']++;
    }

    for(int i = 0; t[i] != '\0'; i++){
        hash[t[i] - 'a']--;
    }

    for(int i = 0; i < N; i++){
        if(hash[i] != 0){
            return false;
        }
    }

    return true;
}