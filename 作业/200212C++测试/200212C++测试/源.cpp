#include <iostream>
#include <string>
using namespace std;


//void deleChar(string str1, string str2){
//	int len2 = str2.size();
//	int i = 0;
//	string ret = str1;
//	while (len2--){
//		string tmp = "";
//		char c = str2[i];
//		int j = 0;
//		int len1 = ret.size();
//		while (j < len1){
//			if (ret[j] != c){
//				tmp += ret[j];
//			}
//			++j;
//		}
//		++i;
//		ret = tmp;
//	}
//	cout << ret << endl;
//
//
//}
//
//int main(){
//	string str1 = "";
//	string str2 = "";
//	cin >> str1;
//	cin >> str2;
//	deleChar(str1, str2);
//	return 0;
//}


int ret(int a, int b, char c){
	if (c == '+'){
		return a + b;
	}
	else if (c == '-'){
		return a - b;
	}
	else if (c == '*'){
		return a * b;
	}
	else{
		return a / b;
	}
}


void test(int a, int b, int c, int d){
	char s[4] = { '+', '-', '*', '/' };
	int tmp = 0;
	int i = 0;
	for (i = 0; i < 4; ++i){
		tmp = ret(a, b, s[i]);
		int j = 0;
		for (j = 0; i < 4; ++j){
			tmp = ret(tmp, c, s[j]);
			int x = 0;
			for (x = 0; x < 4; ++x){
				tmp = ret(tmp, d, s[x]);
				if (tmp == 24){
					cout << "true" << endl;
					return;
				}
			}
		}
	}
	cout << "false" << endl;
}


int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	test(a, b, c, d);
	return 0;
}