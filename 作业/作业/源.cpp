#include <stdio.h>

//反转k个字符
void reserve(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void rotate(int* nums, int k, int len) {
	//将数组分成前后两部分,每一部分分别反转,再整体反转
	int left = 0;
	int right = len - 1;
	int mid = len - k - 1;
	int mid2 = len - k;

	while (left < mid){
		reserve(nums[left], nums[mid]);
		left++;
		mid--;
	}
	while (mid2 < right){
		reserve(nums[mid2], nums[right]);
		right--;
		mid2++;
	}
	while (left < right){
		reserve(nums[left], nums[right]);
		left++;
		right--;
	}
}
int main () {
	int num[10]= { 1, 2, 3, 4, 5, 6, 7 };
	rotate(num, 3, 7);
	return 0;
}