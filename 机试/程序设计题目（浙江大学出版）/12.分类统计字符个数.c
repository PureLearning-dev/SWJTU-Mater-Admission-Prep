#include <stdio.h>
#include <string.h>
#define MAXS 15

// letter = 英文字母个数, blank = 空格或回车个数, digit = 数字字符个数, other = 其他字符个数

void StringCount( char s[] );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

void StringCount( char s[] ){
    int letter = 0, blank = 0, digit = 0, other = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if('a' <= s[i] && s[i] <= 'z'){
            letter++;
        }else if(s[i] == ' ' || s[i] == '\n'){
            blank++;
        }else if('0' <= s[i] && s[i] <= '9'){
            digit++;
        }else{
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
}
void ReadString( char s[] ){
    char ch;
    int i = 0;
    while(i < MAXS - 1 && (ch = getchar()) != EOF){
        s[i] = ch;
        i++;
    }
    s[i] = '\0';
}