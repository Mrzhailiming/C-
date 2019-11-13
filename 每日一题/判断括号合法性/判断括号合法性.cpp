#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;


bool fun(string A, int n){
	//char* str = new char[n + 1];
	//strcpy(str, A.c_str());
	stack<char> s;
	if (n == 0){
		return true;
	}
	if (n == 1){
		return false;
	}
	auto str = A.begin();
	if (*str == '('){
		s.push(*str);
	}
	else{
		return false;
	}
	++str;
	while (--n){
		if (*str == ')'){
			s.pop();
		}
		else if (*str == '('){
			s.push(*str);
		}
		else if (*str != '\0'){
			return  false;
		}
		if (*str != '\0')
			++str;
	}
	//delete str;
	return true;
}

int main () {
	//char* str = "(((((()";
	string A("()()()()");
	for (auto& it : A){
		cout << it;
	}
	cout << fun(A, 0);
	return 0;
}