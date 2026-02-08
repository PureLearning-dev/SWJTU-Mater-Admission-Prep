#include<string.h>
#include<stdio.h>

void reverse(char* s, int start, int end){
	while(start < end){
		char temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}
}

// global rotation plus local rotation
void rightReverse(char* s, int k){
	int rightLen = k % strlen(s);
	if(rightLen == 0){
		return ;
	}
	// global rotation
	reverse(s, 0, strlen(s) - 1);
	// local rotation
	reverse(s, 0, rightLen - 1);
	reverse(s, rightLen, strlen(s) - 1);	
}

int main(){
	char arr[10] = "abcdefghig";
	rightReverse(arr, 9);
	printf("%s", arr);
}