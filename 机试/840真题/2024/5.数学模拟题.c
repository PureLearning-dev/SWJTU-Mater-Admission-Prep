#include<stdio.h>

int main(){
   int x;
   printf("请输入一个0-100内的整数x:");
   scanf("%d", &x);
   int tag = 0;
   printf("符合条件的两数之差如下:\n");
   for(int i = 1; i < 10; i++){
      for(int j = 1; j < 10; j++){
         if((i * 10 + j) - (j * 10 + i) == x){
            printf("%d - %d = %d\n", i * 10 + j, j * 10 + i, x);
            tag = 1;
         }
      }
   }
   if(!tag){
      printf("没有找到符合条件的两数之差\n");
   }
   return 0;
}