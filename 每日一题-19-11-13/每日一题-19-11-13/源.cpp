#include <iostream>
#include <string.h>
using namespace std;

//判断是不是长度排序
int isLen(char str[4][4], int n){
	//保存每个字符串的长度
	int arr[101] = { 0 };
	//循环遍历所有字符串
	int i = 0;
	while (n--){
		//先判断前两个字符串是否按长度排序
		if (i >= 2){
			//如果前两个字符串不符合长度排序, 返回 0
			if (arr[i - 1] < arr[i - 2]){
				return 0;
			}
		}
		//求出当前字符串的长度
		int count = 0;
		int j = 0;
		while (str[i][j] != '\0'){
			++j;
			++count;
		}
		//for(auto& ch : str[i]){
		//    ++count;
		//}
		//保存每一个字符串的长度
		arr[i] = count;
		++i;
	}
	if (arr[i - 1] < arr[i - 2]){
		return 0;
	}
	else
		return 1;
}

//判断是不是按字典序排序
int isLex(char str[4][4], int n){
	int i = 0;
	//遍历每一位
	for (i = 0; i < n; ++i){
		int j = 0;
		//遍历每一个字符串
		for (j = 0; j < n - 1; ++j){
			//两个字符串的字符不为'\0'
			if (str[j][i] != '\0' && str[j + 1][i] != '\0'){
				if (str[j][i] > str[j + 1][i]){
					return 0;
				}
			}
		}
	}
	return 1;
}


int Both(char str[4][4], int n){
	int len = 0;
	int lex = 0;
	len = isLen(str, n);
	lex = isLex(str, n);
	if (len == 1 && lex == 1){
		return 2;
	}
	else if (len == 1 && lex == 0){
		return 1;
	}
	else if (len == 0 && lex == 1){
		return 0;
	}
	return -1;
}


int main(){
	char str[4][4] = { 0 };
	int n = 3;
	int i = 0;
	int ret = 0;
	int in = n;
	while (in--){
		cin >> str[i];
		++i;
	}
	ret = Both(str, n);
	if (ret == 2){
		cout << "both";
		return 0;
	}
	else if (ret == 1){
		cout << "lengths";
		return 0;
	}
	else if (ret == 0){
		cout << "lexicographically";
		return 0;
	}
	cout << "none";
	return 0;
}