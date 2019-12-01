//#include <iostream>
//using namespace std;
//
//
//void printfStr(char* str){
//	int ret[300] = { 0 };
//	char pri[100] = { 0 };
//	//遍历str,统计各个字母出现的次数
//	for (int i = 0; i <= 100; ++i){
//		ret[str[i]]++;
//	}
//	//再次遍历str, 在ret中数字为1则放进输出的数组,并置位0;下次遇到不为0,则不方
//	int index = 0;
//	for (int j = 0; j <= 100; ++j){
//		if (ret[str[j]] >= 1){
//			pri[index++] = str[j];
//			ret[str[j]] = 0;
//		}
//	}
//	pri[index] = '\0';
//	cout << pri << endl;
//}
//int main(){
//	char str[101] = "";
//	cin >> str;
//	printfStr(str);
//	return 0;
//}
//789123456






//#include <iostream>
//#include <string.h>
//using namespace std;
//
//
//int maxDiv(int a, int b){
//	int ret = 0;
//	int max = a > b ? a : b;
//	int min = a > b ? b : a;
//	while (max % min != 0){
//		ret = max % min;
//		max = min;
//		min = ret;
//	}
//	return min;
//}
//
//int begin(int now, int n, int* pow){
//	int i = 0;
//	int ret = now;
//	while (n--){
//		if (pow[i] <= ret){
//			ret += pow[i];
//		}
//		else{
//			int maxdiv = maxDiv(pow[i], ret);
//			ret += maxdiv;
//		}
//		++i;
//	}
//	return ret;
//}
//
//
//
//
//
//int main(){
//	int now, num, fin;
//	int* pow = new int[100000];
//	memset(pow, 0, 100000);
//	while (cin >> num >> now){
//		int i = 0;
//		int n = num;
//		while (n--){
//			cin >> pow[i++];
//		}
//
//		fin = begin(now, num, pow);
//		cout << fin << endl;
//	}
//
//	return 0;
//}


#include <iostream>
using namespace std;


void pri(char* str){
	int arr[128] = { 0 };
	char* s = str;
	while (*s != '\0'){
		arr[*s]++;
		++s;
	}
	int i = 0;
	s = str;
	for (i = 0; i < 128; ++i){
		if (arr[*s] == 1){
			cout << *s << endl;
			return;
		}
		++s;
	}
	cout << -1 << endl;
}

int main(){
	char str[128] = "";
	cin >> str;

	pri(str);




	return 0;
}























