#include <iostream>

using namespace std;


int childSum(int* arr, int begin, int end){
	int sum = 0;
	while (begin <= end){
		sum += arr[begin];
		++begin;
	}
	return sum;
}

int maxSum(int* arr, int num){
	int begin = 0;
	int end = 1;
	int maxChildSum = INT_MIN;
	while (begin < num - 1){
		//����Ԫ��Ҳ��������
		if (arr[begin] > maxChildSum){
			maxChildSum = arr[begin];
		}
		if (arr[begin] + 1 == arr[end]){
			int cur = begin;
			int next = end;
			//��beginΪ�׵ĸ�������������
			while (arr[cur] + 1 == arr[next] && next < num && cur < num - 1){
				int tmp = INT_MIN;
				tmp = childSum(arr, begin, next);
				//�����һ��������ĺʹ�����һ��������ĺ�,��maxChildSum �ı�
				if (tmp > maxChildSum){
					maxChildSum = tmp;
				}
				++next;
				++cur;
			}
		}
		//��ʼ�ͽ�����λ������ƶ�
		++begin;
		end =  begin + 1;
	}
	if (arr[num - 1] > maxChildSum){
		maxChildSum = arr[num - 1];
	}
	return maxChildSum;
}

int main(){
	int num;
	int ret = 0;
	int arr[100000];
	cin >> num;
	int i = 0;
	while (i < num){
		cin >> arr[i];
		++i;
	}
	ret = maxSum(arr, num);
	cout << ret;

	return 0;
}