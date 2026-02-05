#include<stdio.h>

int removeElement(int* nums, int numsSize, int val){
	int slow = 0, fast = 0;
	while(fast < numsSize){
		if(nums[fast] != val){
			nums[slow++] = nums[fast];
		}
		fast++;
	}
	return slow;
}

int main(){
	int arr[5] = {3, 2, 2, 1, 0};
	int len = removeElement(arr, 5, 2);
	printf("len is %d\n", len);
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}