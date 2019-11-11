#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


//�����ַ���B
char* insertStr(char* str1, char* str2, int begin){
	char* str = new char[200];
	memset(str, 0, 200);
	str[0] = '\0';
	//�����λ��
	int pos = begin + 1;
	memcpy(str, str1, pos);
	strcat(str, str2);
	strcat(str, str1 + pos);
	return str;
}

//�жϲ������ַ����ǲ��ǻ��Ĵ�
int isPal(char* str){
	int len = strlen(str);
	int begin = 0;
	int end = len - 1;
	while (begin < end){
		if (str[end] != str[begin]){
			return 0;
		}
		--end;
		++begin;
	}
	return 1;
}

int TotalNum(char* str1, char* str2){
	int ret = 0;
	int str1len = strlen(str1);
	int str2len = strlen(str2);
	int begin = 0;
	char* str = new char[200];
	memset(str, 0, 200);
	str[0] = '\0';
	strcat(str, str2);
	strcat(str, str1);
	if (isPal(str)){
		++ret;
	}
	while (begin < str1len){
		//����ƴ�Ӻ���ַ���
		str = insertStr(str1, str2, begin);
		//���Ϊ��, ret + 1
		if (isPal(str)){
			++ret;
		}
		++begin;
	}

	return ret;
}

//int main(){
//	char str1[100], str2[100];
//	cin >> str1;
//	cin >> str2;
//	int ret = TotalNum(str1, str2);
//	cout << ret;
//	return 0;
//}