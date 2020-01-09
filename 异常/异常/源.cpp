#include <iostream>
#include <string>
using namespace std;

void fun(int a)throw(string){//抛出 string 类型的异常(可写多个类型,自定义类型)
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
		//先释放资源再重新抛出异常
		//重新抛出异常
		throw;
	}
	return 0;
}

