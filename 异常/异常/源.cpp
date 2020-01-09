#include <iostream>
#include <string>
using namespace std;

void fun(int a){
	if (a == 0){
		//抛出异常
		throw string("wwwwww");//string为抛出异常的类型
	}
}
int main () {
	int a;
	cin >> a;
	//捕获异常
	try{
		fun(a);
	}
	//处理异常
	catch (string& str){//捕获异常的类型
		cout << str << endl;
	}
	catch (...){
		//重新抛出
		throw;
	}
	return 0;
}

