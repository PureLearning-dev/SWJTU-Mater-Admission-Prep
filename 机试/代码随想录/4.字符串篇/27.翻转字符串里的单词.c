#include<string.h>
#include<stdio.h>

// reverses the specified range of characters in a string.
void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

// remove extra spaces.
// use double pointer.
void removeExtraSpace(char* s){
	int len = strlen(s);
	// 'begin' and 'end' identifies the start and end of a string.
	int begin = 0, end = 0;
	while(len > 0 && end < len && s[end] == ' '){
		end++;
	}
	for(; end < len; end++){
		// skip if there are two space characters.
		if(begin > 0 && s[end] == ' ' && s[end - 1] == ' '){
			continue;
		}
		// record qualifying characters.
		s[begin++] = s[end];
	}
	// clear space after string
	if(begin > 0 && s[begin - 1] == ' '){
		s[begin - 1] = '\0';
	}else{
		s[begin] = '\0';
	}
}

// reverse words by spaces.
char* reverseWords(char* s){
	// remove extra spaces.
	removeExtraSpace(s);
	int len = strlen(s);
	// reverse the whole string	
	reverse(s, 0, strlen(s) - 1);
	
	// reverse each individual word
	int start = 0;
	for(int i = 0; i <= len; i++){
		if(s[i] == ' ' || s[i] == '\0'){
			reverse(s, start, i - 1);
			start = i + 1;
		}
	}	
}

int main(){
	char arr[20] = "  I am  spider man !";
	reverseWords(arr);
	printf("%s", arr);
	return 0;
}









