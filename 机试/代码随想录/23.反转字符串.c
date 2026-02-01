#include<string.h>

void reverseString(char* string){
    int right = strlen(string) - 1;
    int left = 0;
    
    while(left < right){
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;
        left++;
        right--;
    }
}